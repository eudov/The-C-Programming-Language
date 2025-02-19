#include <stdio.h>

int getInt(char line[], int len);
void printd(int n);
int getline(void);
char line[1000];
int c, len;

int main()
{
    // this converts input into a string, then back to an int... haha
    while ((len = getline()) != 0)
    {
        printd(getInt(line, len));
        printf(" but as a string...");
    }

    return 0;
}

int getInt(char line[], int len)
{
    int i, num, str_len;

    num = 0;
    str_len = (len - 1);
    for (i = str_len; i >= 0; i--)
    {
        // printf("num = %d, line[%d] = %c", num, i, line[i]);
        if (i == 0)
        {
            num += (line[i] - '0');
        }
        else
        {
            num += ((line[i] - '0') * 10 * i);
        }
        // printf(" new num = %d\n", num);
    }

    return num;
}

void printd(int n)
{
    if (n < 0)
    {
        putchar('-');
        n = -n;
    }
    if (n / 10)
        printd(n / 10);

    putchar(n % 10 + '0');
}

int getline(void)
{
    int i = 0;
    while ((c = getchar()) != '\0' && c != '\n')
    {
        line[i++] = c;
    }
    line[i] = '\0';
    return i;
}