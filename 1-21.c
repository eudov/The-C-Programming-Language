#include <stdio.h>
#define MAXLINE 1000
#define TAB 8

int getline(void);

char line[MAXLINE];

int main()
{
    int len;
    extern char line[];

    while ((len = getline()) != 0)
    {
        printf("%s", line);
    }
    return 0;
}

int getline(void)
{
    int i, c;
    extern char line[];

    for (i = 0; i < MAXLINE - 1 && (c = getchar()) == ' '; ++i)
    {
        line[i] = '~';
    }
    if (c == '\n' && (i % TAB) != 0)
    {
        line[i] = '\t';
        line[++i] = '<';
        line[++i] = '\n';
        line[++i] = '\0';
    }
    else
    {
        printf("ENTER BLANK CHARACTERS ONLY\n");
    }

    return i;
}