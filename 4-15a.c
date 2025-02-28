#include <stdio.h>
#include <ctype.h>

#define SIZE 1000

int get_ch(void);
void unget_ch(int);

int getint(int *pn, int *sign)
{
    int c;

    while (isspace(c = get_ch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        // unget_ch(c);
        return 0;
    }

    if (c == '+' || c == '-')
    {
        *sign = (c == '-') ? -1 : 1;
        return -2;
    }

    for (*pn = 0; isdigit(c); c = get_ch())
        *pn = 10 * *pn + (c - '0');
    *pn *= *sign;
    *sign = 1;
    if (c != EOF)
        unget_ch(c);
    printf("got here\n");
    return c;
}

int main(void)
{
    // c is just a flag for errors - not sure if this is the most elegant
    int n, c, sign, array[SIZE], getint(int *, int *);
    n = 0;
    while (n < SIZE && (c = getint(&array[n], &sign)) != EOF)
    {

        if (c == 0)
        {
            printf("ERROR - Not a number!\n");
        }
        else if (c == -2)
        {
            printf("sign detected, storing\n");
        }
        else
        {
            for (int j = 0; j < (n + 1); j++)
            {
                printf("%d", array[j]);
            }
            printf(", n = %d\n", n);
            n++;
        }
    }
}

#define bufsize 100

char buf[bufsize];
int bufp = 0;

int get_ch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void unget_ch(int c)
{
    if (bufp > bufsize)
    {
        printf("unget_ch: too many characters");
    }
    else
        buf[bufp++] = c;
}