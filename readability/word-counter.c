#include <stdio.h>
#include <cs50.h>
#include <string.h>

/* word-counter file */

//Notice that string.h uses 'string' in the place of const char *'someString'
void counter(string text, int *nWords, int *nLetters, int *nSentences);

/* word-counter file */

int main(void)
{
    /* word-counter file */
    
    int nWords = 1;
    int nLetters = 0;
    int nSentences = 0;
    
    /* word-counter file */

    //Gets the text 
    string text = get_string("Text: ");
    //Counts Words, Letters and Sentences
    counter(text, &nWords, &nLetters, &nSentences);

    printf("N words: %i, N letters: %i, N sentences %i \n", nWords, nLetters, nSentences);

    /* word-counter file */

    return 0;
}

/* word-counter file */
//You may assume that any sequence of characters separated
//by spaces should count as a word.
void counter(string text, int *nWords, int *nLetters, int *nSentences)
{
    int i = 0;
    int len = strlen(text);
    int numberOfWords = 1;
    int numberOfLetters = 0;
    int numberOfSentences = 0;

    //Loops through every char in string looking for ' ' char
    while (i < len)
    {
        //counts letters
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            numberOfLetters++;
        }
        //counts words
        else if (text[i] == ' ')
        {
            numberOfWords++;
        }
        //counts sentences
        else if ((text[i] == '.') || (text[i] == '!') || (text[i] == '?'))
        {
            numberOfSentences++;
        }
        
        i++;
    }
    
    *nLetters = numberOfLetters;
    *nWords = numberOfWords;
    *nSentences = numberOfSentences;
}
/* word-counter file */