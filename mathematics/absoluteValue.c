#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint64_t absoluteValue(int64_t number) { return labs(number); }

int main(int argc, char **argv) {
    int64_t number;
    char *temp;
    if (argc > 1) {
        number = strtoll(argv[1], &temp, 10);
        printf("Absolute value for %ld is %lu\n", number, absoluteValue(number));
    } else {
        fprintf(stderr, "Not Enough arguments\n");
        fprintf(stderr, "Usage: ./absoluteValue <input>");
        return 1;
    }
    return 0;
}
