// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    // set every case to false
    bool has_lowercase = false;
    bool has_uppercase = false;
    bool has_number = false;
    bool has_symbol = false;

    int n = strlen(password);

    // iterate through the string
    for (int i = 0; i < n; i++)
    {
        // if this condition true set the variable to true
        if (islower(password[i]))
        {
            has_lowercase = true;
        }

        
        if (isupper(password[i]))
        {
            has_uppercase = true;
        }

        if (isdigit(password[i]))
        {
            has_number = true;
        }

        if (!isalnum(password[i]))
        {
            has_symbol = true;
        }
    }

    if (has_number && has_symbol && has_lowercase && has_uppercase)
    {
        return true;
    }

    return false;
}
