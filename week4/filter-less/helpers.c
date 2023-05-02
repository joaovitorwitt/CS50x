#include "helpers.h"
#include <math.h>

// prototypes
int limit_rgb(int rgb);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int blue_amount;
    int green_amount;
    int red_amount;

    // loop through the images height and width
    for (int i = 0; i < height; i ++)
    {
        for (int j = 0; j < width; j++)
        {
            // variables to store the amount of each color
            blue_amount = image[i][j].rgbtBlue;
            green_amount = image[i][j].rgbtGreen;
            red_amount = image[i][j].rgbtRed;

            // calculate the average of the 3 portions of RGB
            int average = round((blue_amount + green_amount + red_amount) / 3.0);

            // assign each portion to the average, hence converting to grayscale
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // calculate sepia value for each instance of color
            // after calculating using the function to limit the RGB
            int sepiaRed = limit_rgb(round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue));
            int sepiaGreen = limit_rgb(round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue));
            int sepiaBlue = limit_rgb(round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue));

            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaRed;
        }
    }

    return;
}

// function that limits the value of RGB if is greater than 255;
int limit_rgb(int rgb)
{
    if (rgb > 255)
    {
        rgb = 255;
    }

    return rgb;
}


// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        // divide the width by 2
        // making sure the we iterate over half of the image
        // swaping the pixels only once
        for (int j = 0; j < width / 2; j++)
        {
            // if width is 10 and the current pixel is 3 (j = 3)
            // need to swap if pixel 6 on the other side of the image
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;

        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // temporary variable for swaping the pixels
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            double red_amount = 0;
            double green_amount = 0;
            double blue_amount = 0;

            double counter = 0;

            // loops to keep track of 3x3 areas
            for (int row = -1; row < 2; row++)
            {
                for (int column = -1; column < 2; column++)
                {
                    // get the 3x3 location
                    if (i + row < 0 || i + row > height - 1)
                    {
                        continue;
                    }

                    // get the 3x3 location
                    if (j + column < 0 || j + column > width - 1)
                    {
                        continue;
                    }

                    red_amount += image[i + row][j + column].rgbtRed;
                    green_amount += image[i + row][j + column].rgbtGreen;
                    blue_amount += image[i + row][j + column].rgbtBlue;

                    counter++;
                }
            }

            // average of all the values in the 3x3 box
            temp[i][j].rgbtRed = round(red_amount / counter);
            temp[i][j].rgbtBlue = round(blue_amount / counter);
            temp[i][j].rgbtGreen = round(green_amount / counter);
        }
    }

    // swap back the pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }

    return;
}
