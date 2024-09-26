#include "library.h"
#include "utilities.h"

int main()
{
    struct Stack_t stopka = {0};

    StackCtor(&stopka, 50);

    printf("Hello 1\n");

    for (int i = 0; i < 50; i++)
    {
        printf("Hello 2\n");
        StackPush(&stopka, i);
        printf("Hello 3\n");
    }

    // for (int i = 0; i < 50; i++)
    // {
    //     printf("%.0lf %d %d\n", *(stopka.data + i), stopka.size, stopka.capacity);
    // }

    for (int i = 0; i < 50; i++)
    {
        printf("output from stack number %d : %.0lf\n", i, StackPop(&stopka) );
    }


    // free(stopka.data );
    StackDtor(&stopka);
    return 0;
}
