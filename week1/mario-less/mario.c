#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    // Asks a height from the user that is between 1 and 8
    do
    {
        height = get_int("What is the height? ");
    }
    while (height < 1 || height > 8);

    // outer loop for printing new lines
    for (int i = 1; i <= height; i++)
    {
        // loop for printing the spaces
        // they are always equal the current index - 1
        for (int j = 1; j <= height - i; j++)
        {
            printf(" ");
        }

        // loop for printing the hashes
        for (int k = 1; k <= i; k++)
        {
            printf("#");
        }

        printf("\n");
    }
}