/**
 * sbian23
 * 251287906
 * cs2211
 * Kaizhong Zhang
 * December 4, 2023
 *
 * This class takes input and uses the matrix.c class to build a tree matrix
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "matrix.h"

int main()
{
    // Create a new matrix
    Matrix myMatrix = matrix_construction();

    // initialize a char array with max 100 char
    char userString[100];
    // initalize a number
    int userNumber;
    // prompt the user to type in strings
    printf("Enter number and string (type 'stop' to stop):\n");

    bool stop = false;
    while (stop == false)
    {
        // gets user input and puts it into the char array
        fgets(userString, sizeof(userString), stdin);

               // if the user input stop, stop the while loop
        int s = strncmp(userString, "stop", 4);
        if (s == 0)
        {
            stop = true;
            break;
        }

        // reads the integer and stores it in number and reads the string and stores it in string
        int numberScanned = sscanf(userString, "%d %[^\n]", &userNumber, userString);
        // if the number of things inputted (should be two, one for string, one for integer)
        if (numberScanned == 2)
        {
            // put it into the matrix using the string and number that user gave
            matrix_set(myMatrix, userString, userNumber, 1); // Assuming '1' is the value to set.
        }
        else
        {
            // if it wasn't in the correct format, tell the user
            printf("Incorrect format.\n");
        }
    }

    // printing the matrix
    printf("Number Street Occurrence\n");
    matrix_list(myMatrix);

    // destroy the matrix and free all memory
    matrix_destruction(myMatrix);

    return 0;
}
