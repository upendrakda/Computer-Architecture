// Program to perform binary addition and binary subtraction of two binary numbers
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    system("clear");
    char bin1[32], bin2[32], sum[33];
    int i, carry = 0;
    int len1, len2, max;

    printf("Enter first binary number: ");
    scanf("%s", bin1);

    printf("Enter second binary number: ");
    scanf("%s", bin2);

    len1 = strlen(bin1);
    len2 = strlen(bin2);
    max = (len1 > len2) ? len1 : len2;

    /* Binary Addition */
    bin1[max] = '\0';
    bin2[max] = '\0';

    for (i = max - 1; i >= 0; i--) {
        int b1 = (i < len1) ? bin1[len1 - max + i] - '0' : 0;
        int b2 = (i < len2) ? bin2[len2 - max + i] - '0' : 0;

        sum[i + 1] = (b1 ^ b2 ^ carry) + '0';
        carry = (b1 & b2) | (b1 & carry) | (b2 & carry);
    }

    sum[0] = carry + '0';
    sum[max + 1] = '\0';

    printf("Binary Addition = %s\n", (sum[0] == '0') ? sum + 1 : sum);

    /* Binary Subtraction (bin1 - bin2 using 2's complement) */
    char temp[32];
    strcpy(temp, bin2);

    /* 1's complement */
    for (i = 0; temp[i] != '\0'; i++) {
        temp[i] = (temp[i] == '0') ? '1' : '0';
    }

    /* Add 1 to get 2's complement */
    carry = 1;
    for (i = strlen(temp) - 1; i >= 0; i--) {
        if (temp[i] == '1' && carry == 1) {
            temp[i] = '0';
        } else if (temp[i] == '0' && carry == 1) {
            temp[i] = '1';
            carry = 0;
        }
    }

    /* Add bin1 and 2's complement of bin2 */
    carry = 0;
    for (i = max - 1; i >= 0; i--) {
        int b1 = bin1[len1 - max + i] - '0';
        int b2 = temp[len2 - max + i] - '0';

        sum[i + 1] = (b1 ^ b2 ^ carry) + '0';
        carry = (b1 & b2) | (b1 & carry) | (b2 & carry);
    }

    printf("Binary Subtraction = %s\n", sum + 1);

    return 0;
}
