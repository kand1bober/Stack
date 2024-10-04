#include <configuration.h>

#include "library.h"
#include "functions.h"
#include "macros.h"


int main()
{
    struct Stack_t stopka = {0};


    STACK_CTOR_CALL(&stopka, 10);


    for (int i = 0; i < 30 ; i++)
    {
        STACK_PUSH_CALL(&stopka, (StackElem)i);
    }


    for (int i = 0; i < 30; i++)
    {
        printf("output from stack number %d : %d\n", i, STACK_POP_CALL(&stopka));
    }

    #ifdef DEBUG_STACK_FUNCS
        printf("Left canareyka: %X\nRight: %X\n", *(stopka.data - 1), *(stopka.data + stopka.capacity) );
    #endif

    STACK_DTOR_CALL(&stopka);

    return 0;
}
