#include <configuration.h>

#include "utilities.h"
#include "macros.h"
#include "library.h"

int STACK_CTOR(struct Stack_t* stk, int amount)
{
    (stk->data) = ( (StackElem* )calloc( (size_t)(amount ON_DEBUG(+ 2)), sizeof(StackElem))  ON_DEBUG(+ (StackElem)1 ) ); //added canareyka before data

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
    #ifdef DEBUG_STACK_FUNCS
        StackValidity(stk, file, func, line);
    #endif

    stk->size = 0;
    stk->capacity = 0;

    // printf("NASRANO:\n");
    // printf("%d\n", *( (stk->data) - (StackElem)1 ) );

    free( (stk->data) ON_DEBUG(- (StackElem)1 ) );

    return 0;
}


int STACK_PUSH(struct Stack_t* stk, StackElem elem)
{
    #ifdef DEBUG_STACK_FUNCS
        StackValidity(stk, file, func, line);
    #endif

    STACK_RESIZE_UP_CALL( stk );

    *( (stk->data) + (stk->size) ) = elem;
    (stk->size)++;

    return 0;
}


StackElem STACK_POP(struct Stack_t* stk)
{
    #ifdef DEBUG_STACK_FUNCS
        StackValidity(stk, file, func, line);
    #endif

    STACK_RESIZE_DOWN_CALL( stk );

    return *( (stk->data ) + ((stk->size)--) - 1);
}


#ifdef DEBUG_STACK_FUNCS

    int StackValidity(struct Stack_t* stk, const char* file, const char* func, const int line)
    {
        bool status = 0;
        if ( stk == NULL )
        {
            printf("assertion failed: pointer to stack is NULL\n");
            abort();
        }
        else
        {
            if (stk->data == NULL)
            {
                // printf("uslovie 1\n");
                stk->error = stk->error | error_code_1;
                status = 1;
            }
            if ( stk->size < 0 )
            {
                // printf("uslovie 2\n");
                stk->error = stk->error | error_code_2;
                status = 1;
            }
            if ( stk->size > stk->capacity )
            {
                // printf("uslovie 3\n");
                stk->error = stk->error | error_code_3;
                status = 1;
            }
            if ( *(stk->data - (StackElem)1 ) != LEFT_CANAREYKA )
            {
                // printf("uslovie 4\n");
                stk->error = stk->error | error_code_4;
                status = 1;
            }
            if ( *(stk->data + stk->capacity) != RIGHT_CANAREYKA )
            {
                // printf("uslovie 5\n");
                stk->error = stk->error | error_code_5;
                status = 1;
            }

            if (status)
            {
                StackDump(stk, file, func, line);
                return 1;
            }
            else
            {
                return 0;
            }
        }
        return -1;
    }


    void StackDump(struct Stack_t* stk, const char* file, const char* func, const int line)
    {
        printf("stack called from %s in file: %s, line: %d\n"
        "stack:\n"
        "{\n"
        "    StackElem* data: %p\n"
        "    int size: %d\n"
        "    int capacity: %d\n"
        "    ON_DEBUG(int error): ", func, file, line, stk->data, stk->size, stk->capacity);
        BinaryOutput(stk->error);
        printf("\n                         ........|||||||||\n"
        "                                 " WHITE "8" BLACK "7" WHITE "6" PURPLE "5" SINIY "4" BLUE "3" GREEN "2" YELLOW "1" RED "0" DELETE_COLOR "\n"
        RED "0 -- nothing for now\n"
        YELLOW "1 -- invalid pointer to array\n"
        GREEN "2 -- underflow\n"
        BLUE "3 -- overflow\n"
        SINIY "4 -- problem with left canareyka\n"
        PURPLE "5 -- problem with right canareyka\n"
        WHITE "6 -- hash sum changed\n" DELETE_COLOR
        "7 -- nothing for now\n"
        "}\n\n"
        YELLOW "Left Canareyka from constant: %d, " PURPLE "Left Canareyka from stack: %d\n"
        YELLOW "Rigth Canareyka from constant: %d, " PURPLE "Right Canareyka from stack: %d\n\n" DELETE_COLOR
        "Values of data:\n", LEFT_CANAREYKA, *( stk->data - (StackElem)1), RIGHT_CANAREYKA, *( stk->data + stk->capacity) );

        for (int i = 0; i < stk->capacity; i++)
        {
            StackElem output = *(stk->data + (StackElem)i );
            if(output == POISON)
                printf(RED "*[%d] = %d\n" DELETE_COLOR, i, output );
            else
                printf("*[%d] = %d\n", i, output );
        }
        printf("\n");
    }

#endif

void BinaryOutput(uint16_t number)
{
    int l = 8 *  sizeof(number);
    for (int i = l; i >= 0; i--)
    {
        printf("%x", ((number & ((uint16_t)1 << i)) >> i) );
    }
}


// int InputValidity(StackElem elem, const char* file, const char* func, const int line)
// {
//
//     if()
//         return 0;
// }

int STACK_RESIZE_UP(struct Stack_t* stk)
{
    #ifdef DEBUG_STACK_FUNCS
        StackValidity(stk, file, func, line);
    #endif

    // printf(WHITE "size: %d capacity: %d\n" DELETE_COLOR "", stk->size, stk->capacity );

    if ( stk->size >= ( stk->capacity - 1) )
    {
        stk->data = ( (StackElem* )realloc( (void*)(stk->data ON_DEBUG(- (StackElem)1) ), (size_t)( ( stk->capacity * 2 ) ON_DEBUG(+ 2) ) * sizeof(StackElem) ) ON_DEBUG(+ (StackElem)1) );

        #ifdef DEBUG_STACK_FUNCS
            StackValidity(stk, file, func, line);
        #endif

        if ( stk )
        {
            stk->capacity = stk->capacity * 2;

            #ifdef DEBUG_STACK_FUNCS
                *(stk->data - (StackElem)1 ) = LEFT_CANAREYKA;
                *(stk->data + (StackElem)stk->capacity) = RIGHT_CANAREYKA;

                StackValidity(stk, __FILE__, __PRETTY_FUNCTION__, __LINE__);
            #endif

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


