#include <stdio.h>
#define MAXLINE 1000
char line[MAXLINE];
int c, i;
int main()
{

    for (int i = 0; i < MAXLINE - 1; ++i)
    {
        if ((c = getchar()) != '\n')
            if (c != EOF)
                line[i] = c;
            else
            {
                break;
            }
        else
        {
            line[i] = c;
            line[++i] = '\0';
            break;
        }
    }
    printf("%s", line);
    return 0;
}