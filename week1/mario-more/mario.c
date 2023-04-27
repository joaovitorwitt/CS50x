#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    // Asks the use for a height greater than 1 and less than 9
    do
    {
        height = get_int("What is the height? ");
    }
    while (height < 1 || height > 8);

    // loop that prints a new line everytime
    for (int i = 1; i <= height; i++)
    {
        // loop that prints the whites spaces accordingly with the hashes at the beginning of the pyramid
        for (int j = 1; j <= height - i; j++)
        {
            printf(" ");
        }

        // loop for printing the hashes of the first pyramid
        for (int k = 1; k <= i; k++)
        {
            printf("#");
        }

        // prints the vertical white space in the middle of both pyramids
        for (int m = 1; m < 2; m++)
        {
            printf("  ");
        }

        // prints the second pyramid
        for (int n = 1; n <= i; n++)
        {
            printf("#");
        }
        printf("\n");
    }
}