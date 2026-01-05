// Program to find the 1’s complement and 2’s complement of a given binary number
#include <stdio.h>
#include <stdlib.h>

int main() {
    system("clear");
    char bin[32];
    int i, carry = 1;

    printf("Enter a binary number: ");
    scanf("%s", bin);

    /* 1's Complement */
    for (i = 0; bin[i] != '\0'; i++) {
        if (bin[i] == '0')
            bin[i] = '1';
        else
            bin[i] = '0';
    }

    printf("1's Complement = %s\n", bin);

    /* 2's Complement */
    for (i = i - 1; i >= 0; i--) {
        if (bin[i] == '1' && carry == 1) {
            bin[i] = '0';
        }
        else if (bin[i] == '0' && carry == 1) {
            bin[i] = '1';
            carry = 0;
        }
    }

    printf("2's Complement = %s\n", bin);

    return 0;
}
