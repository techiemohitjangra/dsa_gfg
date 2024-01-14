#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void roots(int32_t a, int32_t b, int32_t c) {
    int32_t d;
    float_t first, root1, root2;
    double_t sqrtd;
    d = (b * b) - 4 * a * c;
    if (d < 0) {
        first = (-b / ((double_t)2 * a));
        sqrtd = sqrt(abs(d)) / ((double)2 * a);
        printf("%.3f+%.5lfi and %.3f-%.5lfi\n", first, sqrtd, first, sqrtd);
    } else {
        root1 = (-b - sqrt(d)) / (2 * a);
        root2 = (-b + sqrt(d)) / (2 * a);
        printf("%.3f and %.3f\n", root1, root2);
    }
}

int main(int argc, char **argv) {
    int32_t a, b, c;
    char *temp;
    if (argc == 1) {
        fprintf(stderr, "Not Enough Arguments\n");
        fprintf(stderr, "Usage: ./quadraticRoots <input1> <input2> <input3>\n");
        return 1;
    } else if (argc == 4) {
        a = strtol(argv[1], &temp, 10);
        b = strtol(argv[2], &temp, 10);
        c = strtol(argv[3], &temp, 10);
        printf("Roots of equation (%dx^2 + %dx + %d) are ", a, b, c);
        roots(a, b, c);
    } else {
        fprintf(stderr, "Invalid use\n");
        fprintf(stderr, "Usage: ./quadraticRoots <input1> <input2> <input3>\n");
        return 1;
    }
    return 0;
}
