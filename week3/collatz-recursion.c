#include <stdio.h>
#include <cs50.h>

int collatz(int n);

int main(void)
{
    int n = get_int("N: ");

    int i = collatz(n);

    printf("N steps: %i \n", i+1);

    return 0;
}


int collatz(int n)
{
    if (n == 1)
    {
        return 0;
    }
    // even n's
    else if (n % 2 == 0)
    {

        return 1 + collatz(n/2);
    }

    //odd n's
    else 
    {
        return 1 + collatz((3 * n) + 1);
    }
}