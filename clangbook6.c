#include <stdio.h>

#define IN 1
#define OUT 0
int main()
{
    int c, nl, nw, nc, state;
    state = 0;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF)
    {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        if (c == 17)
        {
            --nl;
            --nw;
            nc -= 2; // correct for both characters before printing
            printf("c = %d, %d %d %d\n", c, nl, nw, nc);
        }
        else if (state == OUT)
        {
            state = IN;
            ++nw;
        }
    }
    return 0;
}
