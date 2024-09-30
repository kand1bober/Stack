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

#define DELETE_COLOR "\u001b[0m"
#define GREEN "\u001b[32;1m"
#define RED "\u001b[31;1m"
#define YELLOW "\u001b[33;1m"
#define PURPLE "\u001b[35;1m"
#define WHITE "\u001b[37;1m"
#define BLUE "\u001b[36;1m"
#define SINIY "\u001b[34;1m"
#define BLACK "\u001b[30m"

typedef int StackElem;

struct Stack_t
    {
        StackElem* data;
        int size;
        int capacity;
        ON_DEBUG(uint16_t error;)
        // ON_DEBUG(uint32_t hash)
    };

#ifdef DEBUG_STACK_FUNCS

const int LEFT_CANAREYKA = 0xBADDED; // =12246509
const int RIGHT_CANAREYKA = 0xBADF00D; // =195948557
const StackElem POISON = -666;

const uint16_t error_code_0 = 1; //
const uint16_t error_code_1 = 2; //invalid ptr to array
const uint16_t error_code_2 = 4; //underflow
const uint16_t error_code_3 = 8; //overflow
const uint16_t error_code_4 = 16; //left canareyka
const uint16_t error_code_5 = 32; //right canareyka
const uint16_t error_code_6 = 64; //hash sum changed
const uint16_t error_code_7 = 128; //

#endif

#endif
