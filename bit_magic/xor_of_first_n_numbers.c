#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int64_t xor_of_n_numbers(int64_t);

int64_t xor_of_n_numbers(int64_t input) {
    switch (input % 4) {
    case 0:
        return input;
    case 1:
        return 1;
    case 2:
        return input + 1;
    case 3:
        return 0;
    default:
        return -1;
    }
    return -1;
}

int32_t main(int32_t argc, char **argv) {

    int64_t first;
    char *temp;
    if (argc == 2) {
        first = strtoll(argv[1], &temp, 10);
        printf("%ld\n", xor_of_n_numbers(first));
    } else if (argc < 2) {
        fprintf(stderr, "Too few arguments\n");
        fprintf(stderr, "Usage: ./xor_of_n_numbers <input> <k>\n");
        return 1;
    } else {
        fprintf(stderr, "Too many arguments\n");
        fprintf(stderr, "Usage: ./xor_of_n_numbers <input> <k>\n");
        return 1;
    }
    return 0;
}
