#include <stdio.h>
#include <stdlib.h>

/*
  Construa uma função que receba uma string relativa ao nome a ser dado a um arquivo. A função deverá gerar um arquivo com um conjunto de valores do tipo real digitados pelo usuário do programa. Os dados deverão ser armazenados no arquivo de forma que não consigam ser interpretados por seres humanos.

 Construa uma função que receba um ponteiro do tipo FILE que aponta para um arquivo com um conjunto de valores do tipo real. A função deverá calcular e retornar a amplitude dos valores nele armazenado.

 Modularização: Divida a tarefa em funções que implementem funcionalidades atômicas.

 Teste as funções criadas a partir da função principal, de forma que consiga validar sua solução.
*/

void createFile(char* fileName) {
  FILE* file = fopen(fileName, "wb");

  int numbers;
  printf("\nEnter how many numbers you want to save: ");
  scanf(" %i", &numbers);

  float input;

  while (numbers > 0) {
    printf("\nEnter a number: ");
    scanf(" %f", &input);

    fwrite(&input, sizeof(float), 1, file);

    numbers--;
  }

  fclose(file);
}

float fileAmplitude(FILE* file) {
  float amplitude = 0;

  if (file != NULL) {
    rewind(file);

    float line, smallest, largest;

    fread(&smallest, sizeof(float), 1, file);

    largest = smallest;

    while (!feof(file)) {
      fread(&line, sizeof(float), 1, file);

      if (line > largest) {
        largest = line;
      } else if (line < smallest) {
        smallest = line;
      }
    }

    amplitude = largest - smallest;

    fclose(file);
  }

  return amplitude;
}

int main() {
  printf("\nGet the amplitude in a number range!");

  char* fileName = "lista-20.bin";

  createFile(fileName);

  FILE* file = fopen(fileName, "rb");

  printf("\nAmplitude: %.2f", fileAmplitude(file));

  return 0;
}