#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int64_t _log2(int64_t);

int64_t _log2(int64_t input) {
    int64_t result = 0;
    while (input >>= 1) {
        result++;
    }
    return result;
}

int32_t main(int32_t argc, char **argv) {

    int64_t first;
    char *temp;
    if (argc == 2) {
        first = strtoll(argv[1], &temp, 10);
        printf("log2(%ld) = %ld\n", first, _log2(first));
    } else if (argc < 2) {
        fprintf(stderr, "Too few arguments\n");
        fprintf(stderr, "Usage: ./log2 <input>\n");
        return 1;
    } else {
        fprintf(stderr, "Too many arguments\n");
        fprintf(stderr, "Usage: ./log2 <input>\n");
        return 1;
    }
    return 0;
}
