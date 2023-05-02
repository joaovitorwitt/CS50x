#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

const int BLOCK_SIZE = 512;
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{

    // if user inputs more than 2 arguments, the program closes and return 1
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // open input file and check for null
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Something went wrong, could not open file.\n");
        return 1;
    }

    int counter = 0;

    BYTE buffer[BLOCK_SIZE];


    FILE *output = NULL;

    char filename[8];

    while (fread(&buffer, BLOCK_SIZE, 1, input))
    {
        // Checking for jpeg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (counter > 0)
            {
                fclose(output);
            }

            sprintf(filename, "%03i.jpg", counter);
            output = fopen(filename, "w");

            // checking for more errors
            if (output == NULL)
            {
                fclose(input);

                printf("Something went wrong\n");
                return 2;
            }

            counter++;
        }

        // found files
        if (counter > 0)
        {
            fwrite(&buffer, BLOCK_SIZE, 1, output);
        }
    }

    // close files and return 0

    fclose(input);
    fclose(output);

    return 0;


}
