#include <stdio.h>
#include <stdlib.h>

/*
  4. Construa algoritmos para calcular o k-ésimo termo Fibonacci utilizando as abordagens abaixo. Antes de iniciar a codificação, busque e planeje, cuidadosamente, as estratégias que o algoritmo deverá adotar.

  b) Algoritmo recursivo
*/

int getFibonacciTerm(int k) {
  int term = 0;

  if (k >= 0) {
    switch (k) {
    case 0:
      term = 0;
      break;
    case 1:
      term = 1;
      break;
    default:
      term = getFibonacciTerm(k - 2) + getFibonacciTerm(k - 1);
      break;
    }
  }

  return term;
}

int main() {
  printf("\n%i", getFibonacciTerm(0));
  printf("\n%i", getFibonacciTerm(1));
  printf("\n%i", getFibonacciTerm(2));
  printf("\n%i", getFibonacciTerm(3));
  printf("\n%i", getFibonacciTerm(4));
  printf("\n%i", getFibonacciTerm(5));

  return 0;
}