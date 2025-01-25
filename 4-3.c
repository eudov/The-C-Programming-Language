// this is shockingly robust and very cool!

#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char[]);
void push(double);
double pop(void);

int main(void)
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '%':
            printf("%d\n", (3 % 3));
            op2 = pop();
            push((int)(pop()) % (int)(op2));
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("unknown command %s\n", s);
            break;
        }
    }
    return 0;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

#include <ctype.h>

int get_ch(void);
void unget_ch(int);

int getop(char s[])
{
    int i, c;
    // ignore all empty space and assign first character to s[0]
    while ((s[0] = c = get_ch()) == ' ' || c == '\t')
        ;
    // null terminate right after in case there's only one char
    s[1] = '\0';
    // if it's not a number or decimal return it and let main give it's default error
    if (!isdigit(c) && c != '.')
        return c;
    // add all the digits to s
    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = get_ch()))
            ;
    // handle decimal, but pretty much just keep adding
    if (c == '.')
        while (isdigit(s[++i] = c = get_ch()))
            ;
    // null terminate for real
    s[i] = '\0';
    // if the last term is not EOF, store it and deal with it later (it sends it to get_ch)
    if (c != EOF)
        unget_ch(c);
    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int get_ch(void)
{
    // if there's something in the buffer, send that first
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void unget_ch(int c)
{
    // simple overflow check then add it to the buffer
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}