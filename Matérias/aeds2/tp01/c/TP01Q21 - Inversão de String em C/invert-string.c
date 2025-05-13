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

void printChars(char string[], int index) {
  printf("%c", string[index]);

  if (index > 0) {
    printChars(string, index - 1);
  }
}

void printString(char string[]) {
  printChars(string, strlen(string) - 1);
  printf("\n");
}

int main(){
  char line[MAX_LENGTH];
  readln(line);

  while (strcmp("FIM", line) != 0) {
    printString(line);

    readln(line);
  }

  return 0;
}