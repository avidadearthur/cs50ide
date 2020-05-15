#include <stdio.h>
#include <cs50.h>
#include <string.h>

//Instead of seting the main function
//desprovided of any argument (void)
//From now on you can set the main function to receive arguments
// more specificaly an argument vector (argv[]) (of string type) of
//argument counter elements lenght (argc)
int main(int argc, string argv[])
{
    //We can take, for instance, the second word
    //at the command promt as an argument
    if (argc == 2)
    {
        //And get the arg vector [1], [2], etc ...
        printf("Hello, %s \n", argv[1]);
    }
    else
    {
        printf("No value was added to the argument vector number 1\n");
    }
        
}