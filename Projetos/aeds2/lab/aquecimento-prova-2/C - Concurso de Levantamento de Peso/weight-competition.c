#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_LINE_LENGTH 100
#define MAX_ARRAY 100
#define MAX_WEIGHT 500

typedef struct {
  char name[MAX_NAME_LENGTH];
  unsigned short maxLifted;
} Atlete;

Atlete* parseAtlete(char* input) {
  Atlete* atlete = malloc(sizeof(Atlete));
  if (atlete == NULL) return NULL;

  int i, j;
  for (i = 0; input[i] != ' '; i++) atlete->name[i] = input[i];

  i++;
  char maxLifted[4];
  for (j = 0; input[i] != '\n'; i++, j++) maxLifted[j] = input[i];
  atlete->maxLifted = atoi(maxLifted);

  return atlete;
}

void quicksort(Atlete* atletes[], int left, int right);

void sort(Atlete* atletes[], int competitors) {
  quicksort(atletes, 0, competitors - 1);
}

int main() {
  Atlete* atletes[MAX_ARRAY];
  int competitors = 0;

  char line[MAX_LINE_LENGTH];
  while (fgets(line, MAX_LINE_LENGTH, stdin)) {
    atletes[competitors++] = parseAtlete(line);
  }

  sort(atletes, competitors);

  for (int i = 0; i < competitors; i++) {
    printf("%s %d\n", atletes[i]->name, atletes[i]->maxLifted);
    free(atletes[i]);
  }

  return 0;
}

void swap(Atlete* array[], int firstIndex, int secondIndex) {
  Atlete* temp = array[firstIndex];
  array[firstIndex] = array[secondIndex];
  array[secondIndex] = temp;
}

void quicksort(Atlete* atletes[], int left, int right) {
  int i = left, j = right;
  char* pivotName = atletes[(i + j) / 2]->name;
  int pivotMaxLifted = atletes[(i + j) / 2]->maxLifted;

  while (i <= j) {
    while (atletes[i]->maxLifted > pivotMaxLifted
      || (atletes[i]->maxLifted == pivotMaxLifted
        && strcmp(atletes[i]->name, pivotName) < 0)
      ) i++;

    while (atletes[j]->maxLifted < pivotMaxLifted
      || (atletes[j]->maxLifted == pivotMaxLifted
        && strcmp(atletes[j]->name, pivotName) > 0)
      ) j--;

    if (i <= j) swap(atletes, i++, j--);
  }

  if (left < j) quicksort(atletes, left, j);
  if (i < right) quicksort(atletes, i, right);
};
