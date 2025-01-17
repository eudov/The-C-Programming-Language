#include <stdio.h>
#define MAXLINE 1000

void itob(int n, int b, char input[]);

char input[1000];

int main()
{
    int base, n;
    base = 2;
    n = 15;
    itob(n, base, input);
    printf("%s", input);

    return 0;
}

void itob(int n, int b, char input[])
{
    int i, tmp, rem, ch, special_char;
    ch = '0';
    i = 0;
    special_char = b + '0';
    do
    {
        tmp = n / b;
        if (rem = (tmp % b) != 0)
        {
            if (rem)
                input[i++] = ch;
        }
        /*15/2 = 7.5
             1
        7 / 2 = 3.5
            11
        3 / 2 = 1.5
            111
        1/2 = 0/5
            1111
             */

    } while (n % b != 0);
    if ()

    // dostuff
}