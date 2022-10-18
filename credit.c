#include <cs50.h>
#include <stdio.h>
// Luhn's algorithm for checksum:
// 1. from end, 2nd to last digit *2. Add DIGITS together
// 2. (sum digits above)+(sum digits not *2)
// 3. if total's last digit is 0, or %10 is 0, it's valid.

int main(void)
{
    long number = get_long("What is your credit card number? ");

    long credit = number;
    int rem;
    int sum2nd = 0;
    int sum1st = 0;

    // Luhn's algorithm METHOD 1
    for (int i = 0; credit > 0; i++)
    {
        rem = credit % 10;
        credit = credit / 10;
        if (i % 2 == 0)
        {
            if (rem >= 10)
            {
                sum1st += rem % 10 + rem / 10;
            }
            else
            {
                sum1st += rem;
            }
        }
        else
        {
            rem *= 2;
            if (rem >= 10)
            {
                sum2nd += rem % 10 + rem / 10;
            }
            else
            {
                sum2nd += rem;
            }
        }
    }

    long total = sum2nd + sum1st;
    if (total % 10 == 0)
    {
        // American Express uses 15-digit numbers, start w 34 or 37
        if ((340000000000000 <= number) && (number <= 349999999999999))
        {
            printf("AMEX\n");
        }
        if ((370000000000000 <= number) && (number <= 379999999999999))
        {
            printf("AMEX\n");
        }
        // MasterCard uses 16-digit numbers, start w  51, 52, 53, 54, or 55
        else if ((5100000000000000 <= number) && (number <= 5599999999999999))
        {
            printf("MASTERCARD\n");
        }
        // Visa uses 13- and 16-digit numbers, start w 4
        else if (((4000000000000000 <= number) && (number <= 4999999999999999)) || ((4000000000000 <= number) && (number <= 4999999999999)))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
    // printf("%i\n", sum2nd);
    // printf("%i\n", sum1st);
    //  Luhn's algorithm METHOD 2
    /*
    // offset by 1 to start on 2nd to last digit
    credit = credit / 10;
    while (credit > 0)
    {
        rem = credit % 10;
        // printf("%i\n", rem);
        rem *= 2;
        credit = credit / 100;

        if (rem >= 10)
        {
            sum2nd += rem % 10 + rem / 10;
        }

        if (rem < 10)
        {
            sum2nd += rem;
        }
    }

    // reset credit to original
    credit = number;

    while (credit > 0)
    {
        rem = credit % 10;
        // printf("%i\n", rem);
        credit = credit / 100;

        if (rem >= 10)
        {
            sum1st = +rem % 10 + rem / 10;
        }

        if (rem < 10)
        {
            sum1st = +rem;
        }
    }
    */
}