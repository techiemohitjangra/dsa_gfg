#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int64_t one_odd_occurence(size_t size, int64_t *arr);

int64_t one_odd_occurence(size_t size, int64_t *arr) {
    int64_t result = arr[0];
    for (size_t i = 1; i < size; i++) {
        result ^= arr[i];
    }
    return result;
}

int32_t main(int32_t argc, char **argv) {

    int64_t size;
    char *temp;
    if (argc >= 2) {
        size = argc - 1;
        int64_t arr[size];
        for (size_t i = 0; i < size; i++) {
            arr[i] = strtoll(argv[i + 1], &temp, 10);
        }
        printf("%ld\n", one_odd_occurence(size, arr));
    } else {
        fprintf(stderr, "Too few arguments\n");
        fprintf(
            stderr,
            "Usage: ./one_odd_occurence <space saperated array elements>\n");
        return 1;
    }

    return 0;
}
