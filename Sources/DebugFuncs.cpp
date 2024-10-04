#include "configuration.h"
#include "decoration.h"

#include "functions.h"
#include "macros.h"
#include "library.h"

#ifdef DEBUG_STACK_FUNCS

    bool StackValidity(struct Stack_t* stk, const char* file, const char* func, const int line)
    {
        bool status = 0;

        if ( stk == NULL )
        {
            stk->error |= STACK_NULLPTR;
        }
        if (stk->data == NULL)
        {
            // printf("uslovie 1\n");
            stk->error |= DATA_NULL;
            status = 1;
        }
        if ( stk->size < 0 )
        {
            // printf("uslovie 2\n");
            stk->error |= STACK_UNDERFLOW;
            status = 1;
        }
        if ( stk->size > stk->capacity )
        {
            // printf("uslovie 3\n");
            stk->error |= STACK_OVERFLOW    ;
            status = 1;
        }
        if ( *(stk->data - (StackElem)1 ) != LEFT_CANAREYKA )
        {
            // printf("uslovie 4\n");
            stk->error |= LEFT_CANARY;
            status = 1;
        }
        if ( *(stk->data + stk->capacity) != RIGHT_CANAREYKA )
        {
            // printf("uslovie 5\n");
            stk->error = stk->error | RIGHT_CANARY;
            status = 1;
        }
        if ( stk->hash_1 != stk->hash_2 )
        {
            stk->error |= HASH_SUM;
        }

        if (status)
            return status;
        else
        {
            return 0;
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


void BinaryOutput(uint16_t number)
{
    int l = 8 *  sizeof(number);
    for (int i = l; i >= 0; i--)
    {
        printf("%x", ((number & ((uint16_t)1 << i)) >> i) );
    }
}


// int HashSUm()
// {
//
// }


size_t GetCanarySize()
{
    #ifdef DEBUG_STACK_FUNCS
        return sizeof(Canary_t);
    #endif

    return 0;
}

#endif



// int InputValidity(StackElem elem, const char* file, const char* func, const int line)
// {
//
//     if()
//         return 0;
// }



