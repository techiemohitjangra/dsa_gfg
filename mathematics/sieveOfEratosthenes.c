#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sieve(uint64_t number);

void sieve(uint64_t number) {
    bool isPrime[number + 1];
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = false;
    isPrime[1] = false;

    for (size_t i = 2; i <= number; i++) {
        if (isPrime[i]) {
            printf("%zu ", i);
            for (size_t j = i * i; j <= number; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int main(int argc, char **argv) {
    uint64_t number;
    char *temp;
    if (argc == 2) {
        number = strtoul(argv[1], &temp, 10);
        printf("Prime numbers up to %lu are ", number);
        sieve(number);
        printf("\n");
    } else if (argc <= 2) {
        fprintf(stderr, "Not Enough Arguments\n");
        fprintf(stderr, "Usage: ./sieveOfEratosthenes <input>\n");
        return 1;
    } else {
        fprintf(stderr, "Too many Arguments\n");
        fprintf(stderr, "Usage: ./sieveOfEratosthenes <input>\n");
        return 1;
    }
    return 0;
}
