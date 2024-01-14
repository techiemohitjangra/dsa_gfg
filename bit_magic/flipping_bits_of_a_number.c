#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int64_t flip(int64_t);

int64_t flip(int64_t input) {
    int64_t temp = input;
    int64_t value = 0;
    while (temp) {
        value <<= 1;
        value += 1;
        temp >>= 1;
    }
    return value - input;
}

int32_t main(int32_t argc, char **argv) {
    int64_t first;
    char *temp;
    if (argc == 2) {
        first = strtoll(argv[1], &temp, 10);
        printf("flip(%ld) = %ld\n", first, flip(first));
    } else if (argc < 2) {
        fprintf(stderr, "Too few arguments\n");
        fprintf(stderr, "Usage: ./flipping_bits_of_a_number <input>\n");
        return 1;
    } else {
        fprintf(stderr, "Too many arguments\n");
        fprintf(stderr, "Usage: ./flipping_bits_of_a_number <input>\n");
        return 1;
    }
    return 0;
}
