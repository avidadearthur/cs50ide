//We will tackle a readability test algoritm based on the Coleman-Liau index.
//This index takes in consideration the average number of letters per 100 words L;
//and the average number of sentences per 100 words S.
//These variables give the index through: index = ( ( 0.0588 * L ) - ( 0.296 * S ) - 15.8 ).
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

//You will need:

/* word-counter file */
//Notice that string.h uses 'string' in the place of const char *'someString'
void counter(string text, int *nWords, int *nLetters, int *nSentences);
/* word-counter file */

/* readability file */
float l_coeficient(int nLetters, int nWords);

float s_coeficient(int nSentences, int nWords);

float calc_index(float S, float L);
/* readability file */

int main(void)
{
    /* word-counter file */
    int nWords = 1;
    int nLetters = 0;
    int nSentences = 0;
    /* word-counter file */
    
    /* word-counter file */
    //Gets the text 
    string text = get_string("Text: ");
    //Counts Words, Letters and Sentences
    counter(text, &nWords, &nLetters, &nSentences);
    /* word-counter file */
    
    /* readability file */
    float L = l_coeficient(nLetters, nWords);
    
    float S = s_coeficient(nSentences, nWords);
    
    float index = calc_index(S, L);
    
    if (((int)roundf(index)) < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (((int)roundf(index)) > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int)roundf(index));
    }
    /* readability file */

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
float l_coeficient(int nLetters, int nWords)
{
    float L = ((float)nLetters / (float)nWords) * 100;
    
    return L;
}

float s_coeficient(int nSentences, int nWords)
{
    float S = ((float)nSentences / (float)nWords) * 100;
    
    return S;
}

float calc_index(float S, float L)
{
    // index = 0.0588 * L - 0.296 * S - 15.8
    float index = ((0.0588 * L) - (0.296 * S) - 15.8);
    
    return index;
}
/* readability file */