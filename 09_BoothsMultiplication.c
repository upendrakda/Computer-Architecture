// Program to implement Booth’s multiplication
#include <stdio.h>
#include <stdlib.h>

#define MASK8 0xFF
#define SIGN8 0x80

void printBinary8(int x)
{
    for (int i = 7; i >= 0; i--)
        printf("%d", (x >> i) & 1);
}

// Arithmetic right shift of A, Q, Q-1
void arithmeticRightShift(int *A, int *Q, int *Q_1)
{
    int a0 = *A & 1;
    int signA = *A & SIGN8;

    *Q_1 = *Q & 1;
    *Q = ((*Q >> 1) | (a0 << 7)) & MASK8;
    *A = ((*A >> 1) | signA) & MASK8;
}

int main()
{
    system("clear");
    int M, Q;
    int A = 0, Q_1 = 0;
    int count = 8;

    printf("Enter multiplicand (M): ");
    scanf("%d", &M);

    printf("Enter multiplier (Q): ");
    scanf("%d", &Q);

    M &= MASK8;
    Q &= MASK8;

    printf("\nStep\tA\t\tQ\t\tQ-1\tOperation\n");
    printf("------------------------------------------------------------\n");

    for (int step = 1; step <= 8; step++)
    {
        int q0 = Q & 1;

        printf("%d\t", step);
        printBinary8(A);
        printf("\t");
        printBinary8(Q);
        printf("\t%d\t", Q_1);

        if (q0 == 0 && Q_1 == 1)
        {
            printf("A = A + M");
            A = (A + M) & MASK8;
        }
        else if (q0 == 1 && Q_1 == 0)
        {
            printf("A = A - M");
            A = (A - M) & MASK8;
        }
        else
        {
            printf("No operation");
        }

        arithmeticRightShift(&A, &Q, &Q_1);
        printf("\n");
    }

    // Combine A and Q into 16-bit signed result
    int result = (A << 8) | Q;
    if (result & 0x8000)
        result |= ~0xFFFF;

    printf("\nFinal Result (Binary): ");
    printBinary8(A);
    printf(" ");
    printBinary8(Q);

    printf("\nFinal Result (Decimal): %d\n", result);

    return 0;
}
