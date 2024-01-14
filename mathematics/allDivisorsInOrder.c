#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void divisorsInOrder(uint64_t number);

void divisorsInOrder(uint64_t number) {
    size_t i = 0;
    for (i = 1; i * i <= number; ++i) {
        if (number % i == 0) {
            printf("%lu ", i);
        }
    }
    for (; i * i >= 1; --i) {
        if (number %i == 0) {
            printf("%lu ", ((uint64_t)number / i));
        }
    }
}

int main(int argc, char **argv) {
    uint64_t number;
    char *temp;
    if (argc == 2) {
        number = strtoul(argv[1], &temp, 10);
        printf("divisors of %lu are ", number);
        divisorsInOrder(number);
        printf("\n");
    } else if (argc <= 2) {
        fprintf(stderr, "Not Enough Arguments\n");
        fprintf(stderr, "Usage: ./allDivisorsInOrder <input>\n");
        return 1;
    } else {
        fprintf(stderr, "Too many Arguments\n");
        fprintf(stderr, "Usage: ./allDivisorsInOrder <input>\n");
        return 1;
    }
    return 0;
}
