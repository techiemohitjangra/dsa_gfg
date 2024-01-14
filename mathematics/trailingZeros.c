#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint64_t trailing_zeros(uint64_t number) {
    uint64_t zeros = 0;
    while (number) {
        zeros += number / 5;
        number /= 5;
    }
    return zeros;
}

uint64_t count_zeros(uint64_t number) {
    uint64_t zeros = 0;
    for (int i = 5; i <= number; i *= 5) {
        zeros += number / i;
    }
    return zeros;
}

int main(int argc, char **argv) {

    uint64_t number;
    char *temp;
    uint64_t zeros;
    if (argc < 2) {
        fprintf(stderr, "Not Enough Arguments\n");
        fprintf(stderr, "Usage: ./trailingZeros <input>\n");
        exit(EXIT_FAILURE);
    } else {
        number = strtol(argv[1], &temp, 10);
        zeros = trailing_zeros(number);
        printf("Trailing zeros in factorial of %lu is %lu\n", number, zeros);
        printf("Trailing zeros in factorial of %lu is %lu\n", number, count_zeros(number));
    }

    return 0;
}
