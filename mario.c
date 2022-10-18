#include <cs50.h>
#include <stdio.h>

// this program builds a pyramid like in mario based on user input between 1 and 8 height

int main(void)
{
    // take user input between 1-8 and take it until it's right
    int height;
    do
    {
        height = get_int("Enter pyramid height between 1 and 8: ");

    } while (height < 1 || height > 8);

    // make pyramid
    int i, j;
    for (i = 1; i <= height; i++)
    {
        // print the left space(s)
        for (j = height - i; j >= 1; j--)
        {
            printf(" ");
        }
        // print the left asterisk(s)
        for (j = 1; j <= i; j++)
        {
            printf("#");
        }

        // print the middle 2 spaces
        printf("  ");

        // print the right asterisk(s)
        for (j = 1; j <= i; j++)
        {
            printf("#");
        }

        // new line
        printf("\n");
    }
}