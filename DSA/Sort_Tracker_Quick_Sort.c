#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <psapi.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high)
{
    // pick random pivot
    int pivotIndex = low + rand() % (high - low + 1);
    swap(&arr[pivotIndex], &arr[low]);
    int pivotValue = arr[low];

    int i = low + 1;
    int j = high;

    while (1)
    {
        while (i <= high && arr[i] <= pivotValue)
            i++;
        while (j >= low && arr[j] > pivotValue)
            j--;
        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
        else
        {
            break;
        }
    }
    swap(&arr[low], &arr[j]);
    return j;
}

void quickSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

size_t getCurrentMemoryUsage()
{
    PROCESS_MEMORY_COUNTERS memInfo;
    GetProcessMemoryInfo(GetCurrentProcess(), &memInfo, sizeof(memInfo));
    return memInfo.WorkingSetSize;
}

void printCurrentISTTime()
{
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    rawtime += 19800; // UTC+5:30
    timeinfo = gmtime(&rawtime);
    printf("Algorithm started at (IST): %02d:%02d:%02d\n",
           timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
}

double getHighResolutionTime()
{
    LARGE_INTEGER freq, counter;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&counter);
    return (double)counter.QuadPart / (double)freq.QuadPart;
}

int main()
{
    int size;
    printf("Enter array size: ");
    if (scanf("%d", &size) != 1 || size <= 0)
    {
        printf("Invalid size.\n");
        return 1;
    }

    int *arr = (int *)malloc(size * sizeof(int));
    if (!arr)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    srand((unsigned int)time(NULL));
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand();
    }

    printCurrentISTTime();
    size_t memBefore = getCurrentMemoryUsage();
    double start = getHighResolutionTime();

    quickSort(arr, 0, size - 1);

    double end = getHighResolutionTime();
    size_t memAfter = getCurrentMemoryUsage();

    double timeTaken = end - start;

    printf("\nTime taken for sorting: %.6f seconds\n", timeTaken);
    printf("Memory used before sort: %zu bytes\n", memBefore);
    printf("Memory used after sort:  %zu bytes\n", memAfter);
    printf("Memory difference:       %zu bytes\n",
           (memAfter > memBefore) ? (memAfter - memBefore) : (memBefore - memAfter));

    free(arr);
    return 0;
}
