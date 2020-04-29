#include <stdio.h>

int main(void)
{
    int i = 50;
    // pointer is a variable that will contain the
    // address of an integer
    int *pointer = &i;
    // whereas '&' means the address in memory '*' goes to the address
    // of the variable
    printf("%p\n", &i);
    printf("%d\n", *&i);

    //printing the pointer
    printf("%p\n", pointer);
    printf("%d\n", *pointer);
    // you won't be able to store addresses in integers
}