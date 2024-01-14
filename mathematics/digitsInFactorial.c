#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint64_t digitsInFactorial(uint64_t number) {
    double digits = 0;
    if (number == 0) {
        return 1;
    }

    for (int i = 1; i <= number; i++) {
        digits += log10(i);
    }
    return floor(digits) + 1;
}

int main(int argc, char **argv) {
    uint64_t number, digits;
    char *temp;
    if (argc < 2) {
        fprintf(stderr, "Not Enough Arguments\n");
        fprintf(stderr, "Usage: ./digitsInFactorial <input>\n");
        exit(EXIT_FAILURE);
    } else {
        number = strtol(argv[1], &temp, 10);

        digits = digitsInFactorial(number);
        printf("Digits in factorial of %lu is %lu\n", number, digits);
    }
    return 0;
}
