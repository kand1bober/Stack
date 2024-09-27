#include "library.h"

#ifndef UTILITIES_HEADER
#define UTILITIES_HEADER

int StackCtor(struct Stack_t* stk, int amount);
int StackDtor(struct Stack_t* stk);
int StackPush(struct Stack_t* stk, StackElem elem);
StackElem StackPop(struct Stack_t* stk);
int StackValidity(struct Stack_t* stk, StackElem elem_to_check);

#endif
