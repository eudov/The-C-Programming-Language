#include <stdio.h>
#include <string.h>
#define MAXLEN 1000

int indices(char ch1[], char ch2[]);

int main()
{
    char ch1[] = "012b34c56a89aa1591951c5656b";
    char ch2[] = "z";

    int flag = indices(ch1, ch2);
    printf("%d", flag);
    return 0;
}

int indices(char ch1[], char ch2[])
{
    int i, j;
    int flag = -1;
    for (i = j = 0; i < ((int)strlen(ch1)); ++i)
    {
        for (int k = 0; k < ((int)strlen(ch2)); ++k)
        {
            // printf("Checking character %c against mask %d/%d\n", ch1[i], (k + 1), ((int)strlen(ch2)));
            if (ch1[i] == ch2[k])
            {
                printf("Match found at %d, %c & %c\n", i, ch1[i], ch2[k]);
                flag = 1;
                break;
            }
        }
    }
    return flag;
}