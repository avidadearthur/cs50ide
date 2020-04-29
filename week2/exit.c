//By default the main function has 0 as its return value
//We can make conditional operators inside the main func
//return other values than  0 in case an error occurs, for example.
#include <stdio.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    //if a command line argument is missing
    //or if the number of arguments is wrong
    if (argc != 2)
    {
        printf("Command line argument error\n");
        printf("This program requires your name as an argument vector to run\n");
        return 1;
    }
    if (argc == 2)
    {
        printf("Hello, %s \n", argv[1]);
    }
}
