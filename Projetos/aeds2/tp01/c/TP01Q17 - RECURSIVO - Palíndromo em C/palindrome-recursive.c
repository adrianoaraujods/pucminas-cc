#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LENGTH 512

void readln(char string[]) {
    fgets(string, MAX_LENGTH, stdin);

    const unsigned len = strlen(string);

    if (len > 0 && string[len - 1] == '\n') {
        string[len - 1] = '\0';
    }
}

bool isPalindromeRecursion(char string[], const unsigned short start, const unsigned short end) {
    bool palindrome = false;

    if (string[start] == string[end]) {
        if (start < end) {
            palindrome = isPalindromeRecursion(string, start + 1, end - 1);
        } else {
            palindrome = true;
        }
    }

    return palindrome;
}

bool isPalindrome(char string[]) {
    return isPalindromeRecursion(string, 0, strlen(string) - 1);
};

int main() {
    char line[MAX_LENGTH];
    readln(line);

    while (strcmp("FIM", line) != 0) {
        printf("%s\n", isPalindrome(line) ? "SIM" : "NAO");

        readln(line);
    }

    return 0;
}
