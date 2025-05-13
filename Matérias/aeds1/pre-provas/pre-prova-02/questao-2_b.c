#include <stdio.h>

#define MAX_LENGHT 255

int head = 5;

void arrayShift(float array[], int i) {
  if (i >= 0) {
    array[i + 1] = array[i];
    arrayShift(array, i - 1);
  }
}

void arrayInsertValue(float array[], float value) {
  if (head < MAX_LENGHT) {
    arrayShift(array, head);

    array[0] = value;

    head++;
  } else {
    printf("\aMax size reached.");
  }
}

int main() {
  float array[MAX_LENGHT] = { 1, 2, 3, 4, 5 };

  arrayInsertValue(array, 6);

  for (int i = 0; i < head; i++) {
    printf("%.2f, ", array[i]);
  }

  return 0;
}