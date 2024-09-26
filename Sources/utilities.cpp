#include "utilities.h"
#include "library.h"

int StackCtor(struct Stack_t* stk, int amount)
{
    assert( stk );
    assert( isfinite(amount) );

    stk->data = (StackElem* )calloc( (size_t)amount, sizeof(StackElem) );
    stk->size = (int)0;
    stk->capacity = amount;

    // printf("%lf %d %d\n", stk->data + stk->size, stk->size, stk->capacity);

    return 0;
}


int StackDtor(struct Stack_t* stk)
{
    assert( stk );
    assert( isfinite(stk->size) );

    stk->size = 0;
    stk->capacity = 0;

    free( stk->data );

    return 0;
}


int StackPush(struct Stack_t* stk, StackElem elem)
{
    printf("Hello 4\n");

    *( (stk->data) + (stk->size) ) = elem;

    printf("Hello 5\n");
    (stk->size)++;
    return 0;
}


StackElem StackPop(struct Stack_t* stk)
{
    return *( (stk->data) + (stk->size)-- );
}


