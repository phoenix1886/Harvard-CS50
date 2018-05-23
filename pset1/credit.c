#include <stdio.h>
#include <cs50.h>

long long power(int num, int x);

int main(void)
{
    printf("Number: ");
    long long num = get_long_long();
    long long num_copy = num;
    int sum1 = 0;
    int sum2 = 0;

    int counter = 0;
    for (int i = 0;;i++)
    {
        int rem = num % 10;
        num /= 10;
        if (i % 2 == 0)
        {
            sum1 += rem;
        }
        else
        {
            rem *= 2;
            sum2 += rem/10 + rem%10;
        }
        if (num == 0) break;
        counter++;
    }
    int total_sum = sum1 + sum2;
    if (total_sum % 10 == 0)
    {
        int first_two_digits = (int)(num_copy / power(10, counter-1));

        switch (first_two_digits)
        {
            case 34:
            case 37:
                printf("AMEX\n");
                break;
            case 51:
            case 52:
            case 53:
            case 54:
            case 55:
                printf("MASTERCARD\n");
                break;
            default:
                if (first_two_digits / 10 == 4)
                    printf("VISA\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}

long long power(int num, int x)
{
    long long result = 1;
    for (int i = 0; i < x; i++)
    {
        result *= num;
    }

    return result;
}