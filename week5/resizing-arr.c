#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //very very ineficient
    int i,j;
    int oldarr[] = {1,2,3,4,7};
    int newel[] = {4,5,6};

    int newlenght, pluslenght, oldlenght;
    pluslenght = (sizeof(oldarr)/sizeof(int));
    oldlenght = (sizeof(newel)/sizeof(int));
    newlenght = oldlenght + pluslenght;

    int newarr[newlenght];

    for (i = 0; i < oldlenght ; i++)
    {
        newarr[i] = oldarr[i];
    }

    for (i = oldlenght, j = 0; i < newlenght; i++, j++)
    {
        newarr[i] = newel[j];
    }

    for (i = 0; i < newlenght; i++)
    {
        printf("%i\n", newarr[i]);
    }

    return 0;
}