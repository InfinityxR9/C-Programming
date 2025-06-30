#include <stdio.h>

void printArr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int* arr, int size) {
    int minIndex;
    int temp;
    for (int i = 0; i < size; i++)
    {
        minIndex = i;

        for (int j = i+1; j < size; j++)
        {
            if (arr[j] < arr[minIndex]) minIndex = j;
        }

        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

int main(){
    int arr[] = {5, 96, 2, 98, 52};
    int size = sizeof(arr)/sizeof(int);
    printArr(arr, size);
    selectionSort(arr, size);
    printArr(arr, size);

    return 0;
}