#include <stdio.h>
#include <cs50.h>

//Gets lenght of your array
int ask_lenght(void);
//Fills the array allocated inside of the main()
//considering its lenght n and a reference of its existence
void fill_array(int n, int array[n]);
//Gets an array and its lenght and prints it
void print_array(int n, int array[n]);

int main(void)
{
    int n = ask_lenght();
    //Then you can allocate memory in your main function
    //for an array of n that will be build somewhere else
    int array[n];
    //Gets a lenght 'n' and an array and fills it
    fill_array(n, array);
    //after this function runs the variable called array
    //has been modified and you can pass it as an argument i guess
    print_array(n, array);
    
    return 0;
}

int ask_lenght(void)
{
    int n;
    
    do
    {
        n = get_int("Set a lenght: ");
    }
    while(n<=0);

    return n;
}

void fill_array(int n, int array[n])
{
    //from now on you will be altering the array
    //defined inside the main function
    for(int i = 0; i < n; i++)
    {
        array[i] = get_int("Enter an element: ");
    }
}

void print_array(int n, int array[n])
{
    printf("Here is the array: \n");
    
    for(int i = 0 ; i < n ; i++)
    { 
        printf("%d \n", array[i]); 
    }
 
}