#include <stdio.h>
#include <stdlib.h>

float celsiusToFahrenheit(float celsius) { return (celsius * (float)9 / (float)5) + 32; }

int main(int argc, char **argv) {
    float celsius, fahrenheit;
    char *temp;
    if (argc > 1) {
        celsius = strtof(argv[1], &temp);
        fahrenheit = celsiusToFahrenheit(celsius);
        printf("%.1f°C is %.1f°F\n", celsius, fahrenheit);
    } else {
        fprintf(stderr, "Not Enough Arguments\n");
        fprintf(stderr, "Usage: ./celsiusToFahrenheit <input>\n");
        return 1;
    }
    return 0;
}
