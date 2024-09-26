#include "library.h"
#include "utilities.h"

int main()
{


    struct Stack_t stopka = {0};

    StackCtor(&stopka, 101);

    for (int i = 0; i < 50; i++)
    {
        StackPush(&stopka, i);
    }

    for (int g = 0; g < 50; g++)
    {
        printf("%.0lf %d %d\n", *(stopka.data + g), stopka.size, stopka.capacity);
    }

    free(stopka.data );
    return 0;
}
