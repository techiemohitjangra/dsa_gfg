#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *primeFactors(uint64_t number) {
    uint64_t *factors = (uint64_t *)calloc(0, sizeof(uint64_t));
    int *temp;
    int size = 0;
    while (number % 2 == 0) {
        number /= 2;
        ++size;
        temp = (int *)realloc(factors, size);
        if (temp != NULL) {
            factors[size - 1] = 2;
        } else {
            free(factors);
            factors = NULL;
            printf("2 ");
        }
    }
    while (number % 3 == 0) {
        number /= 3;
        ++size;
        temp = (int *)realloc(factors, size);
        if (temp != NULL) {
            factors[size - 1] = 3;
        } else {
            free(factors);
            factors = NULL;
            printf("3 ");
        }
    }
    for (int i = 5; i <= number; i += 6) {
        while (number % i == 0) {
            number /= i;
            ++size;
            temp = (int *)realloc(factors, size);
            if (temp != NULL) {
                factors[size - 1] = i;
            } else {
                free(factors);
                factors = NULL;
                printf("%d ", i);
            }
        }
        while (number % (i + 2) == 0) {
            number /= (i + 2);
            ++size;
            temp = (int *)realloc(factors, size);
            if (temp != NULL) {
                factors[size - 1] = i + 2;
            } else {
                free(factors);
                factors = NULL;
                printf("%d ", i + 2);
            }
        }
    }
    char *str = (char *)calloc(1, sizeof(char));
    str[0] = '\0';
    char num[32];
    for (int i = 0; i < size - 1; i++) {
        sprintf(num, "%lu, ", factors[i]);
        strcat(str, num);
    }
    sprintf(num, "%lu", factors[size - 1]);
    strcat(str, num);
    return str;
}

int main(int argc, char **argv) {
    uint64_t number;
    char *result;
    char *temp;

    if (argc > 2) {
        fprintf(stderr, "Too many Arguments\n");
        fprintf(stderr, "Usage: ./primeFactors <input>\n");
        return 1;
    } else if (argc == 2) {
        number = strtof(argv[1], &temp);
        result = primeFactors(number);
        printf("%lu is %s\n", number, result);
    } else {
        fprintf(stderr, "Not Enough Arguments\n");
        fprintf(stderr, "Usage: ./primeFactors <input>\n");
        return 1;
    }

    return 0;
}
