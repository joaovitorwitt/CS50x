#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Check for command line args
    if (argc != 2)
    {
        printf("Usage: ./read infile\n");
        return 1;
    }

    // Create buffer to read into
    char buffer[7];

    // Create array to store plate numbers
    char *plates[8];

    FILE *infile = fopen(argv[1], "r");

    int idx = 0;

    while (fread(buffer, 1, 7, infile) == 7)
    {
        // Replace '\n' with '\0'
        buffer[6] = '\0';

        //
        char *license = malloc(strlen(buffer) + 1);

        // copy the license address to buffer
        strcpy(license, buffer);

        // Save plate number in array
        plates[idx] = license;
        idx++;
    }

    for (int i = 0; i < 8; i++)
    {
        printf("%s\n", plates[i]);

        // free memory, plates[i] holds a copy of the pointer
        free(plates[i]);
    }

    // close the file - avoiding memory leaks
    fclose(infile);

    // return 0 - meaning the program ran as expected
    return 0;
}