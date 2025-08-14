#include <stdio.h>
#include <stdlib.h>

/*
*Heaps is a data structure based on Complete Binary Trees. There are two types of Heaps:
    Max-Heap: arr[parent] >= all elements in the left and right sub-trees.
    Min-Heap: arr[parent] <= all elements in the left and right sub-trees.

*To get the parent node: return (i - 1)/2
*To get the left child node: return 2i + 1
*To get the right child node: return 2i + 2

Heap Algorithm(s) Complexities:
*Building Max-Heap / Min-Heap (build_max_heap, build_min_heap)
    -Time Complexity:   O(n)
    -Space Complexity:  O(1)
    *In-place operation; no extra space except for recursion stack.

*Heapify (max_heapify, min_heapify)
    -Time Complexity:   O(log n)
    -Space Complexity:  O(log n)

*Heap Sort (heap_sort)
    -Time Complexity: O(n log n)
    *Each extraction is O(log n), repeated n times.
    -Space Complexity: O(1)
*/

typedef struct ADT_Arrays
{
    int size;
    int heap_size;
    int *arr;
} Array;

// Utility function to print the given array
void print_arr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Utility function to create the ADT Array
void create_arr(Array *arr, int size, int hsize)
{
    arr->size = size;
    arr->heap_size = hsize;
    arr->arr = (int *)malloc(size * sizeof(int));
}

// Utility function to insert into the Array via array
void insert_arr(Array *arr, int array[], int size)
{
    if (size <= arr->size)
    {
        for (int i = 0; i < size; i++)
        {
            arr->arr[i] = array[i];
        }
    }
}

void max_heapify(Array *, int);
void min_heapify(Array *, int);

// Builds a Max-Heap, given an array
void build_max_heap(Array *arr)
{
    for (int i = (arr->heap_size / 2) - 1; i >= 0; i--)
    {
        max_heapify(arr, i);
    }
}

// The Max Heapify Algorithm
void max_heapify(Array *arr, int index)
{
    int left_child_index = 2 * index + 1;
    int right_child_index = 2 * index + 2;

    int largest;

    if (arr->arr[index] < arr->arr[left_child_index] && left_child_index < arr->heap_size)
        largest = left_child_index;
    else
        largest = index;

    if (arr->arr[largest] < arr->arr[right_child_index] && right_child_index < arr->heap_size)
        largest = right_child_index;

    if (largest != index)
    {
        int temp;
        temp = arr->arr[largest];
        arr->arr[largest] = arr->arr[index];
        arr->arr[index] = temp;

        max_heapify(arr, largest);
    }
}

// Builds a Min-Heap, given an array
void build_min_heap(Array *arr)
{
    for (int i = (arr->heap_size / 2) - 1; i >= 0; i--)
    {
        min_heapify(arr, i);
    }
}

// The Min Heapify Algorithm
void min_heapify(Array *arr, int index)
{
    int left_child_index = 2 * index + 1;
    int right_child_index = 2 * index + 2;

    int smallest;

    if (arr->arr[index] > arr->arr[left_child_index] && left_child_index < arr->heap_size)
        smallest = left_child_index;
    else
        smallest = index;

    if (arr->arr[smallest] > arr->arr[right_child_index] && right_child_index < arr->heap_size)
        smallest = right_child_index;

    if (smallest != index)
    {
        static int temp;
        temp = arr->arr[smallest];
        arr->arr[smallest] = arr->arr[index];
        arr->arr[index] = temp;

        min_heapify(arr, smallest);
    }
}

// The Heap Sort Algorithm, based on the deletion and max-heapifying of the Heap
void heap_sort(Array *array)
{
    int temp;
    for (int i = array->size - 1; i > 0; i--)
    {
        temp = array->arr[array->heap_size - 1];
        array->arr[array->heap_size - 1] = array->arr[0];
        array->arr[0] = temp;

        array->heap_size--;

        build_max_heap(array);
    }
}

int main()
{
    Array array;
    int uarr[] = {9, 7, 12, 8, 10, 2, 3, 6, 4, 1};
    int hsize, size;
    size = hsize = sizeof(uarr) / sizeof(int);
    create_arr(&array, size, hsize);
    insert_arr(&array, uarr, size);

    // Implementing and Checking the Heaps building algorithms
    print_arr(array.arr, array.size);
    build_max_heap(&array);
    // build_min_heap(&array);
    print_arr(array.arr, array.size);

    heap_sort(&array);
    print_arr(array.arr, array.size);
    printf("The value of heap size is %d\nand size of array is %d\n", array.heap_size, array.size);
    
    // Reinitialise heap_size
    array.heap_size = array.size;
    printf("The value of heap size is %d\nand size of array is %d\n", array.heap_size, array.size);

    free(array.arr);

    return 0;
}