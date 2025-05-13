#include <stdio.h>
#include <stdlib.h>

/*
  Considere a seguinte função principal:

  int main()
  {
    int C; scanf("%i", &C); // Capacidade da cabine
    int A; scanf("%i", &A); // Número total de alunos na turma
    printf("%i", minimoDeViagens(C,A) );
    return 0;
  }

  Implemente a função minimoDeViagens(int,int)
*/

int minimoDeViagens(int capacity, int students)
{
  float trips = students / (float)(capacity - 1);

  int decimal = students % (capacity - 1);

  if (decimal > 0)
  {
    trips++;
  }

  return trips;
}

int main()
{
  int C;
  scanf("%i", &C); // Capacidade da cabine
  int A;
  scanf("%i", &A); // Número total de alunos na turma
  printf("%i", minimoDeViagens(C, A));
  return 0;
}