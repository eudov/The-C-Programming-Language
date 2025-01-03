#include <stdio.h>
#define MAXLINE 1000
#define LINE_LEN 16

char line[MAXLINE];
int getline(void);
char testchar(void);

int main()
{
    while (getline() != 0)
        printf("%s", line);
    return 0;
}

int getline(void)
{
    int c, i, j;

    for (i = j = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i, ++j)
    {
        if ((c == ' ' || c == '\t') && j >= LINE_LEN - 1)
        {
            line[i] = '\n';
            j = 0;
        }
        if (j > (LINE_LEN * 2))
        {
            line[i] = c;
            line[++i] = '\n';
            j = 0;
        }
        else
            line[i] = c;
    }
    if (c == '\n')
    {
        line[i] = c;
    }
    ++i;
    line[i] = '\0';
    return i;
}