#include <stdio.h>

#define LOWER 0

#define UPPER 300

#define STEP 20

int main()
{
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = upper;

    printf("Fahr\tCelsius\n");

    while (fahr >= lower)
    {
        celsius = 5 * (fahr - 32) / 9;
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr -= step;
    }

    printf("Celsius\tFahr\n");

    for (float i = 0; i <= 15; i++)
    {
        fahr = (i * 9 / 5) + 32;
        printf("%2.0f\t%6.1f\n", i, fahr);
    }

    return 0;
}