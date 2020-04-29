#include <stdio.h>
#include <cs50.h>
#include <string.h>

//Notice that string.h uses 'string' in the place of const char *'someString'

/* word-counter file */

void word_counter(string text, int *nWords, int *nChars);

void fill_wordArray(int nChars, int nWords, string wordArray[nWords], string text);

/* word-counter file */

int main(void)
{
    /* word-counter file */

    //Gets the text to be analsed
    string text = get_string("Text: ");
    int nWords;
    int nChars;

    word_counter(text, &nWords, &nChars);

    //Prepares an array of words to allocate nWords
    string wordArray[nWords];
    //fills the word Array using the input text as arg
    fill_wordArray(nChars, nWords, wordArray, text);

    for (int j = 0; j < nWords; j++)
    {
        printf("%s \n", wordArray[j]);
    }

    /* word-counter file */

    return 0;
}

/* word-counter file */

//You may assume that any sequence of characters separated
//by spaces should count as a word.
void word_counter(string text, int *nWords, int *nChars)
{
    int len;
    int i = 0;
    int numberOfWords = 1;
    //Gets the lenght of the text (string given)
    len = strlen(text);
    //Loops through every char in string looking for ' ' char
    while (i < len)
    {
        if (text[i] == ' ')
        {
            numberOfWords++;
        }

        i++;
    }

    *nChars = i;

    *nWords = numberOfWords;
}

//Just adds elements to the wordArray
void fill_wordArray(int nChars, int nWords, string wordArray[nWords], string text)
{
    int index = 0;
    //saving the string in &text[0] in a local variable
    string localText = &text[0];

    wordArray[0] = &text[nChars-7];
    wordArray[1] = &text[nChars-10];
    wordArray[2] = &text[nChars-18];
    // for (int i = nChars; i < 0; i--)
    // {
    //     if (localText[i] == ' ')
    //     {
    //         wordArray[index] = &text[i];
    //         printf("%s, %i \n", &text[i], i);
    //         index++;
    //     }
    // }
    // printf("%s, %i \n", &text[nChars-1], nChars);
}

/* word-counter file */