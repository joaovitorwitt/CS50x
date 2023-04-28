#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// index = 0.0588 * L - 0.296 * S - 15.8

// L - average number of letters per 100 words

// S - average number of sentences per 100 words

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{

    string text = get_string("Text: ");

    // Store the values from the functions in variables
    int the_letters = count_letters(text);
    int the_words = count_words(text);
    int the_sentences = count_sentences(text);

    // calculate L typecasting one of the variables before calculating
    float L = the_letters / (float) the_words * 100;

    // calculate S typecasting one of the variables before calculating
    float S = the_sentences / (float) the_words * 100;

    // Formula
    float index = 0.0588 * L - 0.296 * S - 15.8;


    // Conditions
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }

    else
    {
        printf("Grade %.f\n", round(index));
    }

}

int count_letters(string text)
{
    // counter to store number of letters
    int number_of_letters = 0;

    // holds the length of the string
    int n = strlen(text);

    // loop thorugh the string
    for (int i = 0; i < n; i++)
    {
        // if condition true, update the variable
        if (isalpha(text[i]))
        {
            number_of_letters++;
        }
    }

    return number_of_letters;
}

int count_words(string text)
{
    int number_of_words = 1;

    int n = strlen(text);

    for (int i = 0; i < n; i++)
    {
        if (text[i] == ' ')
        {
            number_of_words++;
        }
    }

    return number_of_words;
}

int count_sentences(string text)
{
    int number_of_sentences = 0;

    int n = strlen(text);

    for (int i = 0; i < n; i++)
    {
        if (text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            number_of_sentences++;
        }
    }

    return number_of_sentences;
}