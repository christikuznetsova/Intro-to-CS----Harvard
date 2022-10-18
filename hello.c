#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // this line takes user input, the user's name
    string namestring = get_string("What is your name? ");

    // this line outputs user name
    printf("hello, %s\n", namestring);
}