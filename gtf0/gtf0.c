#!/usr/bin/env -S tcc -run -lgd
//
// gtf0.c  - skeleton code to use the GD graphics library  in a C-script.
//           Output is a PNG file in current working directory.  View the
//           image in web browser, image viewer, file explorer, etc.
//
// PROCESS:  Any change to the code requires rerunning to get a new image
//           generated. Failure to perform this step, in order, may leave
//           you with a stale image.
//
// To execute: ./gtf0
//
// NOTE: the 'libgd3' and 'libgd-dev' packages may need to be installed
//
// Documentation:  https://libgd.github.io/manuals/2.3.0/files/preamble-txt.html
// API:            https://libgd.github.io/manuals/2.3.0/index/Functions.html
//
//////////////////////////////////////////////////////////////////////////////
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gd.h>
 
int main()
{
    //////////////////////////////////////////////////////////////////////////
    //
    // Declare variables
    //
    char       *outfile    = NULL;   // name of the output file
    char        project[]  = "gtf0"; // "string" of project name
    FILE       *out        = NULL;   // output file pointer
    gdImagePtr  image;               // GD Image Construct
    int         wide       = 1;      // image width (pixels)
    int         high       = 2;      // image height (pixels)
    int         black      = 3;      // variable representing color value
    int         blue       = 4;
    int         green      = 5;
    int         red        = 6;
    int         white      = 7;
    int         purple     = 8;
    int         NavyishBlue = 9;
    int         DeepRed    = 10;
    int         Orange     = 11;
 
    //////////////////////////////////////////////////////////////////////////
    //
    // Construct output file name (keep this as-is)
    //
    outfile                = (char *) malloc (sizeof(char) * 73);
    sprintf (outfile, "%s.png", project);
 
    //////////////////////////////////////////////////////////////////////////
    //
    // image dimensions, in pixels (note: the first coordinate on the axis
    // is 0)
    //
    wide                   = 1000;
    high                   = 1000;
 
    //////////////////////////////////////////////////////////////////////////
    //
    // Create new image of specified wide-ness and high-ness (this also will
    // initialize the gd library. Any gd functions called prior to this line
    // may result in error, since there was no image region in memory)
    //
    image                  = gdImageCreate ((wide + 1), (high + 1));
 
    //////////////////////////////////////////////////////////////////////////
    //
    // mixing up  our colors. We need  one line per color  entry, ideally
    // matching  the  color  descriptor  symbol we  are  using.  Quantity
    // specified is the 8-bit hexadecimal value for that color component
    //
    //                                             image  red   green blue
    //
    black                  = gdImageColorAllocate (image, 0x00, 0x00, 0x00);
    blue                   = gdImageColorAllocate (image, 0x00, 0x00, 0xFF);
    green                  = gdImageColorAllocate (image, 0x00, 0xFF, 0x00);
    red                    = gdImageColorAllocate (image, 0xFF, 0x00, 0x00);
    white                  = gdImageColorAllocate (image, 0xFF, 0xFF, 0xFF);
    purple                 = gdImageColorAllocate (image, 0x57, 0x0E, 0x9C);
    NavyishBlue            = gdImageColorAllocate (image, 0x12, 0x2A, 0x54);
    DeepRed                = gdImageColorAllocate (image, 0x91, 0x00, 0x00);
    Orange                 = gdImageColorAllocate (image, 0xD6, 0x5B, 0x13);
 
    //////////////////////////////////////////////////////////////////////////
    //
    // Paint the background black
    //
    //                      image  x  y  x2    y2    color
    //
    gdImageFilledRectangle (image, 0, 0, wide, high, black);
    
    
    //Orange Rectangle
    gdImageFilledRectangle (image, 600, 600, 650, 650, Orange);
 
    //////////////////////////////////////////////////////////////////////////
    //
    // draw the outline of a blue rectangle in the upper left quarter of
    // the image
    //
    //                image  x   y   x2   y2   color
    //
    gdImageRectangle (image, 10, 10, 240, 240, blue);

    //////////////////////////////////////////////////////////////////////////
    //
    // draw a white-outlined circle and fill it green in upper right
    // quarter of the image
    //
    //          image  centerxy  diameterxy  angle start    end  color
    //
    gdImageArc (image, 375, 125, 120, 120,           0,     360, white);

    //           image  x    y    color to fill
    gdImageFill (image, 375, 125, green);

    //////////////////////////////////////////////////////////////////////////
    //
    // lower left: white-filled "orange slice" inside red-filled rectangle
    //
    gdImageArc (image, 125, 375, 120, 120, 90, 270, white);
    gdImageLine (image, 125, 315, 125, 435, white);
    gdImageFill (image, 120, 375, white);
    gdImageRectangle (image, 10, 260, 240, 490, red);
    gdImageFill (image, 15, 265, red);

    //////////////////////////////////////////////////////////////////////////
    //
    // lower right: red plus sign in a green circle
    //
    gdImageArc (image, 375, 375, 120, 120, 0, 360, green);
    gdImageFill (image, 375, 375, green);
    gdImageFilledRectangle (image, 370, 315, 380, 435, red);
    gdImageFilledRectangle (image, 315, 370, 435, 380, red);
    
    
    
    gdImageFilledRectangle (image, 770, 715, 780, 835, red);
    gdImageFilledRectangle (image, 715, 770, 835, 780, DeepRed);
    
    
    // Elipses

    gdImageArc (image, 400, 400, 200, 300,   0, 360, NavyishBlue);
    gdImageFill (image, 400, 400, NavyishBlue);
    
    
    gdImageArc (image, 800, 400, 300, 600,   0, 360, purple);
    gdImageFill (image, 800, 400, NavyishBlue);
    
    gdImageArc (image, 200, 800, 500, 100,   0, 360, Orange);
    gdImageFill (image, 200, 800, Orange);
    
    
    // Initials
    gdImageFilledRectangle (image, 800, 800, 850, 820, DeepRed);
    gdImageFilledRectangle (image, 820, 820, 840, 870, white);
    gdImageFilledRectangle (image, 800, 850, 840, 870, green);

    gdImageFilledRectangle (image, 860, 800, 880, 870, Orange);
    gdImageArc (image, 880, 835, 70, 70, 0, 90, white);
    gdImageArc (image, 880, 800, 70, 70, 0, 90, white);
    gdImageFilledRectangle (image, 880, 830, 915, 840, white);
    gdImageFilledRectangle (image, 880, 800, 915, 810, white);

    //////////////////////////////////////////////////////////////////////////
    //
    // Open the output file (indicated in 'outfile') for writing (keep as-is)
    //
    out           = fopen (outfile, "wb");
    if (out      == NULL)
    {
        fprintf (stderr, "Error opening '%s'\n", outfile);
        exit (1);
    }
 
    //////////////////////////////////////////////////////////////////////////
    //
    // Export, in PNG format, the image data in memory to our output file
    // (keep as-is)
    //
    gdImagePngEx (image, out, -1);
 
    //////////////////////////////////////////////////////////////////////////
    //
    // Close things up (keep as-is)
    //
    fclose (out);
    gdImageDestroy (image);
 
    return (0);
}
