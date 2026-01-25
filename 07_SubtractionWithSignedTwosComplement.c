//Program to perform subtraction with signed 2’s complement data
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
    int x, y;
    signed char a, b, result;

    printf("Enter first signed number (-128 to 127): ");
    scanf("%d", &x);

    printf("Enter second signed number (-128 to 127): ");
    scanf("%d", &y);

    a = (signed char)x;
    b = (signed char)y;

    // Subtraction using 2's complement
    result = a - b;

    printf("\nFirst number (2's complement):  ");
    printBinary(a);

    printf("\nSecond number (2's complement): ");
    printBinary(b);

    printf("\nResult (2's complement):        ");
    printBinary(result);

    printf("\n\nDecimal Result = %d\n", result);

    // Overflow detection for subtraction
    if ((a > 0 && b < 0 && result < 0) || (a < 0 && b > 0 && result > 0))
        printf("Overflow occurred!\n");
    else
        printf("No overflow.\n");

    return 0;
}
