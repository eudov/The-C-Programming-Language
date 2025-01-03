#include <stdio.h>

int main()
{
    int c, b = 0, t = 0, n = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == 9)
        {
            t++;
            printf("\\t");
        }
        if (c == 10)
        {
            n++;
            printf("\\n");
        }
        if (c == 32)
        {
            b++;
            printf("\\b");
        }
        // printf("Input is: %d, Blanks: %d, Tabs: %d, Newlines: %d\n", c, b, t, n);
    }
    return 0;

