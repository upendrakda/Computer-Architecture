// Program to perform addition with signed 2’s complement data
#include <stdio.h>
#include <stdlib.h>

// Function to print 8-bit binary (2's complement)
void printBinary(signed char n)
{
    unsigned char mask = 1 << 7;
    while (mask)
    {
        printf("%d", (n & mask) ? 1 : 0);
        mask >>= 1;
    }
}

int main()
{
    system("clear");
    int x, y;              // read safely
    signed char a, b, sum; // actual 2's complement values

    printf("Enter first signed number (-128 to 127): ");
    scanf("%d", &x);

    printf("Enter second signed number (-128 to 127): ");
    scanf("%d", &y);

    a = (signed char)x;
    b = (signed char)y;

    sum = a + b;

    printf("\nFirst number (2's complement):  ");
    printBinary(a);

    printf("\nSecond number (2's complement): ");
    printBinary(b);

    printf("\nSum (2's complement):           ");
    printBinary(sum);

    printf("\n\nDecimal Sum = %d\n", sum);

    // Overflow detection
    if ((a > 0 && b > 0 && sum < 0) || (a < 0 && b < 0 && sum > 0))
        printf("Overflow occurred!\n");
    else
        printf("No overflow.\n");

    return 0;
}
