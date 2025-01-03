#include <stdio.h>
#define MAXLINE 1000
#define TAB_WIDTH 8

char line[MAXLINE];

int getline(void);

int main()
{
    int len;

    while ((len = getline()) != 0)
    {
        printf("%s", line);
    }
    return 0;
}

int getline(void)
{
    int c, i;
    extern char line[];

    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n';)
    {
        if (c == '\t')
        {
            int spaces = TAB_WIDTH - (i % TAB_WIDTH);
            for (int j = 0; j < spaces; ++j)
            {
                line[i] = ' ';
                ++i;
            }
        }
        else
        {
            line[i] = c;
            ++i;
        }
    }

    if (c == '\n')
    {
        line[i] = '\n';
        ++i;
    }
    line[i] = '\0';
    return i;
}
