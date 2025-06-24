#include <stdio.h>

void printArr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int* arr, int size) {
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

int main(){
    int arr[] = {5, 96, 2, 98, 52};
    int size = sizeof(arr)/sizeof(int);
    printArr(arr, size);
    insertionSort(arr, size);
    printArr(arr, size);

    return 0;
}