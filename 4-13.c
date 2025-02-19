#include <stdio.h>
#include <string.h>

// recursively turn an integer into a string
void reverse(char input[]);
char output[1000];

int main()
{
    char test[] = "1 2 3 4 5 6 7 8 9";
    printf("test = %s\n", test);

    reverse(test);

    printf("reverse test: %s\n", test);

    return 0;
}

void reverse(char input[])
{
    char tmp;
    int i, k, len;

    len = strlen(input);

    i = 0;
    k = (len - 1);
    while (i < k)
    {
        tmp = input[i];
        input[i++] = input[k];
        input[k--] = tmp;
    }
}