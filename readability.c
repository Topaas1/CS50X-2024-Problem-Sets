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
    // Prompt for text
    string text = get_string("Text: ");
    
    // Calculate number of letters, words, and sentences
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    
    // Compute Coleman-Liau index
    int index = round(0.0588 * ((float) letters / words * 100) - 0.296 * ((float) sentences / words * 100));
    
    // Print grade level
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
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        char character = text[i];
        if (isalnum(character))  // Check if alphanumeric
        {
            lettercount++;
        }
    }
    return lettercount;
}

int count_words(string text)
{
    int wordcount = 1;
    
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        char character = text[i];
        if (isspace(character)) // Check for whitespace
        {
            wordcount++;
        }
    }
    return wordcount;
}

int count_sentences(string text)
{
    int sentence_count = 0;
    
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        char character = text[i];
        if (character == '.' || character == '!' || character == '?') // Sentence-ending punctuation
        {
            sentence_count++;
        }
    }
    return sentence_count;
}
