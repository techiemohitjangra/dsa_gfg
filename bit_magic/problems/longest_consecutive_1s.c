#include <errno.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint32_t max_consecutive_set_bits(uint32_t);
uint32_t max_consecutive_set_bits(uint32_t input) {
    uint32_t result = 0;
    uint32_t count = 0;
    while (input) {
        if (input & 1) {
            count++;
        } else {
            count = 0;
        }
        if (count > result) {
            result = count;
        }
        input >>= 1;
    }
    return result;
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
            fprintf(stderr, "No digits were found\n");
            exit(EXIT_FAILURE);
        }
        if (*endptr != '\0') {
            printf("Further characters after the number \"%s\"\n", endptr);
        }
        printf("longest consecutive set bits in %lu is %u\n", first,
               max_consecutive_set_bits(first));
    } else if (argc < 2) {
        fprintf(stderr, "Too few arugments\n");
        fprintf(stderr, "Usage: %s <input>\n", argv[0]);
        exit(EXIT_FAILURE);
    } else {
        fprintf(stderr, "Too many arugments\n");
        fprintf(stderr, "Usage: %s <input>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    return 0;
}
