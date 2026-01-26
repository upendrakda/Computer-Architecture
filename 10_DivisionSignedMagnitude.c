// Program to implement division of signed magnitude data
#include <stdio.h>
#include <stdlib.h>

void printSignedMagnitude(signed char n)
{
    unsigned char sign, mag;

    if (n < 0)
    {
        sign = 1;
        mag = -n;
    }
    else
    {
        sign = 0;
        mag = n;
    }

    printf("%d ", sign);
    for (int i = 6; i >= 0; i--)
        printf("%d", (mag >> i) & 1);
}

int main()
{
    system("clear");
    int x, y;
    signed char dividend, divisor;
    signed char quotient, remainder;

    unsigned char signD, signV, signQ;
    unsigned char magD, magV, magQ;

    printf("Enter dividend (-127 to 127): ");
    scanf("%d", &x);

    printf("Enter divisor (-127 to 127): ");
    scanf("%d", &y);

    if (y == 0)
    {
        printf("Division by zero is not allowed.\n");
        return 0;
    }

    dividend = (signed char)x;
    divisor  = (signed char)y;

    // Extract signs
    signD = (dividend < 0);
    signV = (divisor < 0);

    // Extract magnitudes
    magD = (dividend < 0) ? -dividend : dividend;
    magV = (divisor  < 0) ? -divisor  : divisor;

    // Signed magnitude division
    signQ = signD ^ signV;
    magQ  = magD / magV;

    quotient  = signQ ? -magQ : magQ;
    remainder = signD ? -(magD % magV) : (magD % magV);

    printf("\nDividend (Signed Magnitude): ");
    printSignedMagnitude(dividend);

    printf("\nDivisor  (Signed Magnitude): ");
    printSignedMagnitude(divisor);

    printf("\nQuotient (Signed Magnitude): ");
    printSignedMagnitude(quotient);

    printf("\nRemainder (Decimal): %d", remainder);

    printf("\n\nDecimal Quotient: %d\n", quotient);

    return 0;
}
