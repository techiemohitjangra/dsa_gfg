#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

bool is_power_of_2(int64_t);

bool is_power_of_2(int64_t input) {
    if (input == 0)
        return false;
    return ((input & (input - 1)) == 0);
}

int32_t main(int32_t argc, char **argv) {
    int64_t input;
    char *temp;
    if (argc == 2) {
        input = strtol(argv[1], &temp, 10);
        printf("%ld is %s\n", input,
               (is_power_of_2(input) ? "power of 2" : "is not power of 2"));
    } else if (argc < 2) {
        fprintf(stderr, "Too few arguments\n");
        fprintf(stderr, "Usage: ./is_power_of_2 <input>\n");
        return 1;
    } else {
        fprintf(stderr, "Too many arguments\n");
        fprintf(stderr, "Usage: ./is_power_of_2 <input>\n");
        return 1;
    }
    return 0;
}
