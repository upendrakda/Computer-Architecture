// Program to perform multiplication of signed magnitude data
#include <stdio.h>
#include <stdlib.h>

// Function to print signed magnitude (8-bit)
void printSignedMagnitude(signed char n)
{
    unsigned char sign, magnitude;
    unsigned char mask = 1 << 6;

    if (n < 0)
    {
        sign = 1;
        magnitude = -n;
    }
    else
    {
        sign = 0;
        magnitude = n;
    }

    printf("%d ", sign);

    while (mask)
    {
        printf("%d", (magnitude & mask) ? 1 : 0);
        mask >>= 1;
    }
}

int main()
{
    system("clear");
    int x, y;
    signed char a, b;
    int magR;
    unsigned char signA, signB, signR;
    unsigned char magA, magB;

    printf("Enter first signed number (-63 to 63): ");
    scanf("%d", &x);

    printf("Enter second signed number (-63 to 63): ");
    scanf("%d", &y);

    a = (signed char)x;
    b = (signed char)y;

    // Extract sign and magnitude
    signA = (a < 0);
    signB = (b < 0);

    magA = (a < 0) ? -a : a;
    magB = (b < 0) ? -b : b;

    signR = signA ^ signB;
    magR = magA * magB;

    // Overflow check (7-bit magnitude)
    if (magR > 127)
    {
        printf("\nOverflow occurred! Result cannot be represented in signed magnitude.\n");
        return 0;
    }

    signed char result = signR ? -magR : magR;

    printf("\nFirst number (Signed Magnitude):  ");
    printSignedMagnitude(a);

    printf("\nSecond number (Signed Magnitude): ");
    printSignedMagnitude(b);

    printf("\nResult (Signed Magnitude):        ");
    printSignedMagnitude(result);

    printf("\n\nDecimal Result = %d\n", result);

    return 0;
}
