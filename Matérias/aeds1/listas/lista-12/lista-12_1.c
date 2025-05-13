#include <stdio.h>
#include <stdlib.h>

// Construa uma função que receba a idade de uma pessoa e gere o número de dias por ela vividos até o seu último aniversário (fique à vontade para ignorar o impacto dos anos bissextos). Teste a função criada a partir da função principal.

int daysLived(int);

void main() {
  printf("\nDays lived by age");
  printf("\n%i", daysLived(22));
}

int daysLived(int age) {
  return age * 365;
}
