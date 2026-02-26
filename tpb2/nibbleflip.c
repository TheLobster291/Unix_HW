//////////////////////////////////////////////////////////////////////////////
//
// nibbleflip.c  - a quick helper program that may  assist  you  on  your
//                 puzzlebox journeys.
//
// This program will take data from  STDIN, convert it, and display it to
// STDOUT.
//
// NOTE: nibble-flipped data may not be all that readable from a  textual
// perspective. You may not want to cat the data before you have  flipped
// it back.
//
// For those  unfamiliar with  C, the  magic is  in the  format specifier
// string  in the  fscanf(). You  have  the following  at your  immediate
// disposal:
//
//  format     description of format specifier
//  ======     ==========================================================
//  %c         ASCII character (check out the ASCII table; ascii(7))
//  %hho       octal value   (base 8: 0 1 2 3 4 5 6 7)
//  %hhu       decimal value (base 10: 0 1 2 3 4 5 6 7 8 9)
//  %hhX       hex value     (base 16: 0 1 2 3 4 5 6 7 8 9 A B C D E F)
//  %hhx       hex value     (base 16: 0 1 2 3 4 5 6 7 8 9 a b c d e f)
//
// How you use them  will depend on what your format  your source data is
// in (you'll want to read/input/scan it  in the correct format), as well
// as what your desired destination format shall be (what format you want
// to write/print/output).
//
// There are additional means of translation, and I encourage you to seek
// them out; especially means that may directly aid you in the solving of
// this puzzlebox.
//
// This is C  source code. In order  to USE it, you will  need to COMPILE
// it: gcc -Wall --std=gnu18 nibbleflip.c -o nibbleflip
//
// Be sure  to include any steps  of compilation in your  steps file.
//
// To use it, you need to run or  execute it, as you would any other tool
// (even if it doesn't seem so at first). It likely makes sense to use it
// in conjunction with a pipe, or use a STDIN redirection. It will output
// to STDOUT.
// 
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char uc;

int main()
{
    //////////////////////////////////////////////////////////////////////////
    //
    // Declare variable: where we are going to store  our inputted  value
    //
    uc  input                               = 0;
    uc  output                              = 0;

    //////////////////////////////////////////////////////////////////////////
    //
    // INPUT: grab the  first byte from STDIN and prepare  for the actual
    // processing loop.
    //
    input                                   = fgetc (stdin);

    //////////////////////////////////////////////////////////////////////////
    //
    // So long as we haven't reached the end of the file, keep looping
    //
    while (!feof (stdin))
    {
        //////////////////////////////////////////////////////////////////////
        //
        // A byte is made up of two nibbles (4-bit sequence). Here we are
        // going to  "flip" them  (the lead 4-bits  become the  last, and
        // vice-versa)
        //
        output                              = input  &  0x0F;  // isolate
        output                              = output << 4;     // shift
        input                               = input  >> 4;     // shift
        output                              = output |  input; // combine

        //////////////////////////////////////////////////////////////////////
        //
        // OUTPUT: encode the recently obtained input value in the format
        // desired for output.
        //
        fprintf (stdout, "%c", output);

        //////////////////////////////////////////////////////////////////////
        //
        // INPUT: grab the next byte from  STDIN and prepare for the next
        // iteration.
        //
        input                               = fgetc (stdin);
    }

    return(0);
}
