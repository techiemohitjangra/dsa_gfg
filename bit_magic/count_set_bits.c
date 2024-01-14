#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint8_t count_set_bits(int64_t);

uint8_t count_set_bits(int64_t input) {
    uint8_t count = 0;
    while (input > 0) {
        input = input & (input - 1);
        count++;
    }
    return count;
}

int8_t tbl[256];
void init() {
    tbl[0] = 0;
    for (uint16_t i = 1; i < 256; i++) {
        tbl[i] = tbl[(i & (i - 1))] + 1;
    }
}

uint8_t count_set_bits_const_time(int64_t input) {
    return tbl[input & 255] + tbl[(input >> 8) & 255] +
           tbl[(input >> 16) & 255] + tbl[(input >> 24) & 255] +
           tbl[(input >> 32) & 255] + tbl[(input >> 40) & 255] +
           tbl[(input >> 48) & 255] + tbl[(input >> 56)];
}

int32_t main(int32_t argc, char **argv) {
    int64_t first;
    char *temp;
    if (argc == 2) {
        first = strtoll(argv[1], &temp, 10);
        init();
        printf("(O(log n)) Set bits in %ld is %d\n", first,
               count_set_bits(first));
        printf("(O(1))     Set bits in %ld is %d\n", first,
               count_set_bits_const_time(first));
    } else if (argc < 2) {
        fprintf(stderr, "Too few arguments\n");
        fprintf(stderr, "Usage: ./count_set_bits <input>\n");
        return 1;
    } else {
        fprintf(stderr, "Too many arguments\n");
        fprintf(stderr, "Usage: ./count_set_bits <input>\n");
        return 1;
    }
    return 0;
}
