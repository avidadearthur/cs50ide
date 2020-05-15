#include <stdio.h>
#include <cs50.h>

void sort(int arr[], int low, int high);

void merge(int arr[], int low, int middle, int high);

int main(void)
{
    // unsorted array example
    int arr[9] = {6, 3, 1, 8, 5, 2, 7, 4, 1};
    // simple way of finding arr lenght in
    // scenarios where you don't create it
    int n = sizeof(arr)/sizeof(arr[0]);

    int low = 0;
    int high = n - 1;
    sort(arr, low, high);

    printf("Array sorted\n");
    return 0;
}

// In merge sort the idea is to sort smaller arrays
// and then combine those arrays together(merge them)
// in sorted order
void sort(int arr[], int low, int high)
{
    // in merge sort we will use a recursive approach
    /* pseudocode */

    if (high > low)
    {
        // Find the middle point to divide the array into two halves:
        int middle = (low + high)/2;

        // sort the left half
        // Call mergeSort for first half:
        sort(arr, low, middle);

        // sort the right half (if n > 1)
        // new low = (high-low)/2 new high = high

        sort(arr, middle + 1, high);

        // Merge the two halves sorted
        merge(arr, low, middle, high);
    }
}
void merge(int arr[], int low, int middle, int high)
{
    /* create temp arrays */
    // sizes of the temp array
    // temp left array
    int nLeft = (middle - low);
    int arrLeft[nLeft];
    // temp left
    int nRight = (high - (middle+1));
    int arrRight[nRight];

    /* Copy data to temp arrays L[] and R[] */
    for(int i = 0; i < nLeft; i++)
    {
        arrLeft[i] = arr[low + i];
    }

    for(int j = 0; j < nRight; j++)
    {
        arrRight[j] = arr[middle + 1 + j];
    }

    /* Merge the temp arrays back into arr[l..r]*/
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = low; // Initial index of merged subarray

    while(i < nLeft && j < nRight)
    {
        // arr here represents all the
        // sub arr created overtime.
        if (arrLeft[i] <= arrRight[j])
        {
            arr[k] = arrLeft[i];
            i++;
        }
        if (arrLeft[i] >= arrRight[j])
        {
            arr[k] = arrRight[j];
            j++;
        }
        k++;

    }

    /* Copy the remaining elements of arrLeft, if there are any */
    // left sub arrays has left overs
    while (i < nLeft)
    {
        arr[k] = arrLeft[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of arrRight, if there are any */
    // right sub arrays has left overs
    while (j < nRight)
    {
        arr[k] = arrRight[j];
        j++;
        k++;
    }
}