#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/*
  Faça  uma  função  chamada  primo  que  recebe  como  parâmetro  um  inteiro  m,  passado por valor, e dois outros inteiros, p1 e p2, passados por referência. A função deve representar em p1 o  maior número  primo  menor  do que  m  e  deve  representar  em  p2 o  menor número  primo  maior do que m.
*/

bool numberIsPrime(int number) {
  int i = 2;
  bool numberIsPrime = true;
  int numberSqrt = (int)sqrt(number);

  while (i <= numberSqrt && numberIsPrime) {
    if (number % i == 0) {
      numberIsPrime = false;
    }

    i++;
  }

  return numberIsPrime;
}

void primo(int m, int* p1, int* p2) {
  for (int number = 1; number < m; number++) {
    if (numberIsPrime(number)) {
      *p1 = number;
    }
  }

  *p2 = 0;

  while (*p2 == 0) {
    m++;

    if (numberIsPrime(m)) {
      *p2 = m;
    }
  }
}

int main() {
  int p1;
  int p2;

  primo(10, &p1, &p2);

  printf("p1 = %i; p2 = %i", p1, p2);

  return 0;
}