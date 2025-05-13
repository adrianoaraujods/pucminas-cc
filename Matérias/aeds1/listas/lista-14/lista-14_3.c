#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Construa uma versão da função anterior de forma que os limites inferior e superior sejam parametrizados.
// Teste a sua função a partir da main(). Para testá-la, faça de forma que os limites inferior e superior sejam valores lidos. Para isto, construa uma função que leia e retorne um valor inteiro fornecido pelo teclado.

void recursive(int n, int min, int max) {
  if (n <= max) {
    printf("%i, ", n);
    recursive(n + 1, min, max);

    if (n >= min) {
      printf("%i, ", n);
    }
  }
}

int readInt() {
  int number;
  scanf(" %i", &number);

  return number;
}

void main() {
  printf("\nEnter the maximum number: ");
  int max = readInt();

  printf("\nEnter the mininum number: ");
  int min = readInt();

  recursive(1, min, max);
}