#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int64_t first;
    int64_t second;
} Pair;

Pair two_odd_occurence(size_t size, int64_t *arr);

Pair two_odd_occurence(size_t size, int64_t *arr) {
    Pair result;
    result.first = result.second = 0;

    int64_t temp = arr[0];
    for (size_t i = 1; i < size; i++) {
        temp ^= arr[i];
    }
    int64_t k = temp & ~(temp - 1);
    for (size_t i = 0; i < size; i++) {
        if ((arr[i] & k) != 0) {
            result.first ^= arr[i];
        } else {
            result.second ^= arr[i];
        }
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
        Pair result = two_odd_occurence(size, arr);
        printf("%ld %ld\n", result.first, result.second);
    } else {
        fprintf(stderr, "Too few arguments\n");
        fprintf(
            stderr,
            "Usage: ./two_odd_occurence <space saperated array elements>\n");
        return 1;
    }

    return 0;
}
