#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    printf("Char size is %d\n", CHAR_BIT);
    printf("Char max is %d\n", CHAR_MAX);
    printf("Char min is %d\n", CHAR_MIN);
    printf("Int max is %d\n", INT_MAX);
    printf("Int min is %d\n", INT_MIN);
    printf("Long max is %ld\n", LONG_MAX);
    printf("Long min is %ld\n", LONG_MIN);
    printf("S Char max is %d\n", SCHAR_MAX);
    printf("S Char min is %d\n", SCHAR_MIN);
    printf("Short max is %d\n", SHRT_MAX);
    printf("Short min is %d\n", SHRT_MIN);
    printf("Unsigned char max is %d\n", UCHAR_MAX);
    printf("Unsigned int max is %d\n", UINT_MAX);
    printf("Unsigned long max is %li\n", ULONG_MAX);
    printf("Unsigned short max is %d\n", USHRT_MAX);
}