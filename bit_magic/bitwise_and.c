#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int64_t and (int64_t, int64_t);

int64_t and (int64_t first, int64_t second) { return first & second; }

int32_t main(int32_t argc, char **argv) {

    int64_t first, second;
    char *temp;
    if (argc == 3) {
        first = strtoll(argv[1], &temp, 10);
        second = strtoll(argv[2], &temp, 10);
        printf("%ld & %ld = %ld\n", first, second, and(first, second));
    } else if (argc < 3) {
        fprintf(stderr, "Too few arguments\n");
        fprintf(stderr,
                "Usage: ./bitwise_and <firstOperand> <secondOperand>\n");
        return 1;
    } else {
        fprintf(stderr, "Too many arguments\n");
        fprintf(stderr,
                "Usage: ./bitwise_and <firstOperand> <secondOperand>\n");
        return 1;
    }
    return 0;
}
