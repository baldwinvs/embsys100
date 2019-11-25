#include <assert.h>

extern void swapPointersAsm(int** x, int** y);

int main()
{
    int x = 5;
    int y = 8;
    int* xPtr = &x;
    int* yPtr = &y;

    assert(*xPtr == x);
    assert(*yPtr == y);

    swapPointersAsm(&xPtr, &yPtr);

    assert(*xPtr == y);
    assert(*yPtr == x);

    return 0;
}
