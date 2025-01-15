#include <stdio.h>
#define MAXLINE 1000

char line[MAXLINE];

void expand(char input[], char line[]);

int main()
{
    char input1[] = "a-z a-z";
    char input2[] = "1-9";
    char input3[] = "a-d 1-9 1-3 a-c A-C b-a abc 123";
    char input4[] = "abc a-c 1-5 123";

    expand(input3, line);
    printf("%s\n", line);

    return 0;
}

void expand(char input[], char line[])
{
    int i, j, l, r;
    for (i = j = 0; i < MAXLINE - 1 && input[i] != '\0'; i++)
    {
        printf("i = %d\n", i);
        if (input[i] == '-')
        {
            l = input[i - 1];
            r = input[i + 1];

            if ((l >= 'a' && l <= 'z') && (r >= 'a' && r <= 'z'))
            {
                if (r > l)
                {
                    j--;
                    for (int k = 0; k <= (r - l); k++, j++)
                    {
                        printf("k = %d\n", k);
                        line[j] = (l + k);
                    }
                    i += 2;
                }
            }
            if ((l >= 'A' && l <= 'Z') && (r >= 'A' && r <= 'Z'))
            {
                if (r > l)
                {
                    j--;
                    for (int k = 0; k <= (r - l); k++, j++)
                    {
                        printf("k = %d\n", k);
                        line[j] = (l + k);
                    }
                    i += 2;
                }
            }
            if ((l >= '0' && l <= '9') && (r >= '0' && r <= '9'))
            {
                if (r > l)
                {
                    j--;
                    for (int k = 0; k <= (r - l); k++, j++)
                    {
                        printf("k = %d\n", k);
                        line[j] = (l + k);
                    }
                    ++i;
                }
            }
            else
                line[j++] = input[i];
        }
        else
        {
            line[j++] = input[i];
        }
    }
    if (input[i] == '\0')
        line[++j] = '\0';
}