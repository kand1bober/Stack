#include <configuration.h>

#include "functions.h"
#include "macros.h"
#include "library.h"

int STACK_CTOR(struct Stack_t* stk, int amount)
{
    // (stk->data) = ( (StackElem* )calloc( (size_t)(amount ON_DEBUG(+ 2)), sizeof(StackElem))  ON_DEBUG(+ (StackElem)1 ) ); //added canareyka before data

    size_t kolvo = amount * sizeof(StackElem) ON_DEBUG(+ 2 * sizeof(Canary_t)) ON_DEBUG(+ 8 - (amount * sizeof(StackElem)) % 8 );
    printf("kolvo in bytes: %ld\n", kolvo);

    #ifdef DEBUG_STACK_FUNCS
        stk->capacity_gap = ( 8 - (amount * sizeof(StackElem)) % 8 );
    #endif

    (stk->data) = (StackElem*)( (char*)calloc(kolvo, sizeof(char)) ON_DEBUG(+ sizeof(Canary_t) ) );


    stk->size = 0;
    stk->capacity = amount;

    printf("Ctor: amount: %d, stk->data - sizeof(Cnary_t): %p, kolvo: %ld, stk->data + kolvo - sizeof(canary): %p \n", amount, (char*)stk->data ON_DEBUG(- sizeof(Canary_t) ), kolvo, (char*)stk->data + kolvo ON_DEBUG(- sizeof(Canary_t) ) );

    #ifdef DEBUG_STACK_FUNCS
        *(Canary_t *)( (char*)stk->data - sizeof(Canary_t) ) = LEFT_CANAREYKA; //creating canareyka's
        *(Canary_t*)( (char*)stk->data + kolvo - 2 * sizeof(Canary_t) ) = RIGHT_CANAREYKA;
    #endif

    CHECK_VALIDITY(stk);

    return 0;
}


int STACK_DTOR(struct Stack_t* stk)
{
    CHECK_VALIDITY(stk);

    stk->size = 0;
    stk->capacity = 0;

    free ( (StackElem*)( (char*)stk->data ON_DEBUG(- sizeof(Canary_t) ) ) );

    return 0;
}


int STACK_PUSH(struct Stack_t* stk, StackElem elem)
{
    CHECK_VALIDITY(stk);

    STACK_RESIZE_UP_CALL( stk );

    *( (stk->data) + (stk->size) ) = elem;
    (stk->size)++;

    CHECK_VALIDITY(stk);

    return 0;
}


StackElem STACK_POP(struct Stack_t* stk)
{
    CHECK_VALIDITY(stk);

    STACK_RESIZE_DOWN_CALL( stk );

    CHECK_VALIDITY(stk);

    return *( (stk->data ) + ((stk->size)--) - 1);
}

int STACK_RESIZE_UP(struct Stack_t* stk)
{
    CHECK_VALIDITY(stk);

    if ( stk->size >= ( stk->capacity - 1) )
    {
        // stk->data = ( (StackElem* )realloc( (void*)(stk->data ON_DEBUG(- (StackElem)1) ), (size_t)( ( stk->capacity * 2 ) ON_DEBUG(+ 2) ) * sizeof(StackElem) ) ON_DEBUG(+ (StackElem)1) );

        size_t kolvo = ( 2* stk->capacity * sizeof(StackElem) ON_DEBUG(+ 2 * sizeof(Canary_t)) ON_DEBUG(+ 8 - ( 2 * stk->capacity * sizeof(StackElem) ) % 8 ) );

        #ifdef DEBUG_STACK_FUNCS
            stk->capacity_gap = ( 8 - ( 2 * stk->capacity * sizeof(StackElem) ) % 8 );
        #endif

        stk->data = (StackElem*)( (char*)realloc( (void*)( (char*)stk->data ON_DEBUG(- sizeof(Canary_t) ) ), kolvo )  ON_DEBUG(+ sizeof(Canary_t) ) );

        printf("Resize_up: 2 * stk->capacity: %d, (char*)stk->data - sizeof(Canary_t): %p, kolvo: %ld, stk->data + kolvo - sizeof(canary): %p \n", 2*stk->capacity, (char*)stk->data ON_DEBUG(- sizeof(Canary_t) ), kolvo, (char*)stk->data + kolvo ON_DEBUG(- sizeof(Canary_t) ) );


        CHECK_VALIDITY(stk);

        if ( stk )
        {
            stk->capacity = stk->capacity * 2;

            #ifdef DEBUG_STACK_FUNCS
                *(Canary_t *)( (char*)stk->data - sizeof(Canary_t) ) = LEFT_CANAREYKA; //creating canareyka's
                *(Canary_t*)( (char*)stk->data + kolvo - 2 * sizeof(Canary_t) ) = RIGHT_CANAREYKA;

                CHECK_VALIDITY(stk);
            #endif

            CHECK_VALIDITY(stk);

            return 0;
        }
        else
            return 1;
    }
    else
    {
        // printf("didn't rezize up\n");
        return 0;
    }

    return -1;
}


int STACK_RESIZE_DOWN(struct Stack_t* stk)
{
    CHECK_VALIDITY(stk);

    if ( (stk->size <= (stk->capacity / 4))  && (stk->capacity > START_CAPACITY) )
    {
        // stk->data = ( (StackElem* )realloc( (void*)(stk->data ON_DEBUG(- (StackElem)1) ), (size_t)( ( stk->capacity / 2 ) ON_DEBUG(+ 2) ) * sizeof(StackElem) ) ON_DEBUG(+ (StackElem)1) );

        size_t kolvo = ( (( stk->capacity * sizeof(StackElem)) / 2)  ON_DEBUG(+ 2 * sizeof(Canary_t))  ON_DEBUG(+ 8 - (stk->capacity / 2) % 8 ) );
        #ifdef DEBUG_STACK_FUNCS
            stk->capacity_gap = ( 8 - (stk->capacity / 2) % 8 );
        #endif

        stk->data = (StackElem*)( (char*)realloc( (void*)( (char*)stk->data ON_DEBUG(- sizeof(Canary_t) ) ), kolvo) ON_DEBUG(+ sizeof(Canary_t) ) );

        printf("Resize_down: stk->capacity/2: %d, (char*)stk->data - sizeof(Canary_t): %p, kolvo: %ld, stk->data + kolvo - sizeof(canary): %p \n", stk->capacity / 2, (char*)stk->data ON_DEBUG(- sizeof(Canary_t) ), kolvo, (char*)stk->data + kolvo ON_DEBUG(- sizeof(Canary_t) ) );


        if ( stk )
        {
            stk->capacity = stk->capacity / 2;

            #ifdef DEBUG_STACK_FUNCS
                *(Canary_t *)( (char*)stk->data - sizeof(Canary_t) ) = LEFT_CANAREYKA; //creating canareyka's
                *(Canary_t*)( (char*)stk->data + kolvo - 2 * sizeof(Canary_t) ) = RIGHT_CANAREYKA;

                CHECK_VALIDITY(stk);
            #endif

            return 0;
        }
        else
            return 1;
    }
    else
        return 0;

    return -1;
}


