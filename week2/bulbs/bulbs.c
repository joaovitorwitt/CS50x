#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // Gets a string from the user
    string quote = get_string("What is the quote of the day? ");

    // Stores the length of the string
    int n = strlen(quote);


    for (int i = 0; i < n; i++)
    {
        // array that will be printed containing 8 elements
        int binary[] = {0, 0, 0, 0, 0, 0, 0, 0};
        //
        int j = 0;

        // converts the char to a integer
        int char_to_int = quote[i];

        // if the integer is greater than zero then...
        while (char_to_int > 0)
        {
            // when j is 0
            // binary[0] = 72 % 2;
            // binary[0] = 0;
            binary[j] = char_to_int % 2;
            // 72 = 72 / 2
            // now char_to_int is 36;
            char_to_int = char_to_int / 2;
            // and now j is 1;
            j++;

        }

        // revert the array
        // now k = 8 - 1
        // k = 7

        // if k is 7, then we are printing the last element from the array first and so on until the array is completely reversed
        for (int k = BITS_IN_BYTE - 1; k >= 0; k--)
        {
            print_bulb(binary[k]);
        }

        printf("\n");
    }

}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
