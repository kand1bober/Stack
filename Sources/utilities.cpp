#include <configuration.h>

#include "utilities.h"
#include "macros.h"
#include "library.h"

int STACK_CTOR(struct Stack_t* stk, int amount)
{
    (stk->data) = ( (StackElem* )calloc( (size_t)(amount ON_DEBUG(+ 2)), sizeof(StackElem))  ON_DEBUG(+ (StackElem)1 ) ); //added canareyka before data

    stk->size = (StackElem)0;
    stk->capacity = amount;

    #ifdef DEBUG_STACK_FUNCS
        *(stk->data - 1) = LEFT_CANAREYKA;
        *(stk->data + stk->capacity) = RIGHT_CANAREYKA;
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

    free( (stk->data) - (StackElem)1 );

    return 0;
}


int STACK_PUSH(struct Stack_t* stk, StackElem elem)
{
    #ifdef DEBUG_STACK_FUNCS
        StackValidity(stk, file, func, line);
    #endif

    *( (stk->data) + (stk->size) ) = elem;
    (stk->size)++;

    return 0;
}


StackElem STACK_POP(struct Stack_t* stk)
{
    #ifdef DEBUG_STACK_FUNCS
        StackValidity(stk, file, func, line);
    #endif

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
        printf("stack called from %s in file: %s, line: %d\n", func, file, line);
        printf("stack:\n");
        printf("{\n");
        printf("size: %d\n", stk->size);
        printf("capacity: %d\n", stk->capacity);
        printf("Left Canareyka from constant: %d, Left Canareyka from stack: %d\n", LEFT_CANAREYKA, *( stk->data - (StackElem)1) );
        printf("Rigth Canareyka from constant: %d, Right Canareyka from stack: %d\n", RIGHT_CANAREYKA, *( stk->data + stk->capacity) );
        printf("data: %p\n", stk->data);
        printf("}\n");
        printf("Values of data:\n");
        for (int i = 0; i < stk->capacity; i++)
        {
            printf("*[%d] = %d\n", i, *(stk->data + (StackElem)i ) );
        }
        printf("\n");
    }

#endif

// int InputValidity(StackElem elem)
// {
//     bool status = 0;
//     ASSERT( isfinite(elem) && isdigit(elem) );
//     if (status)
//     {
//         printf("invalid input");
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }

// int StackResize()
// {
//
//
//     return 0;
// }


