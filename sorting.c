#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

int sort_func(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    long long total_iterations = (long long)length * (length - 1) / 2;
    return total_iterations;
}

int main()
{
    int length;

    printf("Enter the length of array: ");
    scanf("%d", &length);

    int *arr = (int *)malloc(length * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    srand((unsigned int)time(NULL));
    for (int i = 0; i < length; i++)
    {
        arr[i] = rand() % 100000;
    }
    printf("Array generation successfull");

    LARGE_INTEGER frequency, start_time, end_time;
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start_time);

    long long total_iterations = sort_func(arr, length);

    QueryPerformanceCounter(&end_time);

    double runtime = (double)(end_time.QuadPart - start_time.QuadPart) / frequency.QuadPart;

    printf("\nSorted array:\n");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Show performance report
    printf("\n=== Performance Report ===\n");
    printf("Length of array:         %d\n", length);
    printf("Runtime:                 %.10f seconds\n", runtime);
    printf("Memory used (array):     %lu bytes\n", length * sizeof(int));
    printf("Total iterations:        %lld\n", total_iterations);

    free(arr);
    return 0;
}
