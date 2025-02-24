#include <stdio.h>

#define swap(t, x, y) \
    {                 \
        t tmp = x;    \
        x = y;        \
        y = tmp;      \
    }

int main(void)
{

    int a = 1;
    int b = 9;
    printf("a = %d, b = %d...\n", a, b);
    swap(int, a, b);
    printf("SWAPPED! a = %d, b = %d\n", a, b);

    char c = 'c';
    char d = 'd';
    printf("c = %c, d = %c...\n", c, d);
    swap(char, c, d);
    printf("SWAPPED! c = %c, d = %c...\n", c, d);
}