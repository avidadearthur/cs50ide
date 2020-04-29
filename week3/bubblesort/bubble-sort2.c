// C program for implementation of Bubble sort 
#include <stdio.h> 
  
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  

/* Function to print an array */
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 
  
// Driver program to test above functions 
int main() 
{ 
    int arr[] = {6, 3, 1, 8, 5, 2, 7, 4, 1}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    int i, j; 
    for (i = 0; i < n-1; i++)       
    {
       // Last i elements are already in place    
       for (j = 0; j < n-i-1; j++)  
       {
           if (arr[j] > arr[j+1])
           {
              swap(&arr[j], &arr[j+1]); 
           }
       }
    }
    printf("Sorted array: \n"); 
    printArray(arr, n); 
    return 0; 
} 