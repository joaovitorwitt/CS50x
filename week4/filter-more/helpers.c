#include "helpers.h"
#include <math.h>

// prototype
int limit_rgb(int rgb);


// Grayscale, reflection and blur are the same from filter less

// TODO edges


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

// function that limits the value of RGB if is greater than 255;
int limit_rgb(int rgb)
{
    if (rgb > 255)
    {
        rgb = 255;
    }

    return rgb;
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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    double sobelX[9] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
    double sobelY[9] = {-1, -2, -1, 0, 0, 0, 1, 2, 1};

    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // values of color for X and Y
            double redX = 0;
            double greenX = 0;
            double blueX = 0;

            double redY = 0;
            double greenY = 0;
            double blueY = 0;

            int counter = -1;

            for (int row = -1; row <= 1; row++)
            {
                for (int column = -1; column <= 1; column++)
                {
                    counter++;


                    if (i + row < 0 || i + row > height - 1)
                    {
                        continue;
                    }

                    if (j + column < 0 || j + column > width - 1)
                    {
                        continue;
                    }


                    redX += sobelX[counter] * image[i + row][j + column].rgbtRed;
                    redY += sobelY[counter] * image[i + row][j + column].rgbtRed;

                    greenX += sobelX[counter] * image[i + row][j + column].rgbtGreen;
                    greenY += sobelY[counter] * image[i + row][j + column].rgbtGreen;

                    blueX += sobelX[counter] * image[i + row][j + column].rgbtBlue;
                    blueY += sobelY[counter] * image[i + row][j + column].rgbtBlue;
                }
            }

            // calculating the square root and limiting the rgb values
            temp[i][j].rgbtRed = limit_rgb(round(sqrt(redX * redX + redY * redY)));
            temp[i][j].rgbtGreen = limit_rgb(round(sqrt(greenX * greenX + greenY * greenY)));
            temp[i][j].rgbtBlue = limit_rgb(round(sqrt(blueX * blueX + blueY * blueY)));

        }
    }

    // swap the values

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
        }
    }

    return;
}
