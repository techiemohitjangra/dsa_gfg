#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint64_t gcd(uint64_t first, uint64_t second) {
    if (second == 0) {
        return first;
    } else {
        return gcd(second, first % second);
    }
}
uint64_t lcm(uint64_t first, uint64_t second) { return (first * second) / gcd(first, second); }

int main(int argc, char **argv) {
    int64_t first, second;
    char *temp;
    if (argc == 3) {
        first = strtol(argv[1], &temp, 10);
        second = strtol(argv[2], &temp, 10);
        printf("LCM of %lu and %lu is %lu\n", first, second, lcm(first, second));
    } else if (argc < 3) {
        fprintf(stderr, "Not Enough arguments\n");
        fprintf(stderr, "Usage: ./lcm <input1> <input2>\n");
        return 1;
    } else {
        fprintf(stderr, "Too many arguments\n");
        fprintf(stderr, "Usage: ./lcm <input1> <input2>\n");
        return 1;
    }
    return 0;
}
