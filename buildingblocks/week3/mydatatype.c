#include <stdio.h>
#include <cs50.h>
#include <string.h>

// creating a container for mutiple data types
typedef struct
{
    string name;
    string number;
}
person;

// searching for people in phone numbers
int main(void)
{
    person people[4];

    people[0].name = "David";
    people[0].number = "167-555-0100";

    people[1].name = "Rodrigo";
    people[1].number = "167-555-0101";

    people[2].name = "Brian";
    people[2].number = "167-555-0102";

    people[3].name = "Emma";
    people[3].number = "167-555-0103";

    for (int i = 0; i < 4; i++)
    {
        if (strcmp(people[i].name, "Emma") == 0)
        {
        // assuming the name and the number will have the same index
        printf("%s : %s \n",people[i].name, people[i].number);
        return 0;
        }
    }
    printf("Name not found");
    return 1;
}