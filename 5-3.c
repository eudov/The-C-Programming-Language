#include <stdio.h>
#define MAX 1000

char *str1 = "Testing Testing testing";
char *str2 = "e - and now for my next trick!";
char output[MAX];

void strcato(char *s, char *t);

int main()
{
    printf("str1: %s \nstr2: %s\n", str1, str2);

    strcato(str1, str2);

    printf("output is: %s", output);

    return 0;
}

void strcato(char *s, char *t)
{
    int i;

    i = 0;
    for (; *s != '\0'; s++)
        output[i++] = *s;
    // printf("*s = %c\n", *s);
    ;

    if (*s == '\0')
    {
        printf("*s is currently \\0\n");
    }
    printf("*t = %c\n", *t);

    while ((*t++))
    {
        output[i++] = *t;
        printf("*t = %c\n", *t);
    }
    output[i] = '\0';
}