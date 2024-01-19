#include <errno.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint32_t count_matching(uint32_t, size_t, uint32_t *);
uint32_t max_and_value(size_t, uint32_t *);

uint32_t count_matching(uint32_t pattern, size_t size, uint32_t *arr) {
    uint32_t count = 0;
    for (size_t i = 0; i < size; i++) {
        if ((pattern & arr[i]) == pattern) {
            count++;
        }
    }
    return count;
}

uint32_t max_and_value(size_t size, uint32_t *arr) {
    uint32_t result = 0;
    uint32_t count = 0;
    for (int32_t i = 18; i >= 0; i--) {
        count = count_matching(result | (1 << i), size, arr);
        if (count >= 2) {
            result = result | (1 << i);
        }
    }
    return result;
}

int32_t main(int32_t argc, char **argv) {

    char *endptr;
    size_t size, iter;
    if (argc > 2) {
        errno = 0;
        size = strtoul(argv[1], &endptr, 10);
        if (errno == ERANGE && size == ULONG_MAX) {
            fprintf(stderr, "%s: Value overflow\n", argv[1]);
            exit(EXIT_FAILURE);
        }
        if (errno != 0) {
            perror("strtoul");
            exit(EXIT_FAILURE);
        }
        if (endptr == argv[1]) {
            fprintf(stderr, "No digits were found\n");
            exit(EXIT_FAILURE);
        }
        if (*endptr != '\0') {
            printf("Further characters after the number \"%s\"\n", endptr);
        }
        uint32_t arr[size];
        iter = 0;
        while (iter < (argc - 2) && iter < size) {
            errno = 0;
            arr[iter] = strtoul(argv[iter + 2], &endptr, 10);
            if (errno == ERANGE && size == ULONG_MAX) {
                fprintf(stderr, "%s: Value overflow\n", argv[iter + 2]);
                exit(EXIT_FAILURE);
            }
            if (errno != 0) {
                perror("strtoul");
                exit(EXIT_FAILURE);
            }
            if (endptr == argv[iter + 2]) {
                fprintf(stderr, "No digits were found\n");
                exit(EXIT_FAILURE);
            }
            if (*endptr != '\0') {
                printf("Further characters after the number \"%s\"\n", endptr);
            }
            iter++;
        }

        printf("%u\n", max_and_value(size, arr));
        exit(EXIT_SUCCESS);
    } else {
        fprintf(stderr, "Too few arguments\n");
        fprintf(stderr, "Usage: %s <number_of_elements> ...", argv[0]);
    }
    return 0;
}
