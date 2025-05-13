#include <stdio.h>
#include <stdlib.h>

/*
  4. Construa algoritmos para calcular o k-ésimo termo Fibonacci utilizando as abordagens abaixo. Antes de iniciar a codificação, busque e planeje, cuidadosamente, as estratégias que o algoritmo deverá adotar.

  a) Algoritmo iterativo
*/

int getFibonacciTerm(int k) {
  int temp = 0;
  int a = 0;
  int b = 1;

  for (int i = 0; i < k; i++) {
    temp = a + b;

    a = b;
    b = temp;
  }

  return temp;
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