#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main(int argc, char *argv[])
{
    // Remember file name using a pointer
    char *filename = argv[1];

    // Ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: name of the forensic image e.g.'card.raw'\n");
        return 1;
    }

    // Open input file using the  pointer inptr
    FILE* fileptr = fopen(filename, "r");

    if (fileptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", filename);
        return 1;
    }

    // start to read the opened file looking for the begining of a JPG
    // number of jpgs already found and number of memory chunks
    FILE* img = NULL;

    // number of jpgs already found and number of memory chunks
    int n_jpg = 0;
    bool is_open = false;

    // initializing buffer
    unsigned char buffer[512];

    // read until looping through all elements
    // fread will return 1 (true) util it gets
    // to the end of the file and returns 0
    while (fread(buffer, 512, 1, fileptr))
    {
        // check the first 3 bytes of the buffer looking for jpg signature in the file headers
        // if true, go and check all the 16 optons for the 4th byte
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // its a jpg, open a new file
            // is it the first?
            if (n_jpg == 0)
            {
                // new file for name for writing the jpg's
                char newfilename[8];

                sprintf(newfilename, "%03i.jpg", n_jpg);
                img = fopen(newfilename, "w");
                is_open = true;

                if (img == NULL)
                {
                    fclose(fileptr);
                    free(buffer);
                    fprintf(stderr, "Could not create %s", newfilename);

                    return 1;
                }

                n_jpg++;

                fwrite(buffer, 512, 1, img);

            }
            // it's not the first file
            else
            {
                // close the previuous one
                fclose(img);
                is_open = false;

                // new file for name for writing the jpg's
                char newfilename[7];

                sprintf(newfilename, "%03i.jpg", n_jpg);
                img = fopen(newfilename, "w");
                is_open = true;

                if (img == NULL)
                {
                    fclose(fileptr);
                    free(buffer);
                    fprintf(stderr, "Could not create %s", newfilename);

                    return 1;
                }

                n_jpg++;

                fwrite(buffer, 512, 1, img);
            }
        }
        else
        {
            if (is_open == true)
            {
                fwrite(buffer, 512, 1, img);
            }
        }
    }

    fclose(fileptr);
    return 0;
}