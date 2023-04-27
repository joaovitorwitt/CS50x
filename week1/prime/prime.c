#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

// PRIME NUMBERS
// only factores are 1 and itself

bool prime(int number)
{

    // by definition 1 is not a prime number
    // so we start at 2
    for (int i = 2; i < number; i++)
    {
        // if there is no remainder the number has more factors
        if (number % i == 0)
        {
            return false;
        }

    }

    return true;

}
