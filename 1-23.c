#include <stdio.h>
#define MAXLINE 1000

char line[MAXLINE];
char c_program[] = "#include <stdio.h>\nint main()\n{\n// adding wayyyyy too many comments\nprintf(\"hello, world\");\n/* this is a multi-line\ncomment*/\nprintf(\"this is an edge case\");\nreturn 0;\n}";

int get_line(void);

int main()
{
    get_line();
    printf("%s", line);
    return 0;
}

int get_line(void)
{
    int c, i, j;

    for (i = j = 0; i < MAXLINE - 1 && (c = c_program[i]) != '\0'; ++i)
    {
        if (c_program[i] == '/' && (c_program[i + 1] == '/'))
        {
            while (c_program[i] != '\n')
            {
                printf("%c", c_program[i]);
                ++i;
            }
            printf("\n");
            c = c_program[i];
        }
        // this will break if any /s are in the comment
        if (c == '/' && (c_program[i + 1] == '*'))
        {
            i += 2;
            while ((c_program[i] != '*') && (c_program[i + 1] != '/'))
            {
                printf("%c", c_program[i++]);
            }
            printf("\n");
            ++i;
        }
        else
        {
            line[j++] = c;
        }
    }
    return i;
}
