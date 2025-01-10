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

unsigned int setbits(unsigned int a, unsigned int p, unsigned int n, unsigned int b);

int invert(int x, int p, int n);

int rightrot(int x, int n);

int main()
{

    // Note that position is zero indexed from the right - so the rightmost bit is index [0]
    // but bits (n) are NOT zero indexed...

    // expected out 00001111
    setbits(9, 2, 2, 3);

    // 00001010 and 00000101 = 01011010
    setbits(10, 7, 4, 5);

    // 10001111 and 00000111 = 11111111
    setbits(143, 6, 3, 7);

    // 00011010 and 00010101 = 01011010
    setbits(26, 7, 4, 21);

    // 10001111 and 00000111 = 11111111
    // setbits(143, 6, 3, 7);

    return 0;
}

unsigned int setbits(unsigned int a, unsigned int p, unsigned int n, unsigned int b)
{
    /*
    a = 00001001
    b = 00000011
    output should = 00001111

    clear bits up to p
    temp1 = 11111000 (~0 << p+1)

    set bits up to p-n
    temp2 = 00000001 (~0 >> (8-(p-n+1)))

    mask = temp1 & temp2; should be 11111001

    set n bits and move them for mask
    temp3 = 00000011(~0 >> (8-n))
    temp4 = 00000110(temp3 << p-1)

    b2 = b & temp3; // right n bits
    b2 << p+1; // move to p


    clear the bits in a
    a & mask;
    b & ~mask;
    a & b;

    b & ~(~0 << n)
    b should be 00000011

    */

    unsigned int o, o_masked, temp1, temp2, mask, antimask, rbits, placed_rbits;

    printf("~~~ BITWISE OPERATIONS FOR ~~~ %i ~~~ and ~~~ %i ~~~\n", a, b);

    printf("a = " BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(a));
    printf("\n");

    printf("b = " BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(b));
    printf("\n");

    rbits = b & (~(~0 << n));

    printf("rbits = " BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(rbits));
    printf("\n");

    temp1 = (~0 << p + 1);
    printf("temp1 = " BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(temp1));
    printf("\n");

    temp2 = ~temp1 >> n;
    printf("temp2 = " BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(temp2));
    printf("\n");

    mask = (temp1 | temp2);
    printf("mask = " BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(mask));
    printf("\n");

    antimask = ~mask;
    printf("antimask = " BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(antimask));
    printf("\n");

    placed_rbits = ((rbits << (p - n + 1))) & antimask;
    printf("placed_rbits = " BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(placed_rbits));
    printf("\n");

    printf("a is currently = " BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(a));
    printf("\n");

    o_masked = (a & mask);
    printf("o_masked = " BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(o_masked));
    printf("\n");

    o = o_masked + placed_rbits;
    printf("o = " BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(o));
    printf("\n");

    return o;
}