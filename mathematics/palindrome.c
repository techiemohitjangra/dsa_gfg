#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

bool isPalindrome(uint64_t number) {
    uint64_t reverse = 0;
    uint64_t temp = number;
    while (temp) {
        reverse = (reverse * 10) + temp % 10;
        temp /= 10;
    }
    return reverse == number;
}

int main(int argc, char **argv) {
    uint64_t number;
    char *temp;
    if (argc < 2) {
        fprintf(stderr, "Not Enough Arguments\n");
        fprintf(stderr, "Usage: ./palindrome <input>\n");
        exit(EXIT_FAILURE);
    } else {
        number = strtol(argv[1], &temp, 10);
        if (isPalindrome(number)) {
            printf("%lu is a palindrome\n", number);
        } else {
            printf("%lu is not a palindrome\n", number);
        }
    }
    return 0;
}
