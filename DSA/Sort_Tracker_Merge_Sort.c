#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <psapi.h>
#include <time.h>

// ---------------- MERGE SORT ----------------
void merge(int *arr, int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0;
    int *newArr = (int *)malloc(sizeof(int) * (high - low + 1));
    if (!newArr)
    {
        printf("Memory allocation failed in merge!\n");
        exit(1);
    }

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
            newArr[k++] = arr[i++];
        else
            newArr[k++] = arr[j++];
    }
    while (i <= mid)
        newArr[k++] = arr[i++];
    while (j <= high)
        newArr[k++] = arr[j++];

    i = low;
    k = 0;
    while (i <= high)
        arr[i++] = newArr[k++];

    free(newArr);
}

void merge_sort(int *arr, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

// ---------------- MEMORY USAGE ----------------
size_t getCurrentMemoryUsage()
{
    PROCESS_MEMORY_COUNTERS memInfo;
    GetProcessMemoryInfo(GetCurrentProcess(), &memInfo, sizeof(memInfo));
    return memInfo.WorkingSetSize;
}

// ---------------- TIME UTIL ----------------
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

// ---------------- MAIN ----------------
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
        arr[i] = rand();

    printCurrentISTTime();

    size_t memBefore = getCurrentMemoryUsage();
    double start = getHighResolutionTime();

    merge_sort(arr, 0, size - 1);

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
