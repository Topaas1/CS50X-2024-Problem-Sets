#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // prompt for text
    string text = get_string("Text: ");
    
    // calculate number of letters, words and sentences
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
        
    int index = round(0.0588 * ((double)letters / words * 100) - 0.296 * ((double)sentences / words * 100));

    
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letters(string text)
{
    int lettercount = 0;
    for(int i = 0, n = strlen(text); i < n; i++){
        char character = text[i];
        if (isalpha(character)) 
        {
            lettercount++;
        }
    }
    return lettercount;
}

int count_words(string text)
{   
    int wordcount = 1; // always at least one word, eg "car" or "brother-in-law"
    
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        char character = text[i];
        if (isspace(character))
        {
            wordcount++;
        }
    }
    return wordcount;
}

int count_sentences(string text)
{
    int sentencecount = 1;
    
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        char character = text[i];
        if (text[i] == 46 || text[i] == 33 || text[i] == 63)
        {
            sentencecount++;
        }
    }
    return sentencecount;
}
