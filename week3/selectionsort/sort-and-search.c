#include <stdio.h>
#include <cs50.h>
#include <math.h>

// studying algorithms
// bubble sorting before binary searching
int main(void)
{
    // bubble sorting the number array below
    int j = 0;

    int numbers[9] = {16, 50, 4, 15, 13, 3, 4, 49, 1};

    while (j < (9 - 1))
    {
        if (numbers[j] > numbers[j + 1])
        {
            // for all the pairs
            while (j < (9 - 1))
            {
                if (numbers[j] > numbers[j + 1])
                {
                    // swap numbers
                    int currentNumberCopy = numbers[j];
                    int nextNumberCopy = numbers[j + 1];
                    numbers[j] = nextNumberCopy;
                    numbers[j + 1] = currentNumberCopy;
                }
                // compare with the next
                j++;
            }
            // comapare the first again
            j = 0;
        }
        else
        {
            j++;
        }
    }

    printf("Array sorted \n");
    // now that our array is sorted
    // we could either do a linear search or do 
    // a binary search
    
    // let's assume we know that the array is
    // sorted but we dont know the numbers inside, neither its lenght
    int len = sizeof(numbers)/sizeof(numbers[0]);
    printf("lenght: %i \n", len);
    int i = (len)/2;
    printf("middle index: %i \n", i);
    // we are looking for the number 50 
    while (numbers[i] != 50)
    {
        if (numbers[i] < 50)
        {
            i += (len - i)/2;
        }
    }
    printf("Number founded at index %i \n", i);
    return 0;
}