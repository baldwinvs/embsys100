#include <assert.h>

extern int swapCharsAsm(char* x, char* y);

int main()
{
    //#########################################################
    // TEST: DIFFERENT CHARACTERS
    // EXPECT: The return of swapCharsAsm() to be 1, x equals
    //         the original value of y and vice versa.
    //#########################################################
    {
        char x = 'A';
        char y = 'B';

        assert('A' == x);
        assert('B' == y);

        assert(1 == swapCharsAsm(&x, &y));

        assert('A' == y);
        assert('B' == x);
    }

    //#########################################################
    // TEST: SAME CHARACTERS
    // EXPECT: The return of swapCharsAsm() to be 0, x and y
    //         are the same before and after the function call.
    //#########################################################
    {
        char x = 'A';
        char y = 'A';

        assert(x == y);

        assert(0 == swapCharsAsm(&x, &y));

        assert(x == y);
    }
    return 0;
}
