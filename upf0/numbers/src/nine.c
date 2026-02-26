//////////////////////////////////////////////////////////////////////////////
//
// nine.c    - program that displays a value in accordance to its name.
//
// Compile:     run 'make' to automate the compile.
//
// Sample run (if installed into user's ~/bin directory):
//
//    $ nine
//    9
//
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define  VARIANT 9

int main(int argc, char **argv)
{
    //////////////////////////////////////////////////////////////////////////
    //
    // Declare variables
    //
    char *upf0_output  = NULL;
    char  upf0_mode    = 0;

    //////////////////////////////////////////////////////////////////////////
    //
    // Obtain the value of the UPF0_MODE variable
    //
    upf0_output        = getenv ("UPF0_MODE");

    //////////////////////////////////////////////////////////////////////////
    //
    // Process the UPF0_MODE variable
    //
    if ((upf0_output  != NULL) &&
        (strncasecmp ("true", upf0_output, 4) == 0))
    {
        upf0_mode      = 1;
    }

    //////////////////////////////////////////////////////////////////////////
    //
    // Display the result
    //
    if (upf0_mode     == 1)
        fprintf(stdout, "%d\n", VARIANT);
    else
        fprintf(stderr, "%d\n", VARIANT);

    return(EXIT_SUCCESS);
}
