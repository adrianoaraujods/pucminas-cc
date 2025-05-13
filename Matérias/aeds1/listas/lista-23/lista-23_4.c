/*
  Construa uma função que receba um arranjo de reais e desloque o menor valor de arranjo para a primeira posição.
*/

void placeSmallestAtStart(float array[], int lenght) {
  int smallestIndex = 0;

  for (int i = 1; i < lenght; i++) {
    if (array[i] < array[smallestIndex]) {
      smallestIndex = i;
    }
  }

  float smallestElement = array[smallestIndex];

  for (int i = smallestIndex; i > 0; i--) {
    array[i] = array[i - 1];
  }

  array[0] = smallestElement;
}

int main() {
  return 0;
}