#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


// Prototypes
bool only_digits(string s);
char rotate(char c, int n);


int main(int argc, string argv[])
{

    // if the user types more than two arguments or there is non-numeric value the program exits
    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // convert the string to an integer
    // this will be the number of places we are going to rotate the character
    int string_to_int = atoi(argv[1]);

    // get the plaintext from the user
    string plaintext = get_string("plaintext: ");

    int n = strlen(plaintext);

    printf("ciphertext: ");

    for (int i = 0; i < n; i++)
    {
        rotate(plaintext[i], string_to_int);
    }

    printf("\n");

    return 0;
}


bool only_digits(string s)
{
    int n = strlen(s);

    bool is_digit = true;

    // loop through all the characters from the string
    // if there is a digit return false
    for (int i = 0; i < n; i++)
    {
        if (isalpha(s[i]))
        {
            is_digit = false;
        }
    }

    if (!is_digit)
    {
        return false;
    }


    return true;
}

char rotate(char c, int n)
{

    // if the char is uppercase we need to subtract 65 from the ASCII code
    // then increment in the ASCII code the value of the key
    char temp = c;

    if (isupper(temp))
    {
        int char_to_int = (((temp - 65) + n) % 26) + 65;

        char int_to_char = char_to_int;

        printf("%c", int_to_char);
    }

    if (islower(temp))
    {
        int char_to_int = (((temp - 97) + n) % 26) + 97;

        char int_to_char = char_to_int;

        printf("%c", int_to_char);
    }

    if (isblank(temp))
    {
        printf("%c", temp);
    }

    if (!isalnum(temp) && !isblank(temp))
    {
        printf("%c", temp);
    }

    // if the char is lowercase we need to subtract 97 from the ASCII code
    // if the char is A now the ASCII code is 0
    // then increment int the ASCII code the value of the key
    // if the ASCII code is 3
    // then the ASCII value of A is now 3
    // after that, we perform the modulo operation
    // this way if the user inputs a key that is larger than the length of the alphabet
    // we can loop back to the correct number
    // lets say the character is A and the key is 27
    // the ASCII of A is 65
    // A = 65
    // 65 - 65 = 0
    // A = 0
    // key = 27
    // A = A + 27
    // A = 27
    // A % 26 = 1
    // A = A + 65
    // A = 66
    // the ASCII of 66 is B

    return 0;

}