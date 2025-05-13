#include <stdio.h>
#include <stdlib.h>

/*
  Faça uma sub-rotina que receba como parâmetro um inteiro no intervalo de 1 a 9 e mostre a seguinte tabela de multiplicação (no exemplo, n = 9):

  1
  2 4
  3 6 9
  4 8 12 16
  5 10 15 20 25
  6 12 18 24 30 36
  7 14 21 28 35 42 49
  8 16 24 32 40 48 56 64
  9 18 27 36 45 54 63 72 81

  Caso a variável paramétrica receba um valor menor que 1 ou maior que 9 nenhum valor deverá ser escrito na tela do monitor de vídeo.
*/

void tableFunction(int n)
{
  if (n >= 1 && n <= 9)
  {
    for (int i = 1; i <= n; i++)
    {
      printf("%i", i);

      for (int j = 2; j <= i; j++)
      {
        printf(" %i", i * j);
      }

      printf("\n");
    }
  }
}

int main()
{
  tableFunction(5);

  return 0;
}
