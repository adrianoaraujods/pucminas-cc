/*
  Escreva uma função chamada teste que recebe um valor n passado “por valor” e dois  inteiros b e k passados “por referência".

  Sua função deve representar em b e k valores tais que bk =  n e b seja o menor possível
*/

void teste(int n, int* b, int* k) {
  // b * k = n;

  *b = 1;
  *k = n;
}

int main() {
  int b;
  int k;

  teste(10, &b, &k);

  return 0;
}