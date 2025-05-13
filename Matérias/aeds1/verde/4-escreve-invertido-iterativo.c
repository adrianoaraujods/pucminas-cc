#include <stdio.h>
#include <stdlib.h>

/*
  Considere a seguinte função:

  int main()
  {
    int x=12345;
    escreveInvertido(x);
  }

  Utilizando a abordagem iterativa, implemente a função `escreveInvertido(int)` encarregada de escrever o   parâmetro enviado de forma invertida.

  No exemplo acima, escreveria 54321
*/

void escreveInvertido(int n)
{
  if (n < 0)
  {
    n *= -1;
  }

  while (n > 0)
  {
    int rest = n % 10;

    printf("%i", rest);

    n /= 10;
  }
}

int main()
{
  int x = 12345;
  escreveInvertido(x);
}