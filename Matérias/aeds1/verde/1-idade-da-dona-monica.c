#include <stdio.h>
#include <stdlib.h>

/*
  Dona Mônica é mãe de três filhos que têm idades diferentes. Ela notou que, neste ano, a soma das idades dos seus três filhos é igual à idade dela. Neste problema, dada a idade de dona Mônica e as idades de dois dos filhos, seu programa deve computar e imprimir a idade do filho mais velho.

  Por exemplo, se sabemos que dona Mônica tem 52 anos e as idades conhecidas de dois dos filhos são 14 e 18 anos, então a idade do outro filho, que não era conhecida, tem que ser 20 anos, pois a soma das três idades tem que ser 52. Portanto, a idade do filho mais velho é 20. Em mais um exemplo, se dona Mônica tem 47 anos e as idades de dois dos filhos são 21 e 9 anos, então o outro filho tem que ter 17 anos e, portanto, a idade do filho mais velho é 21.

  Entrada:
  A primeira linha da entrada contém um inteiro M representando a idade de dona Mônica. A segunda linha da entrada contém um inteiro A representando a idade de um dos filhos. A terceira linha da entrada contém um inteiro B representando a idade de outro filho.

  Saída:
  Seu programa deve imprimir uma linha, contendo um número inteiro, representando a idade do filho mais velho de dona Mônica.

  Considere a seguinte função principal:

  int main()
  {
    int M; scanf("%i", &M); // Idade da Dona Mônica
    int A; scanf("%i", &A); // Idade de um dos filhos
    int B; scanf("%i", &B); // Idade de outro filho
    printf("%i", maisVelho(M,A,B) );
    return 0;
  }
*/

int maisVelho(int mom, int sonA, int sonB)
{
  int sonC = mom - sonA - sonB;

  int oldest = sonC;

  if (sonA > sonB && sonA > sonC)
  {
    oldest = sonA;
  }
  else if (sonB > sonA && sonB > sonC)
  {
    oldest = sonB;
  }

  return oldest;
}

int main()
{
  int M;
  scanf("%i", &M); // Idade da Dona Mônica
  int A;
  scanf("%i", &A); // Idade de um dos filhos
  int B;
  scanf("%i", &B); // Idade de outro filho
  printf("%i", maisVelho(M, A, B));
  return 0;
}