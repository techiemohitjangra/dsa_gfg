#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int64_t flip_nth_bit(int64_t, uint8_t);

int64_t flip_nth_bit(int64_t input, uint8_t k) {
    return input ^ (1 << (k - 1));
}

int32_t main(int32_t argc, char **argv) {

    int64_t first;
    uint8_t k;
    char *temp;
    if (argc == 3) {
        first = strtoll(argv[1], &temp, 10);
        k = strtoul(argv[2], &temp, 10);
        printf("toggle %u bit of %ld = %ld\n", k, first,
               flip_nth_bit(first, k));
    } else if (argc < 3) {
        fprintf(stderr, "Too few arguments\n");
        fprintf(stderr, "Usage: ./flip_nth_bit <input> <k>\n");
        return 1;
    } else {
        fprintf(stderr, "Too many arguments\n");
        fprintf(stderr, "Usage: ./flip_nth_bit <input> <k>\n");
        return 1;
    }
    return 0;
}
