#include <stdio.h>
#define MAXLINE 1000

int get_line(char input[], int limit);

int main()
{
    int len;
    char line[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0)
    {

        if (len == 1 && line[0] == '\n')
        {
            continue;
        }
        for (int i = len - 1; i >= 0; --i)
        {
            printf("%c", line[i]);
        }
        printf("\n");
    }
    return 0;
}

int get_line(char input[], int limit)
{
    char c;
    int i;

    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        input[i] = c;
    }

    if (c == '\n')
    {
        input[i++] = c;
    }

    input[i] = '\0';
    return i;
}