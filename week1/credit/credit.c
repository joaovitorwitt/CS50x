#include <cs50.h>
#include <stdio.h>

// DETAILS

// American Express
// 15 digits
// starts with 34 or 37

// MasterCard
// 16 digits
// starts with 51, 52, 53, 54, 55

// Visa
// 13 or 16 digits
// starts with 4

int main(void)
{

    long credit_card_number;

    // const for the credit card info
    credit_card_number = get_long("What is the credit cards number? ");

    // temporary variable to perform operations
    long temp_card = credit_card_number;

    // store the number of digits
    long number_digits = 0;

    long first_digit = temp_card;

    long first_two_digits = temp_card;

    long last_digit;

    long total = 0;


    while (temp_card > 0)
    {
        // get the last digit
        last_digit = temp_card % 10;

        // update the total - at first is 0
        total = total + last_digit;

        // divides the card number by 100 so it gives the number after next
        temp_card = temp_card / 100;
    }


    // operation to starts the function at the second to last digit
    temp_card = credit_card_number / 10;

    while (temp_card > 0)
    {
        // gets the last digit
        last_digit = temp_card % 10;

        // multiplies the last digit by 2
        long times_two = last_digit * 2;

        // this is for when the number has two digits - we separated the number and increment the digits
        total = total + (times_two % 10) + (times_two / 10);

        // divide the credit card number so it gives the number after next
        temp_card = temp_card / 100;
    }

    // Get length of the card
    while (credit_card_number != 0)
    {
        // every time we divide the number by 10 we increment the number of digits variable
        credit_card_number = credit_card_number / 10;
        number_digits++;
    }

    // Get first digit
    while (first_digit >= 10)
    {
        first_digit = first_digit / 10;
    }

    // Get first two digits
    while (first_two_digits >= 100)
    {
        first_two_digits = first_two_digits / 10;
    }


    if (total % 10 == 0)
    {
        if ((number_digits == 13 || number_digits == 16) && first_digit == 4)
        {
            printf("VISA\n");
        }
        else if (number_digits == 16 && (first_two_digits > 50 && first_two_digits < 56))
        {
            printf("MASTERCARD\n");
        }
        else if (number_digits == 15 && (first_two_digits == 34 || first_two_digits == 37))
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

}