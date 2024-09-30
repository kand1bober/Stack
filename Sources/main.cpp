#include <configuration.h>

#include "library.h"
#include "utilities.h"
#include "macros.h"


int main()
{
    struct Stack_t stopka = {0};


    STACK_CTOR_CALL(&stopka, 50);


    for (int i = 0; i < stopka.capacity ; i++)
    {
        STACK_PUSH_CALL(&stopka, (StackElem)i);
    }


    for (int i = 0; i < stopka.capacity; i++)
    {
        printf("output from stack number %d : %d\n", i, STACK_POP_CALL(&stopka));
    }

    // printf("Left canareyka: %X\nRight: %X\n", *(stopka.data - 1), *(stopka.data + stopka.capacity) );


    STACK_DTOR_CALL(&stopka);

    return 0;
}
