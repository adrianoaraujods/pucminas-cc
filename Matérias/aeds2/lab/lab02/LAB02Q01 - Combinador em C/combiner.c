#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 512

void combiner(char string1[], char string2[], char result[]) {
  char *larger, *smaller;

  if (strlen(string1) >= strlen(string2)) {
    larger = string1;
    smaller = string2;
  } else {
    larger = string2;
    smaller = string1;
  }

  int i = 0;

  while (i < strlen(smaller)) {
    result[(i * 2)] = string1[i];
    result[(i * 2) + 1] = string2[i];

    i++;
  }

  while (i < strlen(larger)) {
    result[strlen(smaller) + i] = larger[i];

    i++;
  }

  result[strlen(smaller) + i] = '\0';
}

int main() {
  char string1[MAX_LENGTH];
  char string2[MAX_LENGTH];

  while (scanf("%s %s", string1, string2) != EOF) {
    char result[MAX_LENGTH * 2];
    combiner(string1, string2, result);

    printf("%s\n", result);
  }

  return 0;
}
