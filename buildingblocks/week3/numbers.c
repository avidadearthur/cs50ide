#include <stdio.h>
#include <cs50.h>

// studying algorithms
int main(void)
{
    int numbers[6] = {4, 5, 15, 16, 23, 42};
    // linear search
    for (int i = 0; i < 6; i++)
    {
        if (numbers[i] == 50)
        {
            printf("50 found in %i \n", i);
            return 0;
        }
    }
    printf("50 not found \n");
    return 1;
}