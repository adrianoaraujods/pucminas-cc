/*
  Construa uma função que receba um arranjo de reais e o seu tamanho. A função deverá trocar o primeiro elemento do arranjo com o último.
*/

void swapArrayEnds(float array[], int lenght) {
  float temp = array[lenght - 1];

  array[lenght - 1] = array[0];
  array[0] = temp;
}

int main() {
  return 0;
}
