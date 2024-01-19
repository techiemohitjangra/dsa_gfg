#include <errno.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint32_t binary_to_gray(uint32_t);
uint32_t binary_to_gray(uint32_t input) { return (input ^ (input >> 1)); }

int32_t main(int32_t argc, char **argv) {
    char *endptr;
    uint32_t input;
    if (argc == 2) {
        errno = 0;
        input = strtoul(argv[1], &endptr, 10);
        if (errno == ERANGE) {
            if (input == UINT_MAX) {
                fprintf(stderr, "%s: Value Overflow\n", argv[1]);
                exit(EXIT_FAILURE);
            }
        }
        if (errno != 0) {
            perror("strtol");
            exit(EXIT_FAILURE);
        }
        if (endptr == argv[1]) {
            fprintf(stderr, "No digits were found\n");
            exit(EXIT_FAILURE);
        }
        if (*endptr != '\0') {
            printf("Further characters after number are \"%s\"\n", endptr);
        }
        printf("%u", binary_to_gray(input));
        exit(EXIT_SUCCESS);

    } else if (argc < 2) {
        fprintf(stderr, "Too few arguments\n");
        fprintf(stderr, "Usage: %s <input>\n", argv[0]);
        exit(EXIT_FAILURE);

    } else {
        fprintf(stderr, "Too many arguments\n");
        fprintf(stderr, "Usage: %s <input>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    return 0;
}
