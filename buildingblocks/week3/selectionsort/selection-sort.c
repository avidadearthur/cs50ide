#include <stdio.h>
#include <cs50.h>

void selection_sort(int arr[], int n);

void swap(int *a, int *b);

int main(void)
{
    // unsorted array example
    int arr[9] = {6, 3, 1, 8, 5, 2, 7, 4, 1};
    // simple way of finding arr lenght in
    // scenarios where you don't create it
    int n = sizeof(arr)/sizeof(arr[0]);

    selection_sort(arr, n);

    printf("Array sorted\n");
    return 0;
}

void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[minIndex] > arr[j])
            {
                minIndex = j;
            }
            swap(&arr[minIndex], &arr[i]);
        }
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}