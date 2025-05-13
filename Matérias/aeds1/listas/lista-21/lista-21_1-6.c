#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
  char* fileName = "lista-21_1-6.dat";

  FILE* file;
  file = fopen(fileName, "w");

  fprintf(file, "%i\n", 22);

  fclose(file);

  file = fopen(fileName, "a");

  fprintf(file, "%i\n", 84);
  fprintf(file, "%i\n", 54);

  fclose(file);

  if ((file = fopen(fileName, "r")) != NULL) {
    int input;
    fscanf(file, "%i", &input);

    while (!feof(file)) {
      printf("%i\n", input);
      fscanf(file, "%i", &input);
    }
  }

  fclose(file);

  return 0;
}