#include <stdio.h>
#include <cs50.h>

//fills an array of a given lenght
int fill_arr(int lenght);

//averaging the values from an array
float average(int lenght, int array[]);

int main(void)
{
    //set lenght
    int n_elements;
    n_elements = get_int("Set the number of elements of the array: ");

    //fill array
    //We still need to build an array inside the main function
    //cause you don't know yet how to pass an array through functions
    int arr[n_elements];
    for (int i = 0; i < n_elements; i++)
    {
        arr[i] = get_float("Enter an element %i: ", i + 1);
    }

    printf("Average: %.2f \n", average(n_elements, arr));
}

float average(int lenght, int array[])
{
    //sum of elements
    int sum = 0;
    for (int j = 0; j < lenght; j++)
    {
        sum += array[j];
    }

    float av = (float)sum/(float)lenght;
    return av;
}