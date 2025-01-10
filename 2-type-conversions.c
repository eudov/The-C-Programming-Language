#include <stdio.h>
#define HEX 0x1A
#define HEX_LEN 6

char hex[] = "0001AF";

int htoi(char hex[]);

int main()
{
    int result;
    result = htoi(hex);
    printf("result is %d\n", result);
    return 0;
}

int htoi(char hex[])
{
    int c, i, digit, sum;

    i = digit = sum = 0;
    for (i = 0; i < HEX_LEN; ++i)
    {
        c = (hex[HEX_LEN - i]);
        printf("%c\n", c);
        // check if c is 0-9 or A-F / a-f
        if (c >= '0' && c <= '9')
        {
            printf("c is a digit\n");
            digit = c - '0';
        }
        else if (c >= 'A' && c <= 'F')
        {
            printf("c is uppercase A-F\n");
            digit = (c - 'A' + 10);
            printf("elif upper digit = %d\n", digit);
        }
        else if (c >= 'a' && c <= 'f')
        {
            printf("c is lowercase a-f\n");
            digit = (c - 'a' + 10);
        }
        else
        {
            printf("ERROR - UNKOWN INPUT\n");
        }
        // if i > 0 multiply by (16*i)
        if (i > 0)
        {
            printf("digit is in the %dth column\n", i);
            printf("digit = %d\n", digit);
            digit *= (16 * i);
            printf("Placed digit is %d\n", digit);
        }
        printf("Current digit is %d\n", digit);
        printf("Current Sum was %d\n", sum);
        sum += digit;
        printf("current sum is %d\n", sum);
    }

    return sum;
}