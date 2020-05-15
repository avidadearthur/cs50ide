#include <stdio.h>

typedef char *string;

int main(void)
{
    // when we assign what we conventioned as string
    // is actualy a pointer to an address in memory
    // where the first letter of an array of chars is stored
    // string stands for char *s or char *p etc ...
    string s = "string";
    
    printf("%s\n", s);
    printf("%p\n", s);
    printf("%p\n", &s[0]);
    printf("%p\n", &s[3]);
    printf("%c\n", s[3]);
}