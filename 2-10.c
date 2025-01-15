#include <stdio.h>

void lower(void);
void lower2(void);

int main(void)
{

    lower2();

    return 0;
}

void lower(void)
{
    int cap_dist, c;
    cap_dist = 'A' - 'a';

    // get length
    while ((c = getchar()) != EOF && c != 'q')
    {
        if ((c >= 'A') && (c <= 'Z'))
            printf("%c", c);
        else if ((c >= 'a') && (c <= 'z'))
        {
            c += cap_dist;
            printf("%c", c);
        }
        else if (c == '\n')
        {
            printf("\n");
        }
        else
            printf("enter characters ONLY");
    }
    if (c == 'q')
        return;
}

void lower2(void)
{
    int cap_dist, c;
    cap_dist = 'A' - 'a';

    while ((c = getchar()) != EOF && c != 'q')
    {
        c = ((c >= 'A') && (c <= 'Z')) ? (c -= cap_dist) : c;
        printf("%c", c);
    }
}