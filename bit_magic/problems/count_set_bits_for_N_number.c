#include <errno.h>
#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int64_t count_set_bits(int64_t);

int64_t count_set_bits(int64_t input) {
    if (input < 2) {
        return input;
    }
    double msb = log2(input);

    return msb * (1 << ((int)msb - 1)) + (input - (1 << (int)msb)) + 1 +
           count_set_bits((input - (1 << (int)msb)));
}

int32_t main(int32_t argc, char **argv) {
    char *endptr;
    uint64_t first;
    if (argc == 2) {
        errno = 0;
        first = strtoull(argv[1], &endptr, 10);
        if (errno == ERANGE && first == ULLONG_MAX) {
            fprintf(stderr, "%s: Value Overflow\n", argv[1]);
            exit(EXIT_FAILURE);
        }
        if (errno != 0) {
            perror("strtoull");
            exit(EXIT_FAILURE);
        }
        if (endptr == argv[1]) {
            fprintf(stderr, "No digits found\n");
            exit(EXIT_FAILURE);
        }
        if (*endptr != '\0') {
            printf("further characters after number \"%s\"\n", endptr);
        }
        printf("number of set bits from 1 to %ld are %ld\n", first,
               count_set_bits(first));
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
