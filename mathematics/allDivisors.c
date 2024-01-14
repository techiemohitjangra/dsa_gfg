#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void divisors(uint64_t number);

void divisors(uint64_t number) {
    for (size_t i = 1; i * i <= number; i++) {
        if (number % i == 0) {
            printf("%lu ", i);
            if (i != number / i) {
                printf("%lu ", ((uint64_t)number / i));
            }
        }
    }
}

int main(int argc, char **argv) {
    uint64_t number;
    char *temp;
    if (argc == 2) {
        number = strtoul(argv[1], &temp, 10);
        printf("divisors of %lu are ", number);
        divisors(number);
        printf("\n");
    } else if (argc <= 2) {
        fprintf(stderr, "Not Enough Arguments\n");
        fprintf(stderr, "Usage: ./allDivisors <input>\n");
        return 1;
    } else {
        fprintf(stderr, "Too many Arguments\n");
        fprintf(stderr, "Usage: ./allDivisors <input>\n");
        return 1;
    }
    return 0;
}
