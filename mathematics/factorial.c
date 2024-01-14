#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint64_t factorial(uint64_t number) {
    uint64_t factorial = 1;
    for (int i = number; i > 0; --i) {
        factorial *= number;
        number--;
    }
    return factorial;
}
int main(int argc, char **argv) {
    uint64_t number, fact;
    char *temp;
    if (argc < 2) {
        fprintf(stderr, "Not Enough Arguments\n");
        fprintf(stderr, "Usage: ./factorial <input>\n");
        exit(EXIT_FAILURE);
    } else {
        number = strtol(argv[1], &temp, 10);
        if (number == 0) {
            fact = 1;
        } else if (number > 65) {
            printf("[IntergerOverFlow]: Result is too big\n");
            exit(EXIT_FAILURE);
        } else {
            fact = factorial(number);
        }
        printf("Factorial of %lu is %lu\n", number, fact);
    }
    return 0;
}
