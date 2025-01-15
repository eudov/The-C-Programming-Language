#include <stdio.h>
#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)         \
    ((byte) & 0x80 ? '1' : '0'),     \
        ((byte) & 0x40 ? '1' : '0'), \
        ((byte) & 0x20 ? '1' : '0'), \
        ((byte) & 0x10 ? '1' : '0'), \
        ((byte) & 0x08 ? '1' : '0'), \
        ((byte) & 0x04 ? '1' : '0'), \
        ((byte) & 0x02 ? '1' : '0'), \
        ((byte) & 0x01 ? '1' : '0')

int bits;
unsigned int input;

unsigned int bitcount(unsigned x);
unsigned int bitcount2(unsigned x);

int main(void)
{
    input = 47;
    bits = bitcount2(input);

    printf("input = %d or binary: " BYTE_TO_BINARY_PATTERN, input, BYTE_TO_BINARY(input));
    printf("\nbits = %d\n", bits);

    return 0;
}

unsigned int bitcount(unsigned x)
{
    int b;

    for (b = 0; x != 0; x >>= 1)
    {
        if (x & 01)
            b++;
    }
    return b;
}

unsigned int bitcount2(unsigned x)
{
    int b;
    // this works because x-1 either flips the rightmost bit to 0 on an odd number, or flips all bits below a power of 2 to 1 (on)
    for (b = 0; x != 0; x &= (x - 1))
    {
        b++;
        printf("x (%d) = " BYTE_TO_BINARY_PATTERN, x, BYTE_TO_BINARY(x));
        printf("\n b = %d\n", b);
    }
    return b;
}