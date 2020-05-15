#include "helpers.h"
#include <math.h>
// Here, notice the fact that each function takes a 2D array called image as an argument,
// where image is an array of height many rows, and each row is itself another array of width many RGBTRIPLEs.
// So if image represents the whole picture, then image[0] represents the first row,
// and image[0][0] represents the pixel in the upper-left corner of the image.

// Converts pixel to gray scale
void setgrey(RGBTRIPLE *px)
{
    float average;

    // take the average of the RGB levels
    average = ((*px).rgbtBlue + (*px).rgbtGreen + (*px).rgbtRed) * 0.3333;

    // Set all the properties to the average value
    // Alternatively to the parentesis you could have used an arrow
    (*px).rgbtBlue = roundf(average);
    (*px).rgbtGreen = roundf(average);
    (*px).rgbtRed = roundf(average);
}

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int i, j;
    RGBTRIPLE px;

    // We have to change all the pixels, therefore lets loop over
    // the 2D array of pixels
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            // As the bmp.h file defines, each pixel is a RGBTRIPLE struct
            px = image[i][j];
            // Set every j pixel in the row i to grey
            setgrey(&px);

            image[i][j] = px;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int i, j, d;

    // lets alocate memory for a 1D array that will temporarely hold the mirror version
    RGBTRIPLE row[width];

    // We have to mirror every row in the array, therefore lets loop over
    // the 2D array of pixels
    for (i = 0; i < height; i++)
    {
        // lets copy the ith row
        for (j = width - 1, d = 0; j >= 0; j--, d++)
        {
            row[d] = image[i][j];
        }

        // lets change the ith row copying the RGBTRIPLES backwards
        for (j = 0; j < width ; j++)
        {
            image[i][j] = row[j];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int i, j, du, lr;

    int sum_red, sum_green, sum_blue;
    float average_red, average_green, average_blue, n_px;

    // Create a temporary table of colors to not alter the calculations
    RGBTRIPLE temp[height][width];

    // We have to change all the pixels, therefore lets loop over
    // the 2D array of pixels
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            // number of pixels counted
            n_px = 0.00;

            // reseting sums for the next pixel
            sum_red = sum_green = sum_blue = 0;

            // current pixel image[i][j]

            // Moving only left to right
            for (du = -1; du < 2; du++)
            {
                // in case the serched pixel doesn't exist
                // du stands for down-->up
                if ((i + du > height - 1) || (i + du < 0))
                {
                    continue;
                }


                for (lr = -1; lr < 2; lr++)
                {
                    // in case the serched pixel doesn't exist
                    // lr stands for left-->right
                    if ((j + lr > width - 1) || (j + lr < 0))
                    {
                        continue;
                    }

                    sum_red += (image[i + du][ j + lr]).rgbtRed;
                    sum_green += (image[i + du][j + lr]).rgbtGreen;
                    sum_blue += (image[i + du][j + lr]).rgbtBlue;

                    n_px++;
                }
            }

            temp[i][j].rgbtBlue = roundf(sum_blue / n_px);
            temp[i][j].rgbtGreen = roundf(sum_green / n_px);
            temp[i][j].rgbtRed = roundf(sum_red / n_px);
        }

    }

    //copies values from temporary table
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
        }
    }
    return;
}

// calculate the gradient value for edges function
int get_grad(int GX, int GY)
{
    float grad;

    grad = sqrt(pow(GX, 2) + pow(GY, 2));

    if (grad > 255)
    {
        grad = 255;

    }
    return roundf(grad);
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int i, j, du, lr, sum_red_gy, sum_green_gy, sum_blue_gy, sum_red_gx, sum_green_gx, sum_blue_gx;
    float average_red, average_green, average_blue, n_px;

    // Create a temporary table of colors to not alter the calculations
    RGBTRIPLE temp[height][width];
    // Create a temporary copy pixel
    RGBTRIPLE px_cpy;

    // Initialize the gx and gy kernels
    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] = {{1, 2, 1}, {0, 0, 0}, {-1, -2, -1}};

    // We have to change all the pixels, therefore lets loop over
    // the 2D array of pixels
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            // reseting gradient sums for the next pixel
            sum_red_gx = sum_green_gx = sum_blue_gx = sum_red_gy = sum_green_gy = sum_blue_gy = 0;

            // Moving only left to right
            for (du = -1; du < 2; du++)
            {
                // in case the serched pixel doesn't exist //
                // du stands for down-->up
                if ((i + du > height - 1) || (i + du < 0))
                {
                    // // multiply them each by the corresponding value in the Gx and Gy kernels
                    // // it will be all zero //
                    continue;
                }

                for (lr = -1; lr < 2; lr++)
                {
                    // in case the serched pixel doesn't exist //
                    // lr stands for left-->right
                    if ((j + lr > width - 1) || (j + lr < 0))
                    {
                        // // multiply them each by the corresponding value in the Gx and Gy kernels
                        // // it will be all zero //
                        continue;
                    }
                    // In short, for each of the three color values for each pixel,
                    // we’ll compute two values Gx and Gy.

                    // copy the current pixel
                    px_cpy = image[i + du][ j + lr];

                    // for the matrices gx and gy the 3x3 indexes will be gx[ 1 - du ][ 1 + lr ]
                    // these sums refer to the chanels of the 3x3 square.
                    sum_red_gx += px_cpy.rgbtRed * gx[ 1 - du ][ 1 + lr ];
                    sum_red_gy += px_cpy.rgbtRed * gy[ 1 - du ][ 1 + lr ];

                    sum_green_gx += px_cpy.rgbtGreen * gx[ 1 - du ][ 1 + lr ];
                    sum_green_gy += px_cpy.rgbtGreen * gy[ 1 - du ][ 1 + lr ];

                    sum_blue_gx += px_cpy.rgbtBlue * gx[ 1 - du ][ 1 + lr ];
                    sum_blue_gy += px_cpy.rgbtBlue * gy[ 1 - du ][ 1 + lr ];

                    // To compute Gx for the red channel value of a pixel,
                    // we’ll take the original red, green and blue values for the nine pixels that form a 3x3 box
                    // around the pixel, multiply them each by the corresponding value in the Gx and Gy kernels,
                    // and take the sum of the resulting values.
                }
            }
            // after each of these loops a 3x3 box has been considecounted
            // let's pass the gradient sums: GX and GY

            // takes the copy of the current pixel and sets it to
            // the grad (grandient). The gradient is calculated in get_grad(GX, GY).
            temp[i][j].rgbtBlue = get_grad(sum_blue_gx, sum_blue_gy);
            temp[i][j].rgbtGreen = get_grad(sum_green_gx, sum_green_gy);
            temp[i][j].rgbtRed = get_grad(sum_red_gx, sum_red_gy);
        }
    }

    //copies values from temporary table
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
        }
    }
    return;
    return;
}
