#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

float calc_hours(int hours[], int weeks, char output);

int main(void)
{
    int weeks = get_int("Number of weeks taking CS50: ");
    // size of the array
    int hours[weeks];

    // loop up to the array
    for (int i = 0; i < weeks; i++)
    {
        hours[i] = get_int("Week %i HW Hours: ", i);
    }

    char output;
    do
    {
        output = toupper(get_char("Enter T for total hours, A for average hours per week: "));
    }
    while (output != 'T' && output != 'A');

    printf("%.1f hours\n", calc_hours(hours, weeks, output));
}

// TODO: complete the calc_hours function
float calc_hours(int hours[], int weeks, char output)
{
    // summation of hours
    int total_hours = 0;

    // loop up to number of weeks
    for (int i = 0; i < weeks; i++)
    {
        // update the variable
        total_hours = total_hours + hours[i];
    }

    // conditions
    if (output == 'T')
    {
        return total_hours;
    }

    if (output == 'A')
    {
        return total_hours / (float) weeks;
    }

    return 0;
}