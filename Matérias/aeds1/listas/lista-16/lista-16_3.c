#include <stdio.h>
#include <stdlib.h>

// Torre de Hanói

void towerOfHanoi(int disk, int initial, int target, int temp) {
  if (disk == 1) {
    printf("\n%i -> %i (disk %i)", initial, target, disk);
  } else {
    towerOfHanoi(disk - 1, initial, temp, target);

    printf("\n%i -> %i (disk %i)", initial, target, disk);

    towerOfHanoi(disk - 1, temp, target, initial);
  };
}

int main() {
  towerOfHanoi(3, 1, 3, 2);

  return 0;
}

/*
  Para 1

  1 -> 3 \ Para 1
  1 -> 2  |
  3 -> 2  \ Para 2
  1 -> 3   |
  2 -> 1   |
  2 -> 3   |
  1 -> 3   \ Para 3
*/
