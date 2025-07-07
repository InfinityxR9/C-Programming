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

void merge(int* arr, int low, int mid, int high) {
    int i = low, j = mid+1, k=0;

    int* newArr = (int*) malloc(sizeof(int)*(high-low+1));

    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            newArr[k] = arr[i];
            k++;
            i++;
        } 
        else{
            newArr[k] = arr[j];
            k++;
            j++;
        }
    }

    while (i <= mid) {
        newArr[k] = arr[i];
        i++;
        k++;
    }

    while (j <= high) {
        newArr[k] = arr[j];
        j++;
        k++;
    }

    // Reinitialise
    i = low;
    k = 0;

    while(i <= high){
        arr[i] = newArr[k];
        i++;
        k++;
    }

    printf("\nPrinting the current array");
    printArr(arr, high-low+1);

    free(newArr);
}

void mergeSort(int* arr, int low, int high) {
    int mid;

    if (low < high) {
        mid = (low+high)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

int main(){
    int arr[] = {9,11,7,2,8,4,1};
    int size = sizeof(arr)/sizeof(int);
    printArr(arr, size);
    mergeSort(arr, 0,size-1);
    printArr(arr, size);

    return 0;
}