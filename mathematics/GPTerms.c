#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

double nthTerm(uint64_t A, uint64_t B, uint64_t N) {
    if (N == 1) {
        return A;
    }
    if (N == 2) {
        return B;
    }

    double R = (double)B / A;
    return (double)A * pow(R, (N - 1));
}

int main(int argc, char **argv) {
    uint64_t A, B, N;
    char *temp;
    if (argc == 4) {
        A = strtol(argv[1], &temp, 10);
        B = strtol(argv[2], &temp, 10);
        N = strtoul(argv[3], &temp, 10);
        printf("%lu%s the term of the GP whose first and second term are %lu and %lu is %.3lf\n", N,
               (N % 10 == 1     ? "st"
                : (N % 10 == 2) ? "nd"
                : (N % 10 == 3) ? "rd"
                                : "th"),
               A, B, nthTerm(A, B, N));
    } else if (argc < 4) {
        fprintf(stderr, "Not Enough Arguments\n");
        fprintf(stderr, "Usage: ./GPTerms <input1> <input2> <input3>\n");
        return 1;
    } else {
        fprintf(stderr, "Too many Arguments\n");
        fprintf(stderr, "Usage: ./GPTerms <A:input1> <B:input2> <N:input3>\n");
        return 1;
    }
    return 0;
}
