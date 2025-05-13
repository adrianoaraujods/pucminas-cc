#include <stdio.h>
#include <stdlib.h>

/*
  Abaixo é apresentada a função de Ackerman, válida para valores inteiros e não negativos de m e n. Para ela, construa uma versão recursiva do algoritmo. Antes da implementação em C, verifique manualmente o seu comportamento para a chamada
    A(1, 2)
  Analise o comportamento da recursão neste caso (o seu ritmo de crescimento)
            / n + 1, para m=0
  A(m, n) = | A(m-1, 1), para m>0 e n=0
            \ A(m-1, A(m, n-1) ), para m>0 e n>0
*/

int ackerman(int m, int n) {
  int a = 0;

  printf("\nm: %i\tn: %i", m, n);

  if (m > 0 && n > 0) {
    a = ackerman(m - 1, ackerman(m, n - 1));
  } else if (m > 0 && n == 0) {
    a = ackerman(m - 1, 1);
  } else if (m == 0 && n >= 0) {
    a = n + 1;
  }

  return a;
}

int main() {
  printf("\n%i", ackerman(3, 0));

  return 0;
}