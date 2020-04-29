#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    string key = get_string(": ");

    int len = strlen(key);

    for (int i = 0; i < len; i++)
    {
        // is alpha in the standard "C" locale,
        // it is equivalent to (isupper(c) || islower(c)).
        if (!isalpha(key[i]))
        {
            printf("Key must contain 26 alphabetic characters.\n");
            return 1;
        }
        // checks if characters appear more than once.
        for (int j = i + 1; j <= len; j++)
            {
                if (key[i] == key[j])
                {
                    printf("Key must contain each letter exactly once.\n");
                    return 1;
                }
            }
    }

    int upperKey[26];
    // uppercase all chars
    for (int i = 0; i < len; i++)
    {
        upperKey[i] = toupper((int)key[i]);
        printf(": %c\n", upperKey[i]);
    }


    int lowKey[26];
    // lowercase all chars
    for (int i = 0; i < len; i++)
    {
        lowKey[i] = tolower((int)key[i]);
        printf(": %c\n", lowKey[i]);
    }


    printf("Success\n");
    return 0;
}