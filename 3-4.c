#include <stdio.h>
#include <string.h>

void itoa(long long int n, char input[]);
void reverse(char input[]);

int main()
{
    char s[1000];
    long long int n = -9223372036854775808LL;
    unsigned long long int b = 9223372036854775808ULL;

    itoa(n, s);
    printf("b = %s\n", s);

    return 0;
}

void itoa(long long int g, char input[])
{
    unsigned long long int n;
    long long int i, sign;

    // edge case - because msb is negative we need to treat the compliment (making it positive) in a special way
    if (g == -9223372036854775808LL)
    {
        n = 9223372036854775808LL;
        sign = -1;
        printf("n = %llu\n", n);
    }
    else if ((sign = g) < 0)
        n = -g;
    else
        n = g;
    i = 0;
    do
    {
        input[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        input[i++] = '-';
    input[i] = '\0';
    reverse(input);
}

void reverse(char input[])
{
    int len = strlen(input);
    char temp[len + 1];
    int i, j;

    j = len - 1;
    for (i = 0; i < len; ++i, --j)
    {
        temp[i] = input[j];
    }

    temp[len] = '\0';
    strcpy(input, temp);
}