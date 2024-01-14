#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

bool isPrime(uint64_t number) {
    if (number <= 1) {
        return false;
    }
    if (number == 2 || number == 3) {
        return true;
    }
    if (number % 2 == 0 || number % 3 == 0) {
        return false;
    }
    for (int i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

uint64_t exactlyThreeDivisors(uint64_t number) {
    uint64_t count = 0;
    number = sqrt(number);
    for (int i = 2; i <= number; i++) {

        if (isPrime(i)) {
            count++;
        }
    }
    return count;
}

int main(int argc, char **argv) {
    uint64_t number;
    char *temp;
    if (argc > 1) {
        number = strtof(argv[1], &temp);
        printf("%lu number less then %lu have exactly three divisors.\n", exactlyThreeDivisors(number), number);
    } else {
        fprintf(stderr, "Not Enough Arguments\n");
        fprintf(stderr, "Usage: ./exactlyThreeDivisors <input>\n");
        return 1;
    }

    return 0;
}
