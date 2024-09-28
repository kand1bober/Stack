#include <configuration.h>

#include "library.h"
#include "utilities.h"
#include "macros.h"


int main()
{
    struct Stack_t stopka = {0};

    // StackAssert(&stopka);

    STACK_CTOR_CALL(&stopka, 50);

    // StackAssert(&stopka);


    for (int i = 0; i < 50; i++)
    {
        STACK_PUSH_CALL(&stopka, i);
    }

    // StackAssert(&stopka);

    for (int i = 0; i < 50; i++)
    {
        printf("output from stack number %d : %.0lf\n", i, STACK_POP_CALL(&stopka));
    }

    // StackAssert(&stopka);

    // free(stopka.data );
    STACK_DTOR_CALL(&stopka);
    return 0;
}
