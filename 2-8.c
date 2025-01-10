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

unsigned int rightrot(unsigned int x, unsigned int n);

unsigned int leftrot(unsigned int x, unsigned int n);

int main()
{
    unsigned int x = 39;
    printf("x = " BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(x));
    printf("\n");

    leftrot(x, 21);
    return 0;
}

unsigned int rightrot(unsigned int x, unsigned int n)
{
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (x & 1)
        {
            // printf("setflag\n");
            flag = 1;
        }
        x /= 2;
        if (flag == 1)
        {
            x += 128;
            flag = 0;
        }
        printf("%d/%d x = ", i, n);
        printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(x));
        printf("\n");
    }
    return x;
}

unsigned int leftrot(unsigned int x, unsigned int n)
{
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (x & 128)
        {
            // printf("setflag\n");
            flag = 1;
        }
        x *= 2;
        if (flag == 1)
        {
            x += 1;
            flag = 0;
        }
        printf("%d/%d x = ", i, n);
        printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(x));
        printf("\n");
    }
    return x;
}