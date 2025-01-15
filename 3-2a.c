#include <stdio.h>

char line[];

void escape(char line[], char input[]);
void unescape(char line[], char input[]);

int main(void)
{
    char input[] = "here's a \n \\n and oh here's a \t \\t for good measure";

    // escape(line, input);
    unescape(line, input);

    printf("%s", line);

    return 0;
}

void escape(char line[], char input[])
{
    int i, j, c, next;
    for (i = j = 0; (c = input[i]) != '\0'; i++)
    {
        next = input[i + 1];
        switch (c)
        {
        case '\\':
            if (next == 'n')
                line[j++] = '\n';
            else if (next == 't')
                line[j++] = '\t';
            else if (next == '\\')
                line[j++] = '\\';
            ++i;
            break;
        default:
            line[j++] = input[i];
            break;
        }
    }
    line[j] = '\0';
}

void unescape(char line[], char input[])
{
    int i, j, c, next;
    for (i = j = 0; (c = input[i]) != '\0'; i++)
    {
        next = input[i + 1];
        switch (c)
        {
        case '\t':
            line[j++] = '\\';
            line[j++] = 't';
            break;
        case '\n':
            line[j++] = '\\';
            line[j++] = 'n';
            break;
        default:
            line[j++] = input[i];
            break;
        }
    }
    line[j] = '\0';
}