#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int64_t set_MSB(int64_t);

int64_t set_MSB(int64_t input) {
    int64_t result = 1;
    while (input >>= 1) {
        result <<= 1;
    }
    return result;
}

int32_t main(int32_t argc, char **argv) {

    int64_t first;
    char *temp;
    if (argc == 2) {
        first = strtoll(argv[1], &temp, 10);
        printf("%ld\n", set_MSB(first));
    } else if (argc < 2) {
        fprintf(stderr, "Too few arguments\n");
        fprintf(stderr, "Usage: ./set_MSB <input>\n");
        return 1;
    } else {
        fprintf(stderr, "Too many arguments\n");
        fprintf(stderr, "Usage: ./set_MSB <input>\n");
        return 1;
    }
    return 0;
}
