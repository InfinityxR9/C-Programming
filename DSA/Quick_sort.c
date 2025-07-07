#include <stdio.h>

void printArr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int *arr, int low, int high)
{
    int pivot = low;
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (arr[pivot] >= arr[i])
        {
            i++;
        }

        while (arr[pivot] < arr[j])
        {
            j--;
        }

        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);

    temp = arr[j];
    arr[j] = arr[pivot];
    arr[pivot] = temp;

    return j;
}

void quickSort(int *arr, int low, int high)
{

    int partitionIndex;

    if (low < high)
    {
        partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}

int main()
{
    int arr[] = {5, 96, 2, 98, 52};
    int size = sizeof(arr) / sizeof(int);
    printArr(arr, size);
    quickSort(arr, 0, size - 1);
    printArr(arr, size);

    return 0;
}