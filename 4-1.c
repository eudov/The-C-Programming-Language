#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int lim);
int strindex(char source[], char searchfor[]);

int main(void)
{
    char target[] = "pat";
    char line[MAXLINE];
    int r_index;

    // main loop
    // while there's another line
    while (get_line(line, MAXLINE) > 0)
    {
        // Print the rightmost index of the found string
        if ((r_index = (strindex(line, target))) >= 0)
        {
            printf("rightmost index is %d\n", r_index);
        }
        else
            printf("target not found (%d)\n", r_index);
    }
    return 0;
}

int get_line(char line[], int lim)
{
    int i, c;

    i = 0;
    while (--lim > 0 && ((c = getchar()) != '\n' && c != EOF))
    {
        line[i++] = c;
    }
    if (c == '\n')
        line[i++] = c;
    line[i] = '\0';
    return i;
}

int strindex(char source[], char searchfor[])
{
    int i, j, k, index;

    index = -1;
    for (i = 0; source[i] != '\n' && source[i] != '\0'; i++)
    {
        // different iteration variables to preserve the first matching index (potentially the start of the correct match)
        for (j = i, k = 0; searchfor[k] != '\0' && source[j] == searchfor[k]; j++, k++)
            ;
        if (searchfor[k] == '\0' && k > 0)
        {
            index = i;
        }
    }

    return index;
}