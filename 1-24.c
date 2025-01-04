#include <stdio.h>
#define MAXLINE 1000

char line[MAXLINE];
char c_program[] = "some brackets {{}lots of text here's an ( and oh look it closes) ) here's some braces for good measure[] ] dind't close did it";

int check_par(int o, int c);

int main()
{
    check_par('(', ')');
    check_par('{', '}');
    check_par('[', ']');

    return 0;
}

int check_par(int o, int c)
{
    int i, j, par_count, parc_count;
    int indices[MAXLINE - 1];
    for (i = j = par_count = parc_count = 0; i < MAXLINE - 1 && c_program[i] != EOF; ++i)
    {
        if (c_program[i] == o)
        {
            ++par_count;
            indices[j++] = i;
        }
        if (c_program[i] == c)
            ++parc_count;
    }
    if (par_count != parc_count)
    {
        printf("'%c' Count is: %d, '%c' Count is %d\n.", o, par_count, c, parc_count);
        // works for open note for improvement would need two branches
        if (par_count)
            printf("Mismatched %c / %c - at index %d\n", o, c, indices[par_count - parc_count]);
        for (int k = 0; k < 5; k++)
        {
            printf("%c", c_program[indices[par_count - parc_count] + k]);
        }
        printf("\n");
        return -1;
    }
    else
    {
        printf("No syntax errors detected.\n");
        return 0;
    }
}