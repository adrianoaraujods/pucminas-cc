#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 255

void readln(char string[]) {
    fgets(string, MAX_LENGTH, stdin);

    const unsigned len = strlen(string);

    if (len > 0 && string[len - 1] == '\n') {
        string[len - 1] = '\0';
    }
}

int parseInt(char character) {
    return character - '0';
}

int digitsSumRecursive(char string[], int sum, const unsigned short index) {
    int result = parseInt(string[index]);

    if (index > 0) {
        result += digitsSumRecursive(string, result, index - 1);
    }

    return result;
}

int digitsSum(char string[]) {
    return digitsSumRecursive(string, 0, strlen(string) - 1);
}

int main(){
    char line[MAX_LENGTH];
    readln(line);

    while (strcmp("FIM", line) != 0) {
        printf("%d\n", digitsSum(line));

        readln(line);
    }

    return 0;
}
