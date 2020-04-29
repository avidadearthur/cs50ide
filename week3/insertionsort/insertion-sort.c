#include <stdio.h>
#include <cs50.h>

void insertion_sort(int arr[], int n);

int main(void)
{
    // unsorted array example
    int arr[9] = {6, 3, 1, 8, 5, 2, 7, 4, 1};
    // simple way of finding arr lenght in
    // scenarios where you don't create it
    int n = sizeof(arr)/sizeof(arr[0]);

    insertion_sort(arr, n);

    printf("Array sorted\n");
    return 0;
}


// Function to sort an array using insertion sort
void insertion_sort(int arr[], int n)
{
    int i;
    int key;
    int j;

    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1], that are
        // greater than key, to one position ahead
        // of their current position

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        // if arr[1] > arr[0] the first for loop
        // starts here
        arr[j + 1] = key;

    }

}

