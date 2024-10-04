#include <configuration.h>

#include "functions.h"
#include "macros.h"
#include "library.h"

int STACK_CTOR(struct Stack_t* stk, int amount)
{
    (stk->data) = ( (StackElem* )calloc( (size_t)(amount ON_DEBUG(+ 2)), sizeof(StackElem))  ON_DEBUG(+ (StackElem)1 ) ); //added canareyka before data

//     size_t size = amount * sizeof(StackElem) + 2 * GetCanarySize();
//     stk-data = (StackElem* )calloc(size + (8 - size % 8), sizeof(char));
//
//     stk-data = (StackElem* )((char*)stk-data + sizeof(Canary_t));

    stk->size = 0;
    stk->capacity = amount;

    #ifdef DEBUG_STACK_FUNCS
        *(stk->data - (StackElem)1 ) = LEFT_CANAREYKA; //creating canareyka's
        *(stk->data + (StackElem)stk->capacity ) = RIGHT_CANAREYKA;
    #endif

    #ifdef DEBUG_STACK_FUNCS
        StackValidity(stk, file, func, line);
    #endif

    return 0;
}


int STACK_DTOR(struct Stack_t* stk)
{
    CHECK_VALIDITY(stk);

    stk->size = 0;
    stk->capacity = 0;

    free( (stk->data) ON_DEBUG(- (StackElem)1 ) );

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
        stk->data = ( (StackElem* )realloc( (void*)(stk->data ON_DEBUG(- (StackElem)1) ), (size_t)( ( stk->capacity * 2 ) ON_DEBUG(+ 2) ) * sizeof(StackElem) ) ON_DEBUG(+ (StackElem)1) );

        CHECK_VALIDITY(stk);

        if ( stk )
        {
            stk->capacity = stk->capacity * 2;

            #ifdef DEBUG_STACK_FUNCS
                *(stk->data - (StackElem)1 ) = LEFT_CANAREYKA;
                *(stk->data + (StackElem)stk->capacity) = RIGHT_CANAREYKA;

                StackValidity(stk, __FILE__, __PRETTY_FUNCTION__, __LINE__);
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
    #ifdef DEBUG_STACK_FUNCS
        StackValidity(stk, file, func, line);
    #endif

    if ( stk->size <= (stk->capacity / (int)4) )
    {
        stk->data = ( (StackElem* )realloc( (void*)(stk->data ON_DEBUG(- (StackElem)1) ), (size_t)( ( stk->capacity / 2 ) ON_DEBUG(+ 2) ) * sizeof(StackElem) ) ON_DEBUG(+ (StackElem)1) );
        if ( stk )
        {
            stk->capacity = stk->capacity / (int)2;

            #ifdef DEBUG_STACK_FUNCS
                *(stk->data - (StackElem)1 ) = LEFT_CANAREYKA;
                *(stk->data + (StackElem)stk->capacity) = RIGHT_CANAREYKA;

                StackValidity(stk, file, func, line);
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


