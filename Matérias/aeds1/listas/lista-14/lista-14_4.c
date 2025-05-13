#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Construa uma função recursiva que escreva em ordem decrescente os inteiros de N até 0.
// Argumento da função: um inteiro relativo ao valor de N.
// Retorno: vazio
// Teste a sua função a partir da função principal. Planeje uma função específica para ler do teclado o valor de N.

void recursive(int n) {
  if (n >= 0) {
    printf("%i, ", n);

    recursive(n - 1);
  }
}

int readInt() {
  int number;
  printf("\nEnter a number: ");
  scanf(" %i", &number);

  return number;
}

void main() {
  int n = readInt();

  recursive(n);
}