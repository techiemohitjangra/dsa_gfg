#include <errno.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

bool sparse_or_not(uint32_t);
bool sparse_or_not(uint32_t input) {
    return (((input & 0xAAAAAAA) == input) || (input & 0x55555555) == input);
    return (input & (input >> 1)) == 0;
}

int32_t main(int32_t argc, char **argv) {
    char *endptr;
    uint32_t input;
    if (argc == 2) {
        errno = 0;
        input = strtoul(argv[1], &endptr, 10);
        if (errno == ERANGE && input == UINT_MAX) {
            fprintf(stderr, "%s: Value Overflow", argv[1]);
            exit(EXIT_FAILURE);
        }
        if (errno != 0) {
            perror("strtoul");
            exit(EXIT_FAILURE);
        }
        if (endptr == argv[1]) {
            fprintf(stderr, "No digits were found\n");
            exit(EXIT_FAILURE);
        }
        if (*endptr != '\0') {
            printf("Further character after number are \"%s\"\n", endptr);
        }
        printf("%d\n", sparse_or_not(input));

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
