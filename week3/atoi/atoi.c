#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

// get the index of the last char in the string

// convert the char to its numeric value

// remove the last char by moving the null terminator one position left

// return this value + 10 times the integer of the new shortened string



int convert(string input)
{
    // TODO

    if (strlen(input) == 0)
    {
        return 0;
    }

    // get the last character and convert it to integer

    char last_character = input[strlen(input) - 1] - 48;

    // input = 345 (string)

    // the length == 3

    // input[3 - 1] = input[2]

    // input[2] = '5'; ----- since we are subtracting the value automatically converts to the corresponded integer
    // so we get 53 - 48 = 5 (integer) hence the number we are looking for


    
    // remove the last char of the string
    input[strlen(input) - 1] = '\0';

    return last_character + 10 * convert(input);

}