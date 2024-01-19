#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

bool kth_bit_check(int64_t, uint8_t);

bool kth_bit_check(int64_t input, uint8_t k) { return input & (1 << (k - 1)); }

int32_t main(int32_t argc, char **argv) {

    int64_t first;
    uint8_t second;
    char *temp;
    if (argc == 3) {
        first = strtoll(argv[1], &temp, 10);
        second = strtoll(argv[2], &temp, 10);
        printf("%ld << %d = %d\n", first, second, kth_bit_check(first, second));
    } else if (argc < 3) {
        fprintf(stderr, "Too few arguments\n");
        fprintf(stderr, "Usage: ./kth_bit_check <input> <k>\n");
        return 1;
    } else {
        fprintf(stderr, "Too many arguments\n");
        fprintf(stderr, "Usage: ./kth_bit_check <input> <k>\n");
        return 1;
    }
    return 0;
}
