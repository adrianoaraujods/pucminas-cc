#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Crie uma função recursiva que calcule o fatorial de um número natural N.

int factorial(int n) {
  int acc = 1;

  if (n > 0) {
    acc = n * factorial(n - 1);
  }

  return acc;
}

void main() // for testing
{
  printf("\nResult: %i", factorial(-3));
}