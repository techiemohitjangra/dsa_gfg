#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int64_t naivePower(int64_t, uint8_t);
int64_t recursivePower(int64_t, uint8_t);

// Asymptotic Notation(Time): O(n)
// Asymptotic Notation(Space): O(1)
int64_t naivePower(int64_t base, uint8_t exponent) {
    uint64_t result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

// Asymptotic Notation(Time): O(log(n))
// Asymptotic Notation(Space): O(log(n))
int64_t recursivePower(int64_t base, uint8_t exponent) {
    if (exponent == 1) {
        return 1;
    }

    int64_t temp = recursivePower(base, exponent / 2);
    temp = temp * temp;
    if (exponent % 2 == 0) {
        return temp;
    } else {
        return temp * base;
    }
}

int32_t main(int32_t argc, char **argv) {
    int64_t base;
    uint8_t exponent;
    char *temp;
    if (argc == 3) {
        base = strtoul(argv[1], &temp, 10);
        exponent = strtoul(argv[2], &temp, 10);
        printf("%li^%hu is %li", base, exponent, recursivePower(base, exponent));
        printf("\n");
    } else if (argc <= 3) {
        fprintf(stderr, "Not Enough Arguments\n");
        fprintf(stderr, "Usage: ./computingPower <input>\n");
        return 1;
    } else {
        fprintf(stderr, "Too many Arguments\n");
        fprintf(stderr, "Usage: ./computingPower <input>\n");
        return 1;
    }
    return 0;
}
