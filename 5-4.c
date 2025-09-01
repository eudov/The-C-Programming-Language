#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 1000

char *line;
char ch;
int strend(char *s, char *t);
char *s = "Test string &";

int main()
{
    // line has a double function of allocating the memory but also holding the start forever
    line = (char *)malloc(sizeof(char) * MAXLINE);

    // now line + i is the full length of the string
    int i = 0;
    while ((*(line + i) = ch = getchar()) != 'q')
    {
        if (ch == '\n')
        {
            *(line + i) = '\0';
            strrev(line);
            printf("%d\n", strend(s, line));
            i = 0;
            continue;
        }
        i++;
    }

    return 0;
}

int strend(char *s, char *t)
{
    // elegant little traversal
    for (; *s != '\0'; s++)
        ;

    while (*t != '\0')
    {
        if (*t++ == *--s)
        {
            printf("Matched %c and %c at end of string.\n", *(t - 1), *s);
        }
        else
        {
            printf("Did not find %c at end of string (%c)\n", *t, *s);
            return 0;
        }
    }
    printf("Reached end of string\n");
    return 1;
}