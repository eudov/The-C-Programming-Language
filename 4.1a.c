#include <stdio.h>
#define MAXLINE 1000

int get_line_from_buff(char line[], int lim, const char buffer[], int *pos);
int strindex(char source[], char searchfor[]);

char test[] = "would could\n don't return\nif return something wrong\nbut could you return this\nbut not this\n";

char pattern[] = "ould";

int main()
{
    char line[MAXLINE];
    int found = 0;
    int pos = 0;
    int last = -1;

    while (get_line_from_buff(line, MAXLINE, test, &pos) > 0)
        if ((last = (strindex(line, pattern))) >= 0)
        {
            printf("%s\n", line);
            printf("last index found at: %d\n", last);
            found++;
        }

    return found;
}

int get_line_from_buff(char line[], int lim, const char buffer[], int *pos)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c = buffer[*pos]) != '\0' && c != '\n')
    {
        line[i++] = c;
        (*pos)++;
    }
    if (c == '\n')
    {
        line[i++] = c;
        (*pos)++;
    }
    line[i] = '\0';
    return i;
}

int strindex(char source[], char searchfor[])
{
    int i, j, k, last;
    last = -1;

    for (i = 0; source[i] != '\0'; i++)
    {
        for (j = i, k = 0; searchfor[k] != '\0' && source[j] == searchfor[k]; j++, k++)
            ;
        if (k > 0 && searchfor[k] == '\0')
        {
            last = i;
            return i;
        }
    }
    if (last >= 0)
        return last;
    else
        return -1;
}