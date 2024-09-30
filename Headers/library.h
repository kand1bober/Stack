#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include <stdint.h>

#include "macros.h"
#include "configuration.h"

#ifndef SHIT_HEADER
#define SHIT_HEADER

typedef int StackElem;

struct Stack_t
    {
        StackElem* data;
        int size;
        int capacity;
        ON_DEBUG(int error;)
        // ON_DEBUG(uint32_t hash)
    };

const int error_code_1 = 2; //invalid ptr to array
const int error_code_2 = 4; //underflow
const int error_code_3 = 8; //overflow
const int error_code_4 = 16; //left canareyka
const int error_code_5 = 32; //right canareyka
const int error_code_6 = 64; //hash sum changed
const int error_code_7 = 128;

const int SIZE = 50;

#ifdef DEBUG_STACK_FUNCS

const int LEFT_CANAREYKA = 0xBADDED; // =12246509
const int RIGHT_CANAREYKA = 0xBADF00D; // =195948557
const int POISON = -666;
#endif

#endif
