#include <errno.h>
#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint8_t rightmost_different_bits(int64_t, int64_t);

uint8_t rightmost_different_bits(int64_t first, int64_t second) {
    int64_t temp = first ^ second;
    if (temp == 0) {
        return -1;
    }
    uint result = 0;
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
    int64_t first, second;

    if (argc == 3) {
        errno = 0;
        first = strtoll(argv[1], &endptr, 10);
        if (errno == ERANGE) {
            if (first == LLONG_MAX) {
                fprintf(stderr, "%s: Value Overflow\n", argv[1]);
            }
            if (first == LLONG_MIN) {
                fprintf(stderr, "%s: Value Underflow\n", argv[1]);
            }
            exit(EXIT_FAILURE);
        }
        if (errno != 0) {
            perror("strtoll");
            exit(EXIT_FAILURE);
        }
        if (endptr == argv[1]) {
            fprintf(stderr, "No digits found\n");
            exit(EXIT_FAILURE);
        }
        if (*endptr != '\0') {
            printf("further characters after number are \"%s\"\n", endptr);
        }

        errno = 0;
        second = strtoll(argv[2], &endptr, 10);
        if (errno == ERANGE) {
            if (first == LLONG_MAX) {
                fprintf(stderr, "%s: Value Overflow\n", argv[2]);
            }
            if (first == LLONG_MIN) {
                fprintf(stderr, "%s: Value Underflow\n", argv[2]);
            }
            exit(EXIT_FAILURE);
        }
        if (errno != 0) {
            perror("strtoll");
            exit(EXIT_FAILURE);
        }
        if (endptr == argv[2]) {
            fprintf(stderr, "No digits found\n");
            exit(EXIT_FAILURE);
        }
        if (*endptr != '\0') {
            printf("further characters after number are \"%s\"\n", endptr);
        }

        printf("right most different bit in %ld and %ld is at index %u\n",
               first, second, rightmost_different_bits(first, second));
        exit(EXIT_SUCCESS);

    } else if (argc < 3) {
        fprintf(stderr, "Too few arguments\n");
        fprintf(stderr, "Usage: %s <input1> <input2>\n", argv[0]);
        exit(EXIT_FAILURE);

    } else {
        fprintf(stderr, "Too many arguments\n");
        fprintf(stderr, "Usage: %s <input1> <input2>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    return 0;
}
