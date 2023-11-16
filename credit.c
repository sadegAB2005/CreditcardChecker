#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int sum = 0;
    int count = 0;
    long divisor = 10;

    long long originalCC;
    long long cc;

    do
    {
        cc = get_long("Number: ");
        originalCC = cc; // Save the original value
    }
    while (cc <= 0);
    cc = originalCC;

    while (cc > 0)
    {
        int digit = cc % 10;
        if (count % 2 == 1)
        {
            int oddnum = digit * 2;
            sum += oddnum % 10 + oddnum / 10;
        }
        else
        {
            sum += digit;
        }
        cc /= 10;
        count++;
    }
    // Reset cc to the original value

    // divisor
    for (int i = 0; i < count - 2; i++)
    {
        divisor = divisor * 10;
    }

    int firstDigit = originalCC / divisor;
    int firstTwoDigits = originalCC / (divisor / 10);

    // Check the card type
    if (sum % 10 == 0)
    {
        if ((firstTwoDigits == 34 || firstTwoDigits == 37) && count == 15)
            printf("AMEX\n");
        else if ((firstTwoDigits >= 51 && firstTwoDigits <= 55) && count == 16)
            printf("MASTERCARD\n");
        else if (firstDigit == 4 && (count == 13 || count == 16))
            printf("VISA\n");
        else
            printf("INVALID\n");
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}
