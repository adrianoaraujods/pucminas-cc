/*
  Construa uma função que receba um arranjo de reais e desloque o maior valor de arranjo para a última posição.
*/

void placeLargestAtEnd(float array[], int lenght) {
  int largestIndex = 0;

  for (int i = 1; i < lenght; i++) {
    if (array[i] > array[largestIndex]) {
      largestIndex = i;
    }
  }

  float largestElement = array[largestIndex];

  for (int i = largestIndex; i < lenght - 1; i++) {
    array[i] = array[i + 1];
  }

  array[lenght - 1] = largestElement;
}

int main() {
  return 0;
}