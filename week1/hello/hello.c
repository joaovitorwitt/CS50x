#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Asks user for name
    string name = get_string("What is your name? ");

    // Greets the user
    printf("hello, %s\n", name);
}


