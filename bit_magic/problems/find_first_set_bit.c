#include <errno.h>
#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint8_t first_set_bit(int64_t);

// find the index of rightmost set bit
uint8_t first_set_bit(int64_t input) {
    uint8_t result = 0;
    double temp = input;
    double msb = 0;
    while (temp) {
        msb = log2(temp);
        result = temp;
        temp = temp - (1 << (int)msb);
    }
    return log2(result) + 1;
}

int32_t main(int32_t argc, char **argv) {
    char *endptr;
    int64_t first;
    if (argc == 2) {
        errno = 0;
        first = strtoll(argv[1], &endptr, 10);
        if (errno == ERANGE && first == LLONG_MAX) {
            fprintf(stderr, "%s: Value Overflow!\n", argv[1]);
            exit(EXIT_FAILURE);
        }
        if (errno == ERANGE && first == LLONG_MIN) {
            fprintf(stderr, "%s: Value Underflow!\n", argv[1]);
            exit(EXIT_FAILURE);
        }
        if (errno != 0) {
            perror("strtoll");
            exit(EXIT_FAILURE);
        }
        if (endptr == argv[1]) {
            fprintf(stderr, "No digits were found.\n");
            exit(EXIT_FAILURE);
        }
        if (*endptr != '\0') {
            printf("further characters after number \"%s\"\n", endptr);
        }

        printf("first set bit in %ld is at %u\n", first, first_set_bit(first));
        exit(EXIT_SUCCESS);
    } else if (argc < 2) {
        fprintf(stderr, "Too few arguments.\n");
        fprintf(stderr, "Usage: %s <input>\n", argv[0]);
        return 1;
    } else {
        fprintf(stderr, "Too many arguments.\n");
        fprintf(stderr, "Usage: %s <input>\n", argv[0]);
        return 1;
    }
    return 0;
}
