#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

#ifndef SHIT_HEADER
#define SHIT_HEADER

typedef double StackElem;

struct Stack_t
    {
        StackElem* data;
        int size;
        int capacity;
    };

const int SIZE = 50;

#endif
