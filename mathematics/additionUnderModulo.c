#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int64_t modularMultiplicativeInverse(int64_t, int64_t);

int64_t modularMultiplicativeInverse(int64_t first, int64_t second) {
    int64_t mod = 1e9 + 7;
    return ((first % mod) + (second % mod)) % mod;
}

int32_t main(int32_t argc, char **argv) {
    int64_t first, second;
    char *temp;
    if (argc == 3) {
        first = strtoul(argv[1], &temp, 10);
        second = strtoul(argv[2], &temp, 10);
        printf("(%li + %li) mod %lu is %li", first, second, (uint64_t)(1e9 + 7), modularMultiplicativeInverse(first, second));
        printf("\n");
    } else if (argc <= 3) {
        fprintf(stderr, "Not Enough Arguments\n");
        fprintf(stderr, "Usage: ./additionUnderModulo <input1> <input2>\n");
        return 1;
    } else {
        fprintf(stderr, "Too many Arguments\n");
        fprintf(stderr, "Usage: ./additionUnderModulo <input1> <input2>\n");
        return 1;
    }
    return 0;
}
