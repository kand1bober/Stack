#include <stdio.h>

int main()
{
    char n = 148;

    int l = sizeof(n) * 8;
    for (int i = l - 1 ; i >= 0; i--)
    {
        printf("%x", (n & (1 << i)) >> i);
    }
    printf("\n");

    printf("%x\n", n);

    return 0;
}




