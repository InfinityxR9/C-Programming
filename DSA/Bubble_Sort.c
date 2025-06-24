#include <stdio.h>

void printArr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp;
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }

        printf("Terminating in %d iterations", i + 1);
    }
}

void bubbleSortAdaptive(int *arr, int size)
{
    int isSorted = 0;

    for (int i = 0; i < size - 1; i++)
    {
        isSorted = 1;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp;
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSorted = 0;
            }
        }

        if (isSorted)
        {
            printf("Terminating in %d iterations", i + 1);
            break;
        }
    }
}

int main()
{
    int arr[] = {5, 96, 2, 98, 52};
    int size = 5;
    printArr(arr, size);
    bubbleSortAdaptive(arr, size);
    printArr(arr, size);

    return 0;
}