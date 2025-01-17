#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

void itob(int n, int b, char line[]);
void reverse(char s[]);

char line[1000];

int main()
{
    int base, n;
    base = 2;
    n = 8;

    // base 10 int to any base
    itob(n, base, line);
    printf("%s\n", line);
    // 1010
    itob(10, 2, line);
    printf("%s\n", line);
    // 101
    itob(65, 8, line);
    printf("%s\n", line);
    // FF
    itob(255, 16, line);
    printf("%s\n", line);
    // 400
    itob(100, 5, line);
    printf("%s\n", line);
    // 112
    itob(14, 3, line);
    printf("%s\n", line);
    // 9IX
    itob(12345, 36, line);
    printf("%s\n", line);
    // 1234
    itob(1234, 10, line);
    printf("%s\n", line);
    // 0
    itob(0, 2, line);
    printf("%s\n", line);

    return 0;
}

void itob(int n, int b, char input[])
{
    int i;
    i = 0;
    do
    {
        printf("n = %d\n", n);
        if ((n % b) < 10)
            input[i++] = ((n % b) + '0');
        else
            input[i++] = ((n % b) - 10 + 'A');
        n /= b;
    } while (n != 0);
    input[i] = '\0';
    reverse(input);
}

void reverse(char s[])
{
    int i, j;
    char tmp;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}