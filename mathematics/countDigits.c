#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint_fast8_t countDigits(long number) {
    uint_fast8_t count = 0;
    while (number != 0) {
        count++;
        number /= 10;
    }
    return count;
}

int main(int argc, char **argv) {

    long num;
    uint_fast8_t count;
    char *temp;
    if (argc > 1) {
        num = strtol(argv[1], &temp, 10);
        count = countDigits(num);
        printf("Number of digits in %ld is %u\n", num, count);
    } else {
        fprintf(stderr, "Not enough arguments.\n");
        fprintf(stderr, "Usage: ./countDigits <value>\n");
        return 1;
    }
    return 0;
}
