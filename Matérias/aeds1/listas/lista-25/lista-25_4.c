#include <stdio.h>

/*
  4. Construa uma função que calcule o tamanho de uma string.
    a) Abordagem iterativa
    b) Abordagem recursiva
*/

int stringLenght_Iterative(char* string) {
  int lenght = 0;

  while (string[lenght] != '\0') {
    lenght++;
  }

  return lenght;
}

int stringLenght_Recursion(char* string, int lenght) {
  if (string[lenght] != '\0') {
    lenght = stringLenght_Recursion(string, lenght + 1);
  }

  return lenght;
}

int stringLenght(char* string) {
  return stringLenght_Recursion(string, 0);
}

int main() {
  printf("\nLenght: %i", stringLenght_Iterative("a"));
  printf("\nLenght: %i", stringLenght("abs"));

  return 0;
}