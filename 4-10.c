// this is shockingly robust and very cool!

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAXOP 100
// range right exclusive for custom variables - a through z
#define RANGE_MIN 0
#define RANGE_MAX 3

#define NUMBER '0'
#define SIN -5
#define EXP -6
#define POW -7
#define VAR_OP -8

int getop(char[]);
void push(double);
double pop(void);
double peek(void);
void printStack(void);
void duplicate(void);
void swap();
void clear();
void custom_var(double value);
int get_line(void);

int var_flag = -1;
double a;

int main(void)
{
    int type;
    double op1, op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case VAR_OP:
            push(a);
            break;
        case NUMBER:
            printf("pushing %f\n", atof(s));
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
        case 'p':
            printStack();
            break;
        case 'd':
            duplicate();
            break;
        case 's':
            swap();
            break;
        case 'c':
            clear();
            break;
        case SIN:
            push(sin(pop()));
            break;
        case EXP:
            push(exp(pop()));
            break;
        case POW:
            op2 = pop();
            op1 = pop();
            if (op2 <= 0 && op1 == 0)
                printf("error: zero to negative power\n");
            else
                push(pow(op1, op2));
            break;
        case '=':
            custom_var(pop());
            break;
        case '\n':
            printf("\t%.8g\n", peek());
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

double peek(void)
{
    return val[sp - 1];
}

void duplicate(void)
{
    if (sp < MAXVAL)
    {
        val[sp] = val[sp - 1];
        ++sp;
    }
}

void printStack(void)
{
    int i;
    for (i = (sp - 1); i >= 0; --i)
    {
        printf("Stack index %d: %.8g\n", i, val[i]);
    }
}

void swap(void)
{
    double tmp;
    printf("Top is: %0.8g, Second is: %0.8g\n", val[sp - 1], val[sp - 2]);
    tmp = val[sp - 1];
    val[sp - 1] = val[sp - 2];
    val[sp - 2] = tmp;
    printf("Top is now: %0.8g, Second is now: %0.8g\n", val[sp - 1], val[sp - 2]);
}

// LOL
void clear(void)
{
    sp = 0;
}

void custom_var(double value)
{
    a = value;
    var_flag = 1;
    printf("a set to %0.8g\n", value);
}

#define BUFSIZE 1000

char buf[BUFSIZE];
int buff_pos = 0;

int get_line(void)
{
    int i, c;

    for (i = 0; i < BUFSIZE && ((c = getchar()) != '\0') && c != '\n' && c != EOF; i++)
    {
        buf[i] = c;
    }

    if (c == '\n')
    {
        buf[i] = c;
    }

    buf[i] = '\0';
    return i;
}

#include <ctype.h>

int getop(char s[])
{
    int i, c;

    if (buf[buff_pos] == '\0')
    {
        if (get_line() == 0)
        {
            return EOF;
        }
        buff_pos = 0;
    }

    // ignore all empty space and assign first character to s[0]
    while ((s[0] = c = buf[buff_pos++]) == ' ' || c == '\t')
        ;
    // null terminate right after in case there's only one char
    s[1] = '\0';
    if (c == EOF)
    {
        printf("Reached end of file... Goodbye!");
        exit(0);
    }
    if (var_flag == 1 && c == 'a')
    {
        // if a is set, unset it and push a to stack
        //  printf("got here a = %0.8g\n", a);
        var_flag = -1;
        return VAR_OP;
    }
    if (c == 'S')
    {
        if ((c = buf[buff_pos++]) == 'I')
        {
            if ((c = buf[buff_pos++]) == 'N')
            {
                return SIN;
            }
        }
        return -1;
    }
    if (c == 'E')
    {
        if ((c = buf[buff_pos++]) == 'X')
        {
            if ((c = buf[buff_pos++]) == 'P')
            {
                return EXP;
            }
        }
        return -1;
    }
    if (c == 'P')
    {
        if ((c = buf[buff_pos++]) == 'O')
        {
            if ((c = buf[buff_pos++]) == 'W')
            {
                return POW;
            }
        }
        return -1;
    }
    // if it's not a number or decimal return it and let main handle with switch
    if (!isdigit(c) && c != '.' && c != '-')
        return c;
    i = 0;
    // handle negatives - this was hard
    if (c == '-')
    {
        // check if the next one is a digit, if it is, we need to use it
        if (isdigit(c = buf[buff_pos++]))
        {
            ;
            while (isdigit(s[++i] = c = buf[i++]))
                ;
        }
        // if not, save it for the next iteration, but return '-' manually (we lost it from the last if check)
        else
        {
            --i;
            return '-';
        }
    }
    // add all the digits to s
    if (isdigit(c))
        while (isdigit(s[++i] = c = buf[i++]))
            ;
    // handle decimal, but pretty much just keep adding
    if (c == '.')
        while (isdigit(s[++i] = c = buf[i++]))
            ;
    // null terminate for real
    s[i] = '\0';
    // if the last term is not EOF, store it and deal with it later (it sends it to get_ch)
    if (c != EOF)
        --i;
    return NUMBER;
}
