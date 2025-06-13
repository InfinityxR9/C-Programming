#include <stdio.h>

int linear_search(int arr[], int value, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
            return i;
    }

    return -1;
}

int binary_search(int arr[], int value, int size)
{
    int low = 0, high = size - 1;
    
    while (low <=high){
        int mid = (low + high) / 2;
        printf("I'm inside while loop");
        if (arr[mid] > value) high = mid;
        if (arr[mid] < value) low = mid;
        if (arr[mid] == value) return mid;
    }
}

int main()
{
    int arr[] = {5,6,10,59,62,95};
    int size = sizeof(arr) / sizeof(int);
    // int index = linear_search(arr, 59, size);
    // printf("The index of first occurance is: %d", index);

    // Binary searching
    int index = binary_search(arr, 59, size);
    printf("The index of first occurance is: %d", index);

    return 0;
}