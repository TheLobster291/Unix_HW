//////////////////////////////////////////////////////////////////////////////
//
// convert.c     - a quick helper program that may  assist  you  on  your
//                 puzzlebox journeys.
//
// This program will take data from  STDIN, convert it, and display it to
// STDOUT. You will want to use it when presented with ASCII data that is
// otherwise un-ASCII-ified (it will look like a  space-separated  series
// of values, in one of three bases). Your task is to figure out what the
// current representation is,  and then determine how to adapt this code, 
// so that it will assist you in converting from the original format to a
// desired end format, which should (in most cases) be more actionable to
// work with.
//
// Compilation and further use instructions are in the comments below.
//
// For those  unfamiliar with  C, the  magic is  in the  format specifier
// string  in the  fscanf(). You  have  the following  at your  immediate
// disposal:
//
//  format     description of format specifier
//  ======     =============================================================
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
// NOTE: data encoded with this logic, especialy the numerical values, is
// quite textually readable. You can and SHOULD cat it to get a feel  for
// what sort of encoding scheme you are working with.
//
// There are additional means of translation. and I encourage you to seek
// them out; especially means that may directly aid you in the solving of
// this puzzlebox.
//
// This is C  source code. In order  to USE it, you will  need to COMPILE
// it: gcc -Wall --std=gnu18 convert.c -o convert
//
// NOTE: instead of calling it 'convert',  you might instead want to give
// it a name reflective of its specific operation, such as 'dec2ascii' or
// 'oct2hex'.
//
// It might make sense to make multiple copies of the code, adapting each
// one to useful source and destination formats, so you can call upon the
// right tool when the opportunity arises.
//
// To run it, remember that unless you place the compiled file in a  PATH
// your session recognizes, you will have to specify a path to it so that
// you can run it.
//
// Be sure  to include any steps  of compilation in your  steps file. You
// may comment upon  what changes you made to get  the program in correct
// working order (so, consider an exception to the manual editing rule to
// be in place for changing this  file:  you can manually  edit JUST THIS
// FILE to get it in the form that is compatible with your puzzle data).
//
// To use it, you need to run or  execute it, as you would any other tool
// (even if it doesn't seem so at first). It likely makes sense to use it
// in conjunction with a pipe, or use a STDIN redirection. It will output
// to STDOUT.
//
// Since you have likely compiled it in your local project directory,  it
// is not likely in your PATH. You will have to specify a path to be able
// to run your executable.
// 
#include <stdio.h>
#include <stdlib.h>

int main()
{
    //////////////////////////////////////////////////////////////////////////
    //
    // Declare variable: where we are going to store  our inputted  value
    //
    char  input                                 = 0;
    char  output                                = 0;

    //////////////////////////////////////////////////////////////////////////
    //
    // INPUT  a value,  and  store  its numeric  value  into our  'input'
    // variable. Keep  going until there is  no more data to  be read (in
    // which case an "end of file" marker will be encountered, ending the
    // loop).
    //
    // Please make note of the format specifier for the input, and ensure
    // that it matches the format of the data you've encountered for your
    // puzzle.  If not, you will not get any sort of  worthwhile (useful)
    // results output.
    //
    while ((fscanf (stdin, "%hhx", &input)) != EOF)
    {
        //////////////////////////////////////////////////////////////////////
        //
        // OUTPUT: encode the recently obtained input value in the format
        // desired for output. Ensure the output format is the that which
        // will give you your desired output.
        //
        // NOTE: if  converting to  some numeric  value, you  will likely
        // want to add  a space after the format  specifier below, within
        // the quotes.  Whereas, if outputting as  ASCII characters, make
        // sure there are no spaces between the quotes.
        //
        output                              = input;
        fprintf (stdout, "%c", output);
    }

    return(0);
}
