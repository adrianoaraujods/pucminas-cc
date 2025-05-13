#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Crie uma função recursiva que calcule a soma dos números inteiros de n até m, sendo n e m limites inferior e superior, respectivamente.
// Planeje, cuidadosamente, sua solução, de forma que as funções implementem funcionalidades atômicas.

int recursive(int n, int m) {
  int sum = 0;

  if (n <= m) {
    sum = n + recursive(n + 1, m);
  }

  return sum;
}

void main() // for testing
{
  printf("\nSum: %i", recursive(1, 0));
}