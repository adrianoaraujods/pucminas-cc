#include <stdio.h>
// #include <string.h>

/*
  2. Escrever uma string de forma invertida. Por exemplo, a palavra ROMA deverá ser escrita como AMOR.
    a) Abordagem iterativa
    b) Abordagem recursiva
*/

void stringPrintInverted_Iterative(char string[]) {
  int i = 0;

  while (string[i] != '\0') i++;

  while (i >= 0) {
    printf("%c", string[i]);

    i--;
  }
}

void recursion(char string[], int i) {
  if (string[i] == '\0') {
    printf("\n");
  } else {
    recursion(string, i + 1);

    printf("%c", string[i]);
  }
}

void stringPrintInverted_Recursive(char string[]) {
  recursion(string, 0);
}

int main() {
  char string[] = "ROMA";

  stringPrintInverted_Iterative(string);

  printf("\n\n");

  stringPrintInverted_Recursive(string);

  return 0;
}