#include <stdio.h>

/*
Incorporating Binary Search Algorithm in Insertion Sort to enhance the running time complexity.
*/

void printArr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int binary_search(int *arr, int low, int high, int key)
{
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return low;
}

void insertionSort(int *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];

        int location = binary_search(arr, 0, i - 1, key);
        int j = i - 1;

        while (j >= location)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[location] = key;
    }
}

int main()
{
    int arr[] = {5, 96, 2, 98, 52};
    int size = sizeof(arr) / sizeof(int);
    printArr(arr, size);
    insertionSort(arr, size);
    printArr(arr, size);

    return 0;
}