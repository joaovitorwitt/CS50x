// Practice working with structs
// Practice applying sorting algorithms

#include <cs50.h>
#include <stdio.h>

#define NUM_CITIES 10

typedef struct
{
    string city;
    int temp;
}
avg_temp;

avg_temp temps[NUM_CITIES];

void sort_cities(void);

int main(void)
{
    temps[0].city = "Austin";
    temps[0].temp = 97;

    temps[1].city = "Boston";
    temps[1].temp = 82;

    temps[2].city = "Chicago";
    temps[2].temp = 85;

    temps[3].city = "Denver";
    temps[3].temp = 90;

    temps[4].city = "Las Vegas";
    temps[4].temp = 105;

    temps[5].city = "Los Angeles";
    temps[5].temp = 82;

    temps[6].city = "Miami";
    temps[6].temp = 97;

    temps[7].city = "New York";
    temps[7].temp = 85;

    temps[8].city = "Phoenix";
    temps[8].temp = 107;

    temps[9].city = "San Francisco";
    temps[9].temp = 66;

    sort_cities();

    printf("\nAverage July Temperatures by City\n\n");

    // loop up to the number of cities and print every city and corresponding temperature
    for (int i = 0; i < NUM_CITIES; i++)
    {
        printf("%s: %i\n", temps[i].city, temps[i].temp);
    }
}

// TODO: Sort cities by temperature in descending order
void sort_cities(void)
{
    // Add your code here

    // selection sort
    // goes through all the array and finds the smallest value and swap this value by the most left value in the array

    for (int i = 0; i < NUM_CITIES; i++)
    {
        // find the smallest value between temp[i] and temp[i - 1]
        // swap smallest value with temp[i]
        int current_index = i;

        // j = i + 1
        // if i is 0 then j is 1 and so on....
        for (int j = i + 1; j < NUM_CITIES; j++)
        {

            // if the condition gives false
            // we are swapping equal values
            if (temps[j].temp > temps[current_index].temp)
            {
                current_index = j;
            }
        }

        // swap code
        int temporary = temps[i].temp;
        temps[i].temp = temps[current_index].temp;
        temps[current_index].temp = temporary;
    }
}
