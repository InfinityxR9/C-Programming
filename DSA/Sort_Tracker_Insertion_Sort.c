#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <psapi.h>

// InsertionSort algorithm copied here
void InsertionSort(int *arr, int size){
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];

        int j = i-1;
        while(arr[j] > key && j >= 0) {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }    
}

// Function to get current process memory usage in bytes (Windows-specific)
size_t getCurrentMemoryUsage() {
    PROCESS_MEMORY_COUNTERS memInfo;
    GetProcessMemoryInfo(GetCurrentProcess(), &memInfo, sizeof(memInfo));
    return memInfo.WorkingSetSize;
}

// Function to print current IST time in HH:MM:SS format
void printCurrentISTTime() {
    time_t rawtime;
    struct tm * timeinfo;
    time(&rawtime);
    // Add 5 hours 30 minutes for IST (UTC+5:30)
    rawtime += 19800; // 5*3600 + 30*60 = 19800 seconds
    timeinfo = gmtime(&rawtime);
    printf("Algorithm started at (IST): %02d:%02d:%02d\n", 
        timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
}

int main() {
    int size;
    printf("Enter array size: ");
    scanf("%d", &size);

    int *arr = (int *)malloc(size * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    srand((unsigned int)time(NULL));
    for (int i = 0; i < size; i++)
        arr[i] = rand();

    // Print current IST time before sorting
    printCurrentISTTime();

    // Track memory before sort
    size_t memBefore = getCurrentMemoryUsage();

    // Track time before sort
    clock_t start = clock();

    // Sort using InsertionSort
    InsertionSort(arr, size);

    // Track time after sort
    clock_t end = clock();

    // Track memory after sort
    size_t memAfter = getCurrentMemoryUsage();

    double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nTime taken for sorting: %.6f seconds\n", timeTaken);
    printf("Memory used before sort: %zu bytes\n", memBefore);
    printf("Memory used after sort:  %zu bytes\n", memAfter);
    printf("Memory difference:       %zu bytes\n", (memAfter > memBefore) ? (memAfter - memBefore) : (memBefore - memAfter));

    free(arr);
    return 0;
}