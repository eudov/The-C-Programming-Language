#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000

double ato_f(char s[]);
int get_line(char line[], int MAX);

int main(void)
{
    // double val;
    // char input[] = " 15.15";
    // val = ato_f(input);
    // printf("Float is: %f\n", val);

    double sum, ato_f(char[]);
    char line[MAXLINE];

    sum = 0;
    while (get_line(line, MAXLINE) > 0)
        printf("\t%g\n", sum += ato_f(line));
    return 0;
}

// the way this works is cool - it just 10x everything for each digit, then divides by 10x for everything after the decimal
double ato_f(char s[])
{
    double val, power;
    int i, sign;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    return sign * val / power;
}

int get_line(char line[], int max)
{
    int i, c;
    for (i = 0; i < max && (c = getchar()) != EOF && c != '\n';)
    {
        line[i++] = c;
    }
    if (c == '\n')
        line[i++] = c;
    line[i] = '\0';
    return i;
}