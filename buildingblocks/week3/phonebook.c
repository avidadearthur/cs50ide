#include <stdio.h>
#include <cs50.h>
#include <string.h>

// searching for people in phone numbers
int main(void)
{
    string names[4] = {"Emma","Rodrigo","Brian","David"};
    string numbers[4] = {"167-555-0100","167-555-0101","167-555-102","617-555-0103"};
    for (int i = 0; i < 4; i++)
    {
        if (strcmp(names[i], "Emma") == 0)
        {
        // assuming the name and the number will have the same index
        printf("%s \n", numbers[i]);
        return 0;
        }
    }
    printf("Name not found");
    return 1;
}