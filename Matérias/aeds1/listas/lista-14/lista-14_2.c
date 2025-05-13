#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Construa uma função recursiva que escreva na tela a sequência abaixo:
// 1, 2, 3, 4, 5, 5, 4, 3, 2, 1,

void recursive(int n) {
  if (n <= 5) {
    printf("%i, ", n);
    recursive(n + 1);
    printf("%i, ", n);
  }
}

void main() {
  recursive(1);
}