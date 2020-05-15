#include <stdio.h>
#include <cs50.h>

void bubble_sort(int arr[], int n);

void swap(int *a, int *b);

int binary_search(int arr[], int low, int high);

int main(void)
{
    // unsorted array example
    int arr[8] = {51, 33, 67, 98, 50, 52, 73, 64};
    // sorted it looks like:
    // {33, 50, 51, 52, 64, 67, 73, 98}
    // {4, 7, 13, 18, 33, 50, 51, 52}

    // simple way of finding arr lenght in
    // scenarios where you don't create it
    int n = sizeof(arr)/sizeof(arr[0]);

    bubble_sort(arr, n);

    printf("Array sorted\n");

    int i = (n)/2;
    int index = binary_search(arr, 0, n - 1);

    if (index == -1)
    {
        printf("Number not found \n");
        return 0;
    }

    printf("Number found at index: %i \n", index);
    return 0;
}

void bubble_sort(int arr[], int n)
{
    // loop over every element
    // notice that  you can move the i++ to the bottom!
    for (int i = 0; i < n - 1; i++)
    {
       // Last i elements are already in place
       for (int j = 0; j < (n - i - 1); j++)
       {
           if (arr[j] > arr[j + 1])
           {
                swap(&arr[j], &arr[j + 1]);
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

// not sure how to implement it with recursion!
int binary_search(int arr[], int low, int high)
{
    // now that we know that the array is
    // sorted but we dont know the numbers inside, neither its lenght

    // low and high define the limits of the current array
    int mid = (low + high) / 2;

    if (low > high)
    {
        return -1;
    }
    // we are looking for the number 50
    if (arr[mid] == 73)
    {
        return mid;
    }

    if (arr[mid] < 73)
    {
        return binary_search(arr, mid + 1, high);
    }

    else
    {
        return binary_search(arr, low, mid-1);
    }
}