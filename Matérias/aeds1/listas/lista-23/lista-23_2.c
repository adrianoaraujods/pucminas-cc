/*
  Construa uma função que receba um arranjo de reais e o seu tamanho. A função deverá trocar dois elementos de lugar. As duas posições deverão também ser parametrizadas.
*/

void swapArrayElements(float array[], int lenght, int elementA, int elementB) {
  if (
    elementA == elementB ||
    elementA < 0 ||
    elementB < 0 ||
    elementA >(lenght - 1) ||
    elementB >(lenght - 1) //
    ) {
    return;
  }

  float temp = array[elementA];

  array[elementA] = array[elementB];
  array[elementB] = temp;
}

int main() {
  return 0;
}