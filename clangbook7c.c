#include <stdio.h>

int main()
{
    int alph[26];
    int c = 0;

    for (int i = 0; i < 26; ++i)
    {
        alph[i] = 0;
    }

    while ((c = getchar()) != EOF)
    {

        if (c >= 'a' && c <= 'z')
            alph[c - 'a']++;
        if (c == '\n')
        {
            printf("A-Z freqs are: \n");
            for (int i = 0; i < 26; ++i)
            {
                for (int j = 0; j < alph[i]; ++j)
                {
                    printf("#");
                }
                printf("\n");
            }
        }
    }
    return 0;
}