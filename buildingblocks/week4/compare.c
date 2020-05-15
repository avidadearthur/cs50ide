#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    // comparing strings is not possible
    // bacause you would be technically comparing

    // get_sting indeed returns to the pointer char *p
    // the address it separated for an array of chars

    char *s = get_string("s: ");
    
    int n = strlen(s);
    // memory allocation for an string input
    char *t = malloc(n + 1);
    
    // instead of this loop you could simply use strcpy(char *s, )
    for (int i = 0; i <= n; i++)
    {
        t[i] = s[i];
    }

    t[0] = toupper(t[0]);

    printf("%s\n", t);
    printf("%s\n", s);
    
    free(t);
}