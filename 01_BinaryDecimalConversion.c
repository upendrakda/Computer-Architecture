// Program to convert a binary number into its decimal equivalent and vice versa
#include <stdio.h>
#include <stdlib.h>

int main() {
    system("clear");
    int choice;
    long long binary;
    int decimal = 0, base = 1, rem;
    int num, bin[32], i = 0;

    printf("Binary <-> Decimal \n");
    printf("\n1. Binary to Decimal\n");
    printf("2. Decimal to Binary\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        /* Binary to Decimal */
        printf("\nEnter a binary number: ");
        scanf("%lld", &binary);

        while (binary > 0) {
            rem = binary % 10;
            decimal = decimal + rem * base;
            base = base * 2;
            binary = binary / 10;
        }

        printf("Decimal equivalent = %d\n", decimal);
    }
    else if (choice == 2) {
        /* Decimal to Binary */
        printf("\nEnter a decimal number: ");
        scanf("%d", &num);

        while (num > 0) {
            bin[i] = num % 2;
            num = num / 2;
            i++;
        }

        printf("Binary equivalent = ");
        for (int j = i - 1; j >= 0; j--) {
            printf("%d", bin[j]);
        }
        printf("\n");
    }
    else {
        printf("\nInvalid choice!\n");
    }

    return 0;
}
