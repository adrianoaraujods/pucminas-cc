#include <stdio.h>

#define MAX_LENGHT 255

int head = 5;

void arrayInsertValue(float array[], float value) {
  if (head < MAX_LENGHT) {
    for (int i = head; i >= 0; i--) {
      array[i + 1] = array[i];
    }

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