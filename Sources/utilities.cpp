#include "utilities.h"
#include "library.h"

void StackCtor(struct Stack_t* ptr, int amount)
{
    assert(ptr);
    assert( isfinite(amount) );

    ptr->data = (StackElem* )calloc( (size_t)amount, sizeof(StackElem) );
    ptr->size = (int)0;
    ptr->capacity = amount;


    printf("%p %d %d\n", ptr->data, ptr->size, ptr->capacity);
}

void StackPush(struct Stack_t* ptr, StackElem elem)
{
    *( (ptr->data + ptr->size) ) = elem;
    (ptr->size)++;
}
