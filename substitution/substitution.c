// In a substitution cipher, we “encrypt” (i.e., conceal in a reversible way)
// a message by replacing every letter with another letter. To do so, we use a key:
// in this case, a mapping of each of the letters of the alphabet
// to the letter it should correspond to when we encrypt it. To “decrypt” the message,
// the receiver of the message would need to know the key, so that they can reverse the process:
// translating the encrypt text (generally called ciphertext) back into the original message (generally called plaintext).

// If k is 27, A should not become [ even though [ is 27 positions away from A in ASCII,
// A should become B, since B is 27 positions away from A, provided you wrap around from Z to A.
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// A 26-character key starting with NQ... means that A (the first letter of the alphabet)
// should be converted into N (the first character of the key), B (the second letter of the alphabet)
// should be converted into Q (the second character of the key), and so forth.
void cipher(string plainText, string key);

int main(int argc, string argv[])
{
    // checks for an argument in the command prompt.
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    //checks for the lenght of the entered arg
    string key = argv[1];
    int len = strlen(key);

    if (len != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // checks if all the chars are alphabetic characters;
    // checks if characters appear more than once.
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
    // if all the chars in key are alphabetic characters
    // gets the plain text to be encripted
    string plainText = get_string("plaintext: ");

    // function that encripts the text
    cipher(plainText, key);

    printf("ciphertext: %s\n", plainText);
    return 0;
}

void cipher(string plainText, string key)
{
    int i = 0;
    int j = 0;
    int lenKey = strlen(key);
    int lenPlainText = strlen(plainText);
    // uppercase and lowercase alphabetic index arrays

    int upperKey[26];
    // uppercase all chars
    for (i = 0; i < lenKey; i++)
    {
        upperKey[i] = toupper((int)key[i]);
    }

    int lowKey[26];
    // lowercase all chars
    for (i = 0; i < lenKey; i++)
    {
        lowKey[i] = tolower((int)key[i]);
    }

    // looping through plain text
    while (j < lenPlainText)
    {
        // 97 --> 122
        if (plainText[j] >= 'a' && plainText[j] <= 'z')
        {
            // printf("Before: %c\n", plainText[j]);

            // ai stands for alphabetical index
            int ai = plainText[j] - 97;

            // the ciphert new ascii index will be
            // the equal the the ascii index of the ith key
            // inside the lowercase alphabetical array
            plainText[j] = lowKey[ai];
            // printf("After: %c\n", plainText[j]);
        }
        // 65 --> 90
        if (plainText[j] >= 'A' && plainText[j] <= 'Z')
        {
            // printf("Before: %c\n", plainText[j]);

            // ai stands for alphabetical index
            int ai = plainText[j] - 65;

            // the ciphert new ascii index will be
            // the equal the the ascii index of the ith key
            // inside the upperercase alphabetical array
            plainText[j] = upperKey[ai];
            // printf("After: %c\n", plainText[j]);
        }

        j++;
    }
}
