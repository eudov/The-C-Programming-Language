#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{
    int c;
    int state = OUT;
    while ((c = getchar()) != EOF)
    {
        if (state == OUT)
        {
            state = IN;
            printf(("%c\n"), c);
        }
        if (c == ' ' || c == '\n' || c == '\t')
        {
            state = OUT;
        }
    }
    return 0;
}