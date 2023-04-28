// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace(string word);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./no-vowels word\n");
        return 1;
    }

    printf("Output: %s\n", replace(argv[1]));
}

// function that will replace the vowels for numbers
string replace(string word)
{
    // the lenght of the string
    int n = strlen(word);

    // loop through the string
    for (int i = 0; i < n; i++)
    {
        // Check every possible scenario
        switch (word[i])
        {
            case 'a':
                word[i] = '6';
                break;

            case 'e':
                word[i] = '3';
                break;

            case 'i':
                word[i] = '1';
                break;

            case 'o':
                word[i] = '0';
                break;

            default:
                break;
        }
    }

    return word;

}