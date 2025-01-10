#include <stdio.h>
#include <string.h>
#define MAXLEN 1000

void squeeze(char ch1[], char ch2[]);

char ch3[MAXLEN];

int main()
{
    char ch1[] = "111 111 mas k t es t1 111";
    char ch2[] = "mask test";

    squeeze(ch1, ch2);

    return 0;
}

void squeeze(char ch1[], char ch2[])
{
    int i, j;
    for (i = j = 0; i < ((int)strlen(ch1)); ++i)
    {
        for (int k = 0; k <= ((int)strlen(ch2)) - 1; ++k)
        {
            printf("Checking character %c against mask %d/%d\n", ch1[i], (k + 1), ((int)strlen(ch2)));
            if (ch1[i] == ch2[k])
            {
                printf("Match found, removing character (%c and %c)\n", ch1[i], ch2[k]);
                break;
            }
            if (k == ((int)strlen(ch2)) - 1)
            {
                printf("Character %c safe\n", ch1[i]);
                ch3[j++] = ch1[i];
            }
        }
        printf("Current output is: %s\n", ch3);
    }

    ch3[j] = '\0';
    printf("Final output is: %s\n", ch3);
}