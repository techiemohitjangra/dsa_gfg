#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int64_t modularMultiplicativeInverse(int64_t, int64_t);

int64_t modularMultiplicativeInverse(int64_t a, int64_t m) {
    for (size_t i = 0; i < m; i++) {
        if (((a % m) * (i % m)) % m == 1) {
            return i;
        }
    }
    return -1;
}

int32_t main(int32_t argc, char **argv) {
    int64_t first, second;
    char *temp;
    if (argc == 3) {
        first = strtoul(argv[1], &temp, 10);
        second = strtoul(argv[2], &temp, 10);
        printf("(%li + %li) mod %lu is %li", first, second, (uint64_t)(1e9 + 7),
               modularMultiplicativeInverse(first, second));
        printf("\n");
    } else if (argc <= 3) {
        fprintf(stderr, "Not Enough Arguments\n");
        fprintf(stderr, "Usage: ./modularMultiplicativeInverse <input1> <input2>\n");
        return 1;
    } else {
        fprintf(stderr, "Too many Arguments\n");
        fprintf(stderr, "Usage: ./modularMultiplicativeInverse <input1> <input2>\n");
        return 1;
    }
    return 0;
}
