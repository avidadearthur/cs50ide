// Your program must accept a single command-line argument, a non-negative integer,
// If your program is executed without any command-line arguments or with more than one command-line argument,
// your program should print an error message
// Do not assume that k will be less than or equal to 26.

// If k is 27, A should not become [ even though [ is 27 positions away from A in ASCII,
// A should become B, since B is 27 positions away from A, provided you wrap around from Z to A.
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void cipher(string plainText, int key);

int main(int argc, string argv[])
{
    // checks for an argument in the command prompt.
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // checks for non-digits characters in the sKey.
    // sKey stands for the key in const char * type.
    string sKey = argv[1];
    int len = strlen(sKey);

    for (int i = 0; i < len; i++)
    {
        if (!isdigit(sKey[i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    // if all the chars in sKey are digits sKey is turned into an int
    int key = atoi(sKey);
    // printf("Digit: %i \n", key);

    // gets the plain text to be encripted
    string plainText = get_string("plaintext: ");

    // function that encripts the text
    cipher(plainText, key);

    // after cipher function print out ciphert text
    printf("ciphertext:%s\n", plainText);

    return 0;
}

void cipher(string plainText, int key)
{
    int i = 0;
    int len = strlen(plainText);

    while (i < len)
    {
        // $ ./caesar 13
        // plaintext:  be sure to drink your Ovaltine
        // ciphertext: or fher gb qevax lbhe Binygvar


        // 97 --> 122
        if (plainText[i] >= 'a' && plainText[i] <= 'z')
        {
            // ai stands for alphabetical index
            int ai = plainText[i] - 97;

            // the ciphert ascii alphabetical index will be
            // the modulo of the plain text ai plus the key
            // with respect to the lenght of the lowercase alphabetical array
            int cAi = (ai + key) % 26;

            //alphabetical array back to ascii numbers
            plainText[i] = cAi + 97;
        }
        // 65 --> 90
        if (plainText[i] >= 'A' && plainText[i] <= 'Z')
        {
            // ai stands for alphabetical index
            int ai = plainText[i] - 65;

            // the ciphert ascii alphabetical index will be
            // the modulo of the plain text ai plus the key
            // with respect to the lenght of the uppercase alphabetical array
            int cAi = (ai + key) % 26;

            //alphabetical array back to ascii numbers
            plainText[i] = cAi + 65;
        }

        i++;

    }
}
