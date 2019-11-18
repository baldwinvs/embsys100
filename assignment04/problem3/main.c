#include "stack.h"

#include <assert.h>

int main()
{
    int32_t testValue = 0;

    //###################################################################
    // TEST CASE #1
    // Test: Pop an empty stack.
    // Expected results: Stack starts empty, input value remains unchanged,
    //      and return value is 0.
    //###################################################################
    stackInit();
    testValue = -1;

    assert(1 == isStackEmpty());
    assert(0 == stackPop(&testValue));
    assert(-1 == testValue);

    //###################################################################
    // TEST CASE #2
    // Test: Push a value to a full stack.
    // Expected results: stack starts empty, after 3 pushes then
    //      isStackFull() will return 1;
    //###################################################################
    stackInit();

    assert(1 == isStackEmpty());
    assert(1 == stackPush(2));
    assert(0 == isStackFull());
    assert(1 == stackPush(4));
    assert(0 == isStackFull());
    assert(1 == stackPush(8));
    assert(1 == isStackFull());
    assert(0 == stackPush(16));

    //###################################################################
    // TEST CASE #3
    // Test: Fill the stack and pop all values from the stack.
    // Expected results: Stack starts empty, after 3 pushes the stack will
    //      be full, after 3 pops the stack will be empty.
    //###################################################################
    stackInit();

    assert(1 == isStackEmpty());
    assert(1 == stackPush(2));
    assert(0 == isStackFull());
    assert(1 == stackPush(4));
    assert(0 == isStackFull());
    assert(1 == stackPush(8));
    assert(1 == isStackFull());
    assert(1 == stackPop(&testValue));
    assert(8 == testValue);
    assert(1 == stackPop(&testValue));
    assert(4 == testValue);
    assert(1 == stackPop(&testValue));
    assert(2 == testValue);
    assert(1 == isStackEmpty());

    //###################################################################
    // TEST CASE #4
    // Test: Fill the stack, pop the top element, check that the stack
    //      is not full, push one more value, check that the stack is full.
    // Expected results: Stack starts empty, after 3 pushes the stack will
    //      be full, the value popped will be the last value pushed, the
    //      stack won't be full until one more push.
    //###################################################################
    stackInit();

    assert(1 == isStackEmpty());
    assert(1 == stackPush(2));
    assert(0 == isStackFull());
    assert(1 == stackPush(4));
    assert(0 == isStackFull());
    assert(1 == stackPush(8));
    assert(1 == isStackFull());
    assert(1 == stackPop(&testValue));
    assert(8 == testValue);
    assert(0 == isStackFull());
    assert(1 == stackPush(16));
    assert(1 == isStackFull());

    //###################################################################
    // TEST CASE #5
    // Test: Fill the stack, empty the stack, fill the stack, empty the
    //      stack.
    // Expected results: Stack starts empty, after 3 pushes the stack will
    //      be full, after 3 pops the stack will be empty, after 3 pushes
    //      the stack will be full, after 3 pops the stack will be empty.
    //###################################################################
    stackInit();

    assert(1 == isStackEmpty());
    assert(1 == stackPush(2));
    assert(0 == isStackFull());
    assert(1 == stackPush(4));
    assert(0 == isStackFull());
    assert(1 == stackPush(8));
    assert(1 == isStackFull());
    assert(1 == stackPop(&testValue));
    assert(8 == testValue);
    assert(1 == stackPop(&testValue));
    assert(4 == testValue);
    assert(1 == stackPop(&testValue));
    assert(2 == testValue);
    assert(1 == isStackEmpty());
    assert(1 == stackPush(4));
    assert(0 == isStackFull());
    assert(1 == stackPush(16));
    assert(0 == isStackFull());
    assert(1 == stackPush(64));
    assert(1 == isStackFull());
    assert(1 == stackPop(&testValue));
    assert(64 == testValue);
    assert(1 == stackPop(&testValue));
    assert(16 == testValue);
    assert(1 == stackPop(&testValue));
    assert(4 == testValue);
    assert(1 == isStackEmpty());

    return 0;
}
