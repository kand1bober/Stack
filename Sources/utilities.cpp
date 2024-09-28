#include <configuration.h>

#include "utilities.h"
#include "macros.h"
#include "library.h"

int STACK_CTOR(struct Stack_t* stk, int amount)
{
    assert( stk );
    assert( isfinite(amount) );

    stk->data = (StackElem* )calloc( (size_t)amount, sizeof(StackElem) );
    stk->size = (int)0;
    stk->capacity = amount;

    // printf("file: %s \nfunc: %s \nline: %d\n", file, func, line);

    // printf("%lf %d %d\n", stk->data + stk->size, stk->size, stk->capacity);

    return 0;
}


int STACK_DTOR(struct Stack_t* stk)
{
    assert( stk );
    assert( isfinite(stk->size) );

    stk->size = 0;
    stk->capacity = 0;

    free( stk->data );

    return 0;
}


int STACK_PUSH(struct Stack_t* stk, StackElem elem)
{
    *( (stk->data) + (stk->size) ) = elem;

    (stk->size)++;

    printf("file: %s \nfunc: %s \nline: %d\n", file, func, line);

    return 0;
}


StackElem STACK_POP(struct Stack_t* stk)
{
    return *( (stk->data) + (stk->size)-- );
}


// int StackValidity(struct Stack_t* stk)
// {
//     assert( stk );
//     ASSERT( ( (stk->size) >= 0 ) && ( (stk->size) <= capacity) );
// }

// int Assert()
// {
//
// }

