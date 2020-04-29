#include <stdio.h>
#include <cs50.h>
#include <string.h>

// comparing strings
int main(void)
{
    string names[3] = {"Rodrigo", "Anne", "Emma"};
    for (int i = 0; i < 3; i++)
    {
        if (strcmp(names[i], "Emma") == 0)
        {
            printf("Emma found in %i \n", i);
            return 0;
        }
    }
    printf("Name not found \n");
    return 1;
}