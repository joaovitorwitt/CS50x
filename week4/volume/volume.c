// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }


    float factor = atof(argv[3]);

    // Write the header to the output file
    // Repeat for each 2 BYTES samples
    // read the sample from input file
    // multiply the sample value by the volume factor
    // write the new sample to the output file

    // uint8_t - unsigned integer 8 bits or 1 BYTE
    // int16_t - 2 BYTES


    // TODO: Copy header from input file to output file

    // header array type unsigned integer 8 bits (1 BYTE)
    // 44 BYTES for the header
    uint8_t header[HEADER_SIZE];

    // store 2 BYTES
    int16_t buffer;


    // Read the header from the input file
    fread(header, HEADER_SIZE, 1, input);

    // write the information into the output file
    fwrite(header, HEADER_SIZE, 1, output);


    // TODO: Read samples from input file and write updated data to output file

    while (fread(&buffer, sizeof(int16_t), 1, input))
    {
        buffer = buffer * factor;
        fwrite(&buffer, sizeof(int16_t), 1, output);
    }


    // Close files
    fclose(input);
    fclose(output);
}