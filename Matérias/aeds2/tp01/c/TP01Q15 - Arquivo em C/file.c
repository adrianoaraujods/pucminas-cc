#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "numbers.temp"
#define MAX_lENGTH 64

void writeFile(int n) {
    FILE *file;

    if ((file = fopen(FILENAME, "w")) != NULL) {
        double number;

        for (int i = 0; i < n; i++) {
            scanf("%lf\n", &number);

            fprintf(file, "\n%f", number);
        }

        fclose(file);
    }
}

void readFileBackwards(int n) {
    FILE *file;

    if ((file = fopen(FILENAME, "r")) != NULL) {
        fseek(file, 0, SEEK_END);
        long bytes = ftell(file);

        char buffer[MAX_lENGTH];
        int bufferIndex = 0;
        bool trailingZeros = true;

        while (bytes > 0) {
            bytes--;
            fseek(file, bytes, SEEK_SET);
            char character = fgetc(file);

            if (character == '0') {
                if (!trailingZeros) {
                    buffer[bufferIndex] = character;
                    bufferIndex++;
                }
            } else if (character == '.') {
                if (trailingZeros) {
                    trailingZeros = false;
                } else {
                    buffer[bufferIndex] = character;
                    bufferIndex++;
                }
            } else if (character != '\n') {
                trailingZeros = false;
                buffer[bufferIndex] = character;
                bufferIndex++;
            } else {
                while (bufferIndex > 0) {
                    printf("%c", buffer[bufferIndex - 1]);
                    bufferIndex--;
                }

                printf("\n");

                trailingZeros = true;
            }
        }

        fclose(file);
    }
}

int main() {
    int n;

    scanf("%d", &n);

    writeFile(n);
    readFileBackwards(n);

    return 0;
}