#include <stdio.h>

#define LOWER 0

#define UPPER 300

#define STEP 20

void to_celsius(float fahr);

void to_fahrenheit();

int main()
{
    float fahr = UPPER;

    printf("Fahr\tCelsius\n");
    to_celsius(fahr);

    printf("Celsius\tFahr\n");
    to_fahrenheit();

    return 0;
}

void to_celsius(float fahr)
{
    float celsius;
    while (fahr >= LOWER)
    {
        celsius = 5 * (fahr - 32) / 9;
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr -= STEP;
    }
}

// logic not dependent on upper/lower bounds but exercise prompt was ambiguous anyway
void to_fahrenheit()
{
    float fahr;
    for (float i = 0; i <= 15; i++)
    {
        fahr = (i * 9 / 5) + 32;
        printf("%2.0f\t%6.1f\n", i, fahr);
    }
}