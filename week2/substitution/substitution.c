#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{


    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    int argv_length = strlen(argv[1]);

    if (argv_length != 26)
    {
        printf("Key must be 26 characters\n");
        return 1;
    }

    for (int m = 0; m < argv_length; m++)
    {
        if (!isalpha(argv[1][m]))
        {
            printf("Invalid characters\n");
            return 1;
        }

        for (int k = m + 1; k < argv_length; k++)
        {
            if (argv[1][m] == argv[1][k])
            {
                printf("Repeated characters are not allowed!\n");
                return 1;
            }
        }
    }

    string key = argv[1];


    string plaintext = get_string("plaintext: ");

    int n = strlen(plaintext);
    int current_index;


    printf("ciphertext: ");

    for (int i = 0; i < n; i++)
    {
        if (isupper(plaintext[i]))
        {
            current_index = plaintext[i] - 65;
            printf("%c", toupper(key[current_index]));
        }

        else if (islower(plaintext[i]))
        {
            current_index = plaintext[i] - 97;
            printf("%c", tolower(key[current_index]));
        }

        else
        {
            printf("%c", plaintext[i]);
        }
    }

    printf("\n");

    return 0;
}