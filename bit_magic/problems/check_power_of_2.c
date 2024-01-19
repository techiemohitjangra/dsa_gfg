#include <errno.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

bool is_power_of_2(uint64_t);
bool is_power_of_2(uint64_t input) {
    if (input == 0) {
        return false;
    }
    return (input & (input - 1));
}

int32_t main(int32_t argc, char **argv) {
    char *endptr;
    uint64_t first;
    if (argc == 2) {
        errno = 0;
        first = strtoull(argv[1], &endptr, 10);
        if (errno == ERANGE && first == ULLONG_MAX) {
            fprintf(stderr, "%s: Value overflow!\n", argv[1]);
            exit(EXIT_FAILURE);
        }
        if (errno != 0) {
            perror("strtoull");
            exit(EXIT_FAILURE);
        }
        if (endptr == argv[1]) {
            fprintf(stderr, "No digits were found\n");
            exit(EXIT_FAILURE);
        }
        if (*endptr != '\0') {
            printf("further character after number \"%s\"\n", endptr);
        }
        printf("%lu %s power of 2\n", first,
               (!is_power_of_2(first) ? "is" : "is not"));
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
