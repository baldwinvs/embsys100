#include <assert.h>

void swap_pointer(int** p1, int** p2);

int main()
{
    int x = 5;
    int y = 8;
    int* xPtr = &x;
    int* yPtr = &y;

    swap_pointer(&xPtr, &yPtr);

    assert(8 == *xPtr);
    assert(5 == *yPtr);
    return 0;
}

void swap_pointer(int** p1, int** p2)
{
    int* temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}