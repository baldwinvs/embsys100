#include "stack.h"

#include <string.h>

#define STACK_SIZE (3)

// The stack implemented using an array.
static int32_t stack[STACK_SIZE];
// Pointer to the top of the stack.
static int32_t* top = 0L;

// Flag to indicate that the stack is full.
static int32_t stackFull = 0;
// Flag to indicate that the stack is empty.
static int32_t stackEmpty = 1;
// Flag to indicate that the stack is almost full;
// the top pointer is in the final position but the
// final element hasn't been filled.
static int32_t stackAlmostFull = 0;

void stackInit(void)
{
    // reset all values in the stack to 0
    memset(stack, 0, sizeof(int32_t) * STACK_SIZE);
    // reset the state of the stack
    stackFull = 0;
    stackEmpty = 1;
    stackAlmostFull = 0;
    // reset the pointer to the top
    top = stack;
}

int32_t stackPush(const int32_t value)
{
    if(stackFull) {
        return 0;
    }
    *top = value;

    // update the empty state flag
    if(stackEmpty) {
        stackEmpty = 0;
    }

    // check if the stack is now full
    if(stackAlmostFull) {
        stackFull = 1;
        stackAlmostFull = 0;
    }
    else {
        ++top;
        // check if the stack is almost full
        if(top - stack == STACK_SIZE - 1) {
            stackAlmostFull = 1;
        }
    }
    return 1;
}

int32_t stackPop(int32_t* value)
{
    if(stackEmpty) {
        return 0;
    }

    // update state flags according to current state
    if(stackFull) {
        *value = *top;
        stackFull = 0;
        stackAlmostFull = 1;
    }
    else if(stackAlmostFull) {
        --top;
        *value = *top;
        --top;
        stackAlmostFull = 0;
    }
    else if(!stackEmpty) {
        if(top == stack) {
            *value = *top;
            stackEmpty = 1;
        }
        else {
            *value = *top;
            --top;
        }
    }

    return 1;
}

int32_t isStackEmpty(void)
{
    if(stackEmpty) {
        return 1;
    }
    return 0;
}

int32_t isStackFull(void)
{
    if(stackFull) {
        return 1;
    }
    return 0;
}