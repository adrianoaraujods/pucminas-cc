#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LENGTH 255

void readln(char string[]) {
  fgets(string, MAX_LENGTH, stdin);

  const unsigned len = strlen(string);

  if (len > 0 && string[len - 1] == '\n') {
    string[len - 1] = '\0';
  }
}

bool isPalindrome(char string[]) {
  bool palindrome = true;
  int start = 0, end = (int) strlen(string) - 1;

  while (start < end) {
    if (string[start] != string[end]) {
      palindrome = false;
      end = 0;
    }

    start++;
    end--;
  }

  return palindrome;
}

int main() {
  char line[MAX_LENGTH];
  readln(line);

  while (strcmp("FIM", line) != 0) {
    printf("%s\n", isPalindrome(line) ? "SIM" : "NAO");;

    readln(line);
  }

  return 0;
}
