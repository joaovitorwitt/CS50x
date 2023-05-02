#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing

    // loop through the height
    for (int i = 0; i < height; i++)
    {
        // loop thorugh the width
        for (int j = 0; j < width; j++)
        {

            // checking every pixel for dark values
            if (image[i][j].rgbtBlue == 0x00 && image[i][j].rgbtGreen == 0x00 && image[i][j].rgbtRed == 0x00)
            {
                // changing the pixels to blue
                image[i][j].rgbtBlue = 0xff;
            }

        }
    }
}