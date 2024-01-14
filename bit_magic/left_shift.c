#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int64_t left_shift(int64_t, int64_t);

int64_t left_shift(int64_t input, int64_t offset) { return input << offset; }

int32_t main(int32_t argc, char **argv) {

    int64_t first, second;
    char *temp;
    if (argc == 3) {
        first = strtoll(argv[1], &temp, 10);
        second = strtoll(argv[2], &temp, 10);
        printf("%ld << %ld = %ld\n", first, second, left_shift(first, second));
    } else if (argc < 3) {
        fprintf(stderr, "Too few arguments\n");
        fprintf(stderr, "Usage: ./left_shift <firstOperand> <secondOperand>\n");
        return 1;
    } else {
        fprintf(stderr, "Too many arguments\n");
        fprintf(stderr, "Usage: ./left_shift <firstOperand> <secondOperand>\n");
        return 1;
    }
    return 0;
}
