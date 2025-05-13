#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Construa uma função recursiva que escreva na tela a sequência abaixo:
// 1, 2, 3, 4, 5,

void recursive(int n) {
  printf("%i, ", n);

  if (n < 5) {
    recursive(n + 1);
  }
}

void main() {
  recursive(1);
}