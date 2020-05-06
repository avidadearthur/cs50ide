#include <stdio.h>
#include <stdlib.h>


int main(void)
{

    int *list = malloc(3 * sizeof(int));
    if (list == NULL)
    {
        return 1;
    }

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // saves the comented out lines below
    int *temp = realloc(list, 4 * sizeof(int));
    if (temp == NULL)
    {
        return 1;
    }

    // stupid way
    // int *temp = malloc(4 * sizeof(int));

    // for (int i = 0; i < 4; i++)
    // {
    //   temp[i] = list[i];
    // }

    temp[3] = 9;

    list = temp;

    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    free(list);

    return 0;
}