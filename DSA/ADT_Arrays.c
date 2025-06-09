#include <stdio.h>
#include <stdlib.h>

struct ADT_Arrays
{
    int total_size;
    int used_size;
    int *ptr;
};

void create_arr(struct ADT_Arrays *arr, int tsize, int usize)
{
    arr->total_size = tsize;
    arr->used_size = usize;
    arr->ptr = (int *)malloc(tsize * sizeof(int));
}

void display_arr(struct ADT_Arrays *arr)
{
    for (int i = 0; i < arr->used_size; i++)
    {
        printf("%d ", (arr->ptr)[i]);
    }
}

void insert_arr(struct ADT_Arrays *arr)
{
    int val;
    for (int i = 0; i < arr->used_size; i++)
    {
        printf("Enter the array's %d position value: ", i);
        scanf("%d", &val);
        (arr->ptr)[i] = val;
    }
}

int append_arr(struct ADT_Arrays *arr, int val, int index)
{
    if (arr->total_size < index)
    {
        printf("Don't fuck with the Array Structures");
        return -1;
    }
    if (arr->used_size <= index)
    {
        (arr->ptr)[arr->used_size] = val;
        arr->used_size++;
        return 0;
    }

    for (int i = arr->used_size - 1; i >= index; i--)
    {
        (arr->ptr)[i + 1] = (arr->ptr)[i];
    }
    (arr->ptr)[index] = val;
    arr->used_size++;

    return 0;
}

int delete_arr(struct ADT_Arrays *arr, int index)
{
    if (arr->used_size <= index)
    {
        printf("Don't fuck with the Array Structures, No Element Present");
        return -1;
    }

    for (int i = index; i < arr->used_size; i++)
    {
        (arr->ptr)[i] = (arr->ptr)[i + 1];
    }

    arr->used_size--;

    return 0;
}

int main()
{
    int tsize, usize;
    printf("Enter the total size allocation of the array: ");
    scanf("%d", &tsize);
    printf("Enter the usuable size allocation for the array: ");
    scanf("%d", &usize);

    if (tsize < usize)
    {
        printf("Don't fuck with the dynamic memory and Array structures");
        return -1;
    }

    struct ADT_Arrays myArr;
    create_arr(&myArr, tsize, usize);
    insert_arr(&myArr);
    display_arr(&myArr);

    // Append Code
/*     int val, index;
    printf("The value to be inserted into the Array: ");
    scanf("%d", &val);
    printf("The index at which the value is to be inserted into the Array: ");
    scanf("%d", &index);
    append_arr(&myArr, val, index);

    display_arr(&myArr); */

    // Deletion Code
/*     int index;
    printf("Enter the index of the element to be deleted: ");
    scanf("%d", &index);
    delete_arr(&myArr, index);

    display_arr(&myArr); */


    free(myArr.ptr);

    return 0;
}