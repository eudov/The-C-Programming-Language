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

unsigned int invert(int x, int p, int n);

int main()
{
    unsigned int test = 23;
    printf("Binary test: " BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(test));
    printf("\n");
    // should return 00000000
    unsigned int o = invert(test, 3, 2);
    printf("Inverted select bits are: " BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(o));

    return 0;
}

unsigned int invert(int x, int p, int n)
{
    unsigned int tmp, tmp3, tmp4, mask, rmask, lmask;

    // invert
    tmp = ((~x >> (p - n + 1)) & ~(~0 << n)) << (p - n + 1);
    // move target bits to right and mask
    // move bits back
    rmask = ~(~0 << (p - n + 1));
    lmask = ~rmask << (n);
    mask = lmask | rmask;
    // use mask to set target placed bits in input to zero
    // add inverted bits back

    printf("tmp = " BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(tmp));
    printf("\n");
    printf("rmask = " BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(rmask));
    printf("\n");
    printf("lmask = " BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(lmask));
    printf("\n");
    printf("mask = " BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(mask));
    printf("\n");

    tmp3 = x & mask;

    printf("tmp3 = " BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(tmp3));
    printf("\n");

    tmp4 = (tmp3 + tmp);
    printf("tmp4 = " BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(tmp4));
    printf("\n");

    return tmp4;
}