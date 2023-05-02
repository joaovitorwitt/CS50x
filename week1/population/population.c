#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start_population;

    do
    {
        // get the intial population from the user
        start_population = get_int("What is the initial population? ");
    }
    // keep asking for the inital population while the value is less than 9
    // if the initital population is greater than 9 we break out of the loop
    while (start_population < 9);

    // TODO: Prompt for end size

    int end_population;

    do
    {
        // get the final population from the user
        end_population = get_int("What is the ending population? ");
    }
    // keep asking while the value is less than the initial population
    // when the end population is greater than the initial population we break out of the loop
    while (end_population < start_population);

    // TODO: Calculate number of years until we reach threshold

    int n = 0;

    int llamas_born;
    int llamas_pass;

    if (start_population == end_population)
    {
        printf("Years: %i\n", n);
    }

    else
    {
        do
        {
            llamas_born = start_population / 3;
            llamas_pass = start_population / 4;
            start_population = llamas_born - llamas_pass + start_population;
            n++;
        }
        while (start_population < end_population);
    }


    // TODO: Print number of years
    printf("Years: %i\n", n);
}
