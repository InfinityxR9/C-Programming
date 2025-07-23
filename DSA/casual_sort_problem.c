#include <stdio.h>
#include <stdlib.h>

/*
The Casual Sort Problem:
Given an unsorted array, rearrange (sort) the array such that, first element is the largest number followed by smallest number, then second largest followed by second lowest and it goes on.

Algorithm: Using Merge sort to sort the given array and then looping over the array to get the desired rearrangement

Time Complexity: O(n lg n)      (The Most efficient Algorithm for this Problem)
Space Complexity: O(n)
*/

void printArr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int *arr, int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0;

    int *newArr = (int *)malloc(sizeof(int) * (high - low + 1));

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            newArr[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            newArr[k] = arr[j];
            k++;
            j++;
        }
    }

    while (i <= mid)
    {
        newArr[k] = arr[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        newArr[k] = arr[j];
        j++;
        k++;
    }

    // Reinitialise
    i = low;
    k = 0;

    while (i <= high)
    {
        arr[i] = newArr[k];
        i++;
        k++;
    }

    // printf("\nPrinting the current array");
    // printArr(arr, high-low+1);

    free(newArr);
}

void mergeSort(int *arr, int low, int high)
{
    int mid;

    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void casual_sort(int *arr, int size)
{
    mergeSort(arr, 0, size - 1);

    int i = 0, j = size - 1;
    int k = 0;

    int *new_arr = (int *)malloc(size * sizeof(int));

    while (i <= j)
    {
        new_arr[k++] = arr[j--];
        new_arr[k++] = arr[i++];
    }

    i = j = k = 0;

    for (i = 0; i < size; i++, k++)
    {
        arr[i] = new_arr[k];
    }

    free(new_arr);
}

int main()
{
    // int arr[] = {9, 11, 7, 2, 8, 4, 1,6};
    // int size = sizeof(arr) / sizeof(int);

    int size;

    printf("Enter size of array: ");
    scanf("%d", &size);

    int* arr = (int*) malloc(size*sizeof(int));

    for (int i = 0; i < size; i++)
    {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    

    printArr(arr, size);
    // mergeSort(arr, 0, size - 1);
    // printArr(arr, size);
    casual_sort(arr, size);
    printArr(arr, size);

    return 0;
}