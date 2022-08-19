#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int Red;
    int Blue;
    int Green;
    for (int row=0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            Red = image[row][column].rgbtRed;
            Blue = image[row][column].rgbtBlue;
            Green = image[row][column].rgbtGreen;
            float avg = (Red + Blue + Green) / 3.0;
            int newGrey = round(avg);
            image[row][column].rgbtRed = newGrey;
            image[row][column].rgbtBlue = newGrey;
            image[row][column].rgbtGreen = newGrey;
            Red =0;
            Blue=0;
            Green=0;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed;
    int sepiaGreen;
    int sepiaBlue;
    for (int row=0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {

            sepiaRed = round(((0.393 * image[row][column].rgbtRed) + (0.769 * image[row][column].rgbtGreen) + (0.189 * image[row][column].rgbtBlue)));
            sepiaGreen = round((0.349*image[row][column].rgbtRed)+(0.686*image[row][column].rgbtGreen)+(0.168*image[row][column].rgbtBlue));
            sepiaBlue = round((0.272*image[row][column].rgbtRed)+(0.534*image[row][column].rgbtGreen)+(0.131*image[row][column].rgbtBlue));
            if (sepiaRed>255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen>255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue>255)
            {
                sepiaBlue = 255;
            }
            image[row][column].rgbtRed = sepiaRed;
            image[row][column].rgbtBlue = sepiaBlue;
            image[row][column].rgbtGreen = sepiaGreen;


        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copyImage[height][width];
    for (int row=0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            copyImage[row][column].rgbtRed = image[row][column].rgbtRed;
            copyImage[row][column].rgbtBlue = image[row][column].rgbtBlue;
            copyImage[row][column].rgbtGreen = image[row][column].rgbtGreen;
        }
    }
    for (int row=0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            image[row][column].rgbtRed = copyImage[row][abs(column - (width-1))].rgbtRed;
            image[row][column].rgbtBlue = copyImage[row][abs(column - (width-1))].rgbtBlue;
            image[row][column].rgbtGreen = copyImage[row][abs(column - (width-1))].rgbtGreen;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE copyImage[height][width];
    //Creates copy image for reference
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copyImage[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int total_Red, total_Blue, total_Green;
            total_Red = total_Blue = total_Green = 0;
            float counter = 0.00;
            //Look at surrounding pixels
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int currentX = i + x;
                    int currentY = j + y;

                    //check for out of bounds pixels
                    if (currentX < 0 || currentX > (height - 1) || currentY < 0 || currentY > (width - 1))
                    {
                        continue;
                    }

                    //Get the image value
                    total_Red += copyImage[currentX][currentY].rgbtRed;
                    total_Green += copyImage[currentX][currentY].rgbtGreen;
                    total_Blue += copyImage[currentX][currentY].rgbtBlue;

                    counter++;
                }

                //do the average of neigbhouring pexels
                image[i][j].rgbtRed = round(total_Red / counter);
                image[i][j].rgbtGreen = round(total_Green / counter);
                image[i][j].rgbtBlue = round(total_Blue / counter);
            }
            }
    }
    return;
    }