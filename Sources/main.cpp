#include "configuration.h"

#include "library.h"
#include "functions.h"
#include "macros.h"


int main()
{
    struct Stack_t stopka = {};

    STACK_CTOR_CALL(&stopka, START_CAPACITY);

    for (int i = 0; i < 11 ; i++)
    {
        STACK_PUSH_CALL(&stopka, (StackElem)i);
    }


    for (int i = 0; i < 11; i++)
    {
        printf("output from stack number %d : %lf\n", i, STACK_POP_CALL(&stopka));
    }
    STACK_POP_CALL(&stopka);

    // #ifdef DEBUG_STACK_FUNCS
    //     printf("Left canareyka: %lX\nRight: %lX\n", *(Canary_t*)((char*)stopka.data - sizeof(Canary_t) ), *(Canary_t*)( (char*)stopka.data + (size_t)stopka.capacity * sizeof(StackElem) + stopka.capacity_gap) );
    // #endif

    STACK_DTOR_CALL(&stopka);

    return 0;
}
