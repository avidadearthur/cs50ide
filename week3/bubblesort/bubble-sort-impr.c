#include <stdio.h>
#include <cs50.h>

void bubble_sort(int arr[], int n);

void swap(int *a, int *b);

int main(void)
{
    // unsorted array example
    int arr[9] = {1, 1, 2, 3, 5, 4, 7, 8, 6};
    // simple way of finding arr lenght in
    // scenarios where you don't create it
    int n = sizeof(arr)/sizeof(arr[0]);

    bubble_sort(arr, n);

    printf("Array sorted\n");
    return 0;
}

/* improving bubble sort */
// for optimistic situations, bubble sort can be improved

void bubble_sort(int arr[], int n)
{
    // loop over every element
    // notice that  you can move the i++ to the bottom!
    int swapCount = -1;
    while (swapCount != 0)
    {
        swapCount = 0;
        // Last i elements are already in place
        for (int j = 0; j < n; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swapCount++;
            }
        }
        // every thime the  inner loop ends, it means
        // that i elements have gotten to its place!
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}