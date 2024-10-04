#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include <stdint.h>

#include "macros.h"
#include "configuration.h"

#ifndef SHIT_HEADER

#define SHIT_HEADER

int printf(const char *, ...) __attribute__((format(printf, 1, 2)));

typedef int StackElem;
typedef uint64_t Canary_t;

#ifdef DEBUG_STACK_FUNCS
    const int LEFT_CANAREYKA = 0xBADDED; // =12246509
    const int RIGHT_CANAREYKA = 0xBADF00D; // =195948557
    const StackElem POISON = -666;

    enum StackError
    {
        STACK_NULLPTR = 0,
        DATA_NULL = 1,
        STACK_UNDERFLOW = 2,
        STACK_OVERFLOW = 3,     // = (1 << i), i=1,2,3...
        LEFT_CANARY = 4,
        RIGHT_CANARY = 5,
        HASH_SUM = 6,
    };
#endif

struct Stack_t
    {
        Canary_t first_canary = 0xCAFEBABE; // =3405691582

        StackElem* data;
        int size;
        int capacity;

        ON_DEBUG(uint16_t error;)
        ON_DEBUG(uint64_t hash_1;)
        ON_DEBUG(uint64_t hash_2;)

        Canary_t second_canary = 0xDEADFA11; // =3735943697
    };

#endif
