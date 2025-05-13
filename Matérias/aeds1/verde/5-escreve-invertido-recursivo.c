#include <stdio.h>
#include <stdlib.h>

/*
  Considere a seguinte função:

  int main()
  {
    int x=12345;
    escreveInvertidoRec(x);
  }

  Utilizando a abordagem recursiva, implemente a função `escreveInvertidoRec(int)` encarregada de escrever o parâmetro enviado de forma invertida.

  No exemplo acima, escreveria 54321
*/

void escreveInvertidoRec(int n)
{
  if (n > 0)
  {
    int lastDigit = n % 10;

    printf("%i", lastDigit);

    escreveInvertidoRec(n / 10);
  }
}

int main()
{
  int x = 12345;
  escreveInvertidoRec(x);
}