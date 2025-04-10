#include <stdio.h>

char ch;
int strend(char *s, char t);

int main()
{
    while ((ch = getchar()) != 'q')
    {
        if (ch == '\n')
        {
            // printf("got here\n");
            continue;
        }

        char *s = "Test string &";

        printf("%d\n", strend(s, ch));
    }

    return 0;
}

int strend(char *s, char t)
{
    for (; *s != '\0'; s++)
        // printf("%c\n", *s);
        ;

    if (t == *--s)
    {
        printf("Found %c at end of string (%c)\n", t, *s);
        return 1;
    }
    else
    {
        printf("Did not find %c at end of string (%c)\n", t, *s);
        return 0;
    };
}