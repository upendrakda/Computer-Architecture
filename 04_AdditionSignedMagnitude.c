// Program to perform addition with signed magnitude data
#include <stdio.h>
#include <stdlib.h>

int main() {
    system("clear");
    int sign1, sign2;
    int mag1, mag2;
    int result_sign, result_mag;

    printf("Enter sign and magnitude of first number\n");
    printf("Sign (0 for +, 1 for -): ");
    scanf("%d", &sign1);
    printf("Magnitude: ");
    scanf("%d", &mag1);

    printf("\nEnter sign and magnitude of second number\n");
    printf("Sign (0 for +, 1 for -): ");
    scanf("%d", &sign2);
    printf("Magnitude: ");
    scanf("%d", &mag2);

    /* Signed Magnitude Addition */
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

    printf("\nResult:\n");
    printf("Sign = %d\n", result_sign);
    printf("Magnitude = %d\n", result_mag);

    return 0;
}
