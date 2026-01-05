// Program to perform subtraction with signed magnitude data
#include <stdio.h>
#include <stdlib.h>

int main() {
    system("clear");
    int sign1, sign2;
    int mag1, mag2;
    int result_sign, result_mag;

    printf("Enter sign and magnitude of first number (A)\n");
    printf("Sign (0 for +, 1 for -): ");
    scanf("%d", &sign1);
    printf("Magnitude: ");
    scanf("%d", &mag1);

    printf("\nEnter sign and magnitude of second number (B)\n");
    printf("Sign (0 for +, 1 for -): ");
    scanf("%d", &sign2);
    printf("Magnitude: ");
    scanf("%d", &mag2);

    /* Subtraction: A - B = A + (-B) */
    sign2 = (sign2 == 0) ? 1 : 0;   // Change sign of B

    /* Signed Magnitude Addition Logic */
    if (sign1 == sign2) {
        /* Same sign → add magnitudes */
        result_mag = mag1 + mag2;
        result_sign = sign1;
    } else {
        /* Different signs → subtract magnitudes */
        if (mag1 > mag2) {
            result_mag = mag1 - mag2;
            result_sign = sign1;
        } else if (mag2 > mag1) {
            result_mag = mag2 - mag1;
            result_sign = sign2;
        } else {
            /* Result is zero */
            result_mag = 0;
            result_sign = 0;
        }
    }

    printf("\nResult of Subtraction (A - B):\n");
    printf("Sign = %d\n", result_sign);
    printf("Magnitude = %d\n", result_mag);

    return 0;
}
