#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Crie uma versão recursiva para o algoritmo que trata o problema do cálculo da potenciação.

int power(int base, int expoent) {
  expoent--;

  if (expoent > 0) {
    return base * power(base, expoent);
  }
}

void main() // for testing
{
  printf("\nResult: %i", power(2, 5));
}