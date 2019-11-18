#include <assert.h>

#ifndef LITTLE_ENDIAN
#define LITTLE_ENDIAN 1
#endif

/** Determine the endianness of the processor.
 *
 * \returns 1 for little endian
 * \returns 0 for big endian
 */
int determineEndianness()
{
    const int value = 0x89ABCDEF;
    const char* byte = (char*)&value;

    if(*byte == (value & 0xFF)) {
        return 1;
    }
    return 0;
}

int main()
{
#if LITTLE_ENDIAN == 1
    //assert little endian when testing against STM32F401RE and when the simulator is setup for little endian
    assert(1 == determineEndianness());
#else
    //assert big endian when testing against the simulator being setup for big endian
    assert(0 == determineEndianness());
#endif
    return 0;
}
