#include <stdint.h>
#include <stdio.h>
#include <string.h>

void power_set(char *str);

void power_set(char *str) {
    size_t len = strlen(str);
    int64_t pSize = (1 << len);
    for (size_t i = 0; i < pSize; i++) {
        printf("%lu ", i+1);
        for (size_t j = 0; j < len; j++) {
            if ((i & (1 << j)) != 0) {
                printf("%c", str[j]);
            }
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    char *temp;
    if (argc == 2) {
        power_set(argv[1]);
    } else if (argc < 2) {
        fprintf(stderr, "Too few arguments\n");
        fprintf(stderr, "Usage: ./power_set <input_string>\n");
        return 1;
    } else {
        fprintf(stderr, "Too many arguments\n");
        fprintf(stderr, "Usage: ./power_set <input_string>\n");
        return 1;
    }
    return 0;
}
