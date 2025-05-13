#include <stdio.h>

#define MAX 100

char wall[MAX][MAX];
int height, width;

void readWall() {
  for (int i = 0; i < height; i++) {
    scanf("%s", wall[i]);
  }
}

void printWall() {
  for (int i = 0; i < height; i++) {
    printf("%s\n", wall[i]);
  }
}

int findHole() {
  int hole = -1, j = 0;

  while (hole < 0 && j < width) {
    if (wall[0][j] == 'o') hole = j;

    j++;
  }

  return hole;
};

void spill(int i, int j) {
  if (
    i >= 0 && i < height &&
    j >= 0 && j < width &&
    wall[i][j] == '.'
    ) {
    wall[i][j] = 'o';

    // Down
    if (i + 1 < height && wall[i + 1][j] != '#') {
      spill(i + 1, j);
    }

    // Left
    if (j - 1 >= 0 && wall[i][j - 1] == '#') {
      spill(i, j - 1);
    }

    // Right
    if (j + 1 < width && wall[i][j + 1] == '#') {
      spill(i, j + 1);
    }
  }
}

int main() {
  scanf("%d %d", &height, &width);
  readWall();

  int hole = findHole();
  wall[0][hole] = '.';

  spill(0, hole);

  printWall();

  return 0;
}
