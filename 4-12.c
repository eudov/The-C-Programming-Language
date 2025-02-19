#include <stdio.h>
#include <string.h>

// recursively turn an integer into a string
void printd(int input, int index);
int getlen(int n);
char output[1000];

int main()
{
    int test = 12345;
    int len = getlen(test);

    printd(test, len - 1);
    output[len + 1] = '\0';
    printf("%s", output);

    return 0;
}

void printd(int input, int index)
{
    printf("input = %d, index = %d\n", input, index);

    int num = input;

    if (num / 10)
        printd((num / 10), (index - 1));

    output[index] = ((num % 10) + '0');
    printf("output[%d] = %c\n", index, output[index]);
}

int getlen(int n)
{
    int i = 1;
    while ((n /= 10) != 0)
    {
        i++;
    }
    printf("len is %d\n", i);
    return i;
}