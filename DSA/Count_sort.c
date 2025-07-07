#include <stdio.h>
#include <stdlib.h>

void printArr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int findMaxima (int* arr, int size) {
    int assumedMax = arr[0];

    for (int i = 0; i < size; i++)
    {
        if (assumedMax < arr[i]) assumedMax = arr[i];
    }

    return assumedMax;    
}

void countSort(int* arr, int size) {
    int maxima = findMaxima(arr, size)+1;

    int* countArr = (int*) calloc(maxima, sizeof(int));
    // printArr(countArr, maxima);
    // printf("%d", maxima);

    for (int i = 0; i < size; i++)
    {
        countArr[arr[i]]++;
    }

    // printArr(countArr, maxima);
    // printf("\n%d\n", countArr[96]);
    // printf("\n%d\n", countArr[98]);
    int j = 0;

    for (int i = 0; i < maxima; i++)
    {
        if (countArr[i] > 0) {
            while (countArr[i] > 0) {
                arr[j++] = i;
                countArr[i]--;
            }
        }
    }
    // printf("\n%d\n", maxima);
    // printArr(countArr, maxima);

    free(countArr);
    
    // printArr(arr, size);
}

int main(){
    int arr[] = {5, 96, 2, 98, 52};
    int size = sizeof(arr)/sizeof(int);
    printArr(arr, size);
    countSort(arr, size);
    printArr(arr, size);

    return 0;
}