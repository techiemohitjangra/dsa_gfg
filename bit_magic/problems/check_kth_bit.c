#include <errno.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

bool kth_bit(uint64_t, uint8_t);
bool alt_kth_bit(uint64_t, uint8_t);

// 1 indexed from LSB
bool kth_bit(uint64_t input, uint8_t k) { return (input & (1 << (k - 1))); }

// 0 indexed from LSB
bool alt_kth_bit(uint64_t input, uint8_t k) { return (input & (1 << k)); }

int main(int argc, char **argv) {
    char *endptr;
    uint64_t first;
    uint8_t second;

    if (argc == 3) {
        errno = 0;
        first = strtoll(argv[1], &endptr, 10);
        if (errno == ERANGE && first == ULLONG_MAX) {
            fprintf(stderr, "%s: Value Overflow!\n", argv[1]);
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

        errno = 0;
        second = strtoul(argv[2], &endptr, 10);
        if (errno == ERANGE && second == UCHAR_MAX) {
            fprintf(stderr, "%s: Value Overflow!\n", argv[2]);
            exit(EXIT_FAILURE);
        }
        if (errno != 0) {
            perror("strtoll");
            exit(EXIT_FAILURE);
        }
        if (endptr == argv[2]) {
            fprintf(stderr, "No digits were found.\n");
            exit(EXIT_FAILURE);
        }
        if (*endptr != '\0') {
            printf("Further characters after number \"%s\"\n", endptr);
        }
        printf("%u bit of %lu is %u\n", second, first,
               alt_kth_bit(first, second));
        exit(EXIT_SUCCESS);
    } else if (argc < 3) {
        fprintf(stderr, "Too few Arguments\n");
        fprintf(stderr, "Usage: %s <input_number> <k>\n", argv[0]);
        exit(EXIT_FAILURE);
    } else {
        fprintf(stderr, "Too many Arguments\n");
        fprintf(stderr, "Usage: %s <input_number> <k>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    return 0;
}
