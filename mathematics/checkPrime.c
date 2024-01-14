#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

bool isPrime(uint64_t);

bool isPrime(uint64_t number) {
    // 1 is not prime
    if (number == 1) {
        return false;
    }

    // 2 and 3 are prime
    if (number == 2 || number == 3) {
        return true;
    }

    // multiple of 2 and 3 are eliminated as they are not prime
    if (number % 2 == 0 || number % 3 == 0) {
        return false;
    }

    // check if number is multiple of prime smaller then sqrt(number)
    for (int i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) {
            return false;
        }
    }

    return true;
}

int main(int argc, char **argv) {
    int64_t number;
    char *temp;
    bool prime;
    if (argc > 1) {
        number = strtol(argv[1], &temp, 10);
        prime = isPrime(number);
        if (prime) {
            printf("%lu is a prime number\n", number);

        } else {
            printf("%lu is not a prime number\n", number);
        }
    } else {
        fprintf(stderr, "Not Enough arguments\n");
        fprintf(stderr, "Usage: ./checkPrime <input>\n");
        return 1;
    }
    return 0;
}
