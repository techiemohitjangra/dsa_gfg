#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int64_t power(int64_t, uint8_t);

int64_t power(int64_t base, uint8_t exponent) {
    int64_t result = 1;
    while (exponent > 0) {
        if (exponent & 1) {
            result *= base;
        }
        base *= base;
        exponent >>= 1;
    }
    return result;
}

int32_t main(int32_t argc, char **argv) {
    int64_t base;
    uint64_t exponent;
    char *temp;
    if (argc == 3) {
        base = strtoull(argv[1], &temp, 10);
        exponent = strtoull(argv[2], &temp, 10);
        printf("%li^%lu is %li\n", base, exponent, power(base, exponent));
    } else if (argc < 3) {
        fprintf(stderr, "Too few Arguments\n");
        fprintf(stderr, "Usage: ./computingPower <base> <exponent>\n");
        return 1;
    } else {
        fprintf(stderr, "Too many Arguments\n");
        fprintf(stderr, "Usage: ./computingPower <base> <exponent>\n");
        return 1;
    }
    return 0;
}
