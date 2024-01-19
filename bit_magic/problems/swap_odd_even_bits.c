#include <errno.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint64_t swap_odd_even_bits(uint64_t);
uint64_t swap_odd_even_bits(uint64_t input) {
    uint64_t even = input & 0xAAAAAAAA;
    uint64_t odd = input & 0x55555555;
    even >>= 1;
    odd <<= 1;
    return (odd | even);
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
            printf("further character after the number are \"%s\"\n", endptr);
        }
        printf("%lu after swapping odd and even bits is %lu\n", first,
               swap_odd_even_bits(first));
        exit(EXIT_SUCCESS);

    } else if (argc < 2) {
        fprintf(stderr, "Too few arguments\n");
        fprintf(stderr, "Usage: %s <input>\n", argv[1]);
        exit(EXIT_FAILURE);
    } else {
        fprintf(stderr, "Too many arguments\n");
        fprintf(stderr, "Usage: %s <input>\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    return 0;
}

