#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int64_t not(int64_t);

int64_t not(int64_t first) { return ~first; }

int32_t main(int32_t argc, char **argv) {

    int64_t input;
    char *temp;
    if (argc == 2) {
        input = strtoll(argv[1], &temp, 10);
        printf("~%ld = %ld\n", input, not(input));
    } else if (argc < 2) {
        fprintf(stderr, "Too few arguments\n");
        fprintf(stderr, "Usage: ./bitwise_not <input>\n");
        return 1;
    } else {
        fprintf(stderr, "Too many arguments\n");
        fprintf(stderr, "Usage: ./bitwise_not <input>\n");
        return 1;
    }
    return 0;
}
