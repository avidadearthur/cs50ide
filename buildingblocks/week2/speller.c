#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    int lenght = get_int("Set a lenght: ");
    
    string names[lenght];
    for (int i = 0; i < lenght; i++)
    {
        names[i] = get_string("Enter a name: ");    
    }
    
    //printing out names of the list
    for(int i = 0; i < lenght; i++)
    {
        printf("%i: %s \n", i, names[i]);
    }
    //size of will give the number in bites
    int len = sizeof(names)/sizeof(names[0]);
    int index;
    do
    {
        printf("%i \n", len);
        index = get_int("Which name do you want me to spell? Give its idex: ");
    }
    while((index < 0) || (index >= len));
    
    string name = names[index];
    for (int i = 0; name[i] != '\0'; i++)
    {
        //spelling with uppercase
        printf("%i: %c \n", i, toupper(name[i]));
    }
    
    

    
    //Alternatively instead of using the boolean expression "name[i] != '\0'""
    //we could take advantage of the lib string.h and use the function strlen('some string')
    //just make sure of seting strlen to a variable instead of callig it every time inside the loop!
}