#include "library.h"
#include "utilities.h"

#define ASSERTION

int main()
{
    struct Stack_t stopka = {0};

    StackAssert(&stopka);

    StackCtor(&stopka, 50);

    StackAssert(&stopka);


    for (int i = 0; i < 50; i++)
    {
        StackPush(&stopka, i);
    }

    StackAssert(&stopka);

    for (int i = 0; i < 50; i++)
    {
        printf("output from stack number %d : %.0lf\n", i, StackPop(&stopka) );
    }

    StackAssert(&stopka);

    // free(stopka.data );
    StackDtor(&stopka);
    return 0;
}
