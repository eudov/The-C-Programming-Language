#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int arr[] = {3, 10, 15, 20, 25, 30, 35, 40, 45, 50};

int binsearch(int x, int v[], int n);
int binsearch2(int x, int v[], int n);
int binsearch3(int x, int v[], int n);
int binsearch4(int x, int v[], int n);

int main()
{
    int *arr2 = (int *)malloc(1000000 * sizeof(int));
    if (arr2 == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }
    for (int i = 0; i < 1000000; ++i)
    {
        arr2[i] = i + 1;
    }

    int target = 1000000;

    clock_t start_time = clock();
    binsearch4(target, arr2, target);
    clock_t end_time = clock();

    clock_t start_time2 = clock();
    binsearch(target, arr2, target);
    clock_t end_time2 = clock();

    double runtime_two_tests = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Original binary search run-time: %f seconds\n", runtime_two_tests);

    double runtime_two_tests2 = ((double)(end_time2 - start_time2)) / CLOCKS_PER_SEC;
    printf("Improved binary search run-time: %f seconds\n", runtime_two_tests2);

    // binsearch(20, arr, 10);
    // binsearch2(50, arr, 10);
    // binsearch4(25, arr, 10);

    return 0;
}

int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high)
    {
        printf("low (%d) is less than high (%d)\n", low, high);
        mid = (low + high) / 2;
        printf("mid = %d\n", mid);
        if (x < v[mid])
        {
            printf("%d is less than v[mid] %d\n", x, v[mid]);
            high = mid - 1;
        }
        else if (x > v[mid])
        {
            printf("%d is more than v[mid] %d\n", x, v[mid]);
            low = mid + 1;
        }
        else
        {
            printf("Found %d at index %d!\n", x, mid);
            return mid;
        }
    }
    return -1;
}

int binsearch2(int x, int v[], int n)
{

    int mid, low, high;
    low = 0;
    high = n - 1;

    while (low <= high)
    {
        mid = low + ((high - low) / 2);
        printf("low (%d) is less than high (%d)\n", low, high);
        if (v[mid] == x)
        {
            printf("Found %d at index %d!\n", x, mid);
            return mid;
        }
        else if (x > v[mid])
        {
            printf("%d is more than v[mid] %d\n", x, v[mid]);
            low = mid + 1;
        }
        else
        {
            printf("%d is less than v[mid] %d\n", x, v[mid]);
            high = mid;
        }
    }
    return -1;
}

int binsearch3(int x, int v[], int n)
{

    int mid, low, high;
    low = 0;
    high = n;

    while (low < high && v[mid] != x)
    {
        mid = low + ((high - low) / 2);
        printf("low (%d) is less than high (%d)\n", low, high);
        if (x > v[mid])
        {
            printf("%d is more than v[mid] %d\n", x, v[mid]);
            low = mid + 1;
        }
        else
        {
            printf("%d is less than v[mid] %d\n", x, v[mid]);
            high = mid;
        }
    }
    if (v[mid] == x)
    {
        printf("Found %d at index %d!\n", x, mid);
        return mid;
    }
    else
    {
        printf("Not Found...");
        return -1;
    }
}

int binsearch4(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high && v[mid] != x)
    {
        mid = (low + high) / 2;
        printf("low (%d) is less than high (%d)\n", low, high);
        if (x < v[mid])
        {
            printf("%d is less than v[mid] %d\n", x, v[mid]);
            high = mid - 1;
        }
        else
            printf("%d is more than v[mid] %d\n", x, v[mid]);
        {
            low = mid + 1;
        }
    }
    if (v[mid] == x)
    {
        printf("Found %d at index %d!\n", x, mid);
        return mid;
    }
    else
    {
        printf("Not Found...\n");
        printf("final values mid = %d high = %d low = %d", mid, high, low);
        return -1;
    }
}