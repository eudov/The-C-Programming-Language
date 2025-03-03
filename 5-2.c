#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define SIZE 1000

int get_ch(void);
void unget_ch(int);

int getfloat(float *pn, int *sign, int *dec)
{
    float c;

    while (isspace(c = get_ch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.')
    {
        // unget_ch(c);
        return 0;
    }

    if (c == '+' || c == '-')
    {
        *sign = (c == '-') ? -1 : 1;
        return -2;
    }

    if (c == '.')
    {
        *dec = -1;
        return -3;
    }

    if (*dec == -1)
    {
        // for floats, we can't do it the same way, basically += c / 10^i for everything after decimal
        for (int i = 1; isdigit(c); c = get_ch(), i++)
        {
            printf("i = %d, *pn = %f\n", i, *pn);
            *pn += (c - '0') / (pow(10, i));
        }
        *dec = 0;
    }
    else
    {
        // lots of very interesting summation ideas in this book - this one multiplies the last digit (or rather, most significant) by ten then adds the next
        for (*pn = 0; isdigit(c); c = get_ch())
            *pn = 10 * *pn + (c - '0');
    }
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
    int n, sign, dec, getfloat(float *, int *, int *);
    float c, array[SIZE];
    n = 0;

    // turned this into a while loop to use my 'error' handling - mostly to bubble the error then go through the next iteration
    //  this loop sends in the address of array item n - then c returns an error - the values are set in the getfloat fn
    while (n < SIZE && (c = getfloat(&array[n], &sign, &dec)) != EOF)
    {

        if (c == 0)
        {
            printf("ERROR - Not a number!\n");
        }
        else if (c == -2)
        {
            printf("sign detected, storing\n");
        }
        // if we found a decimal, we need to operate on the previous item in the array
        else if (c == -3)
        {
            printf("decimal found!\n");
            n--;
        }
        // if no errors, print then increment
        else
        {
            for (int j = 0; j < (n + 1); j++)
            {
                printf("%0.4f, ", array[j]);
            }
            printf("n = %d\n", n);
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