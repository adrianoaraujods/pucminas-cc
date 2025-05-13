#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
  Construa um programa que calcule a quantidade de alunos com idade acima da idade média da turma. Para isto, o programa deverá ler a idade de cada aluno. A leitura de uma idade igual a zero deverá indicar o término dos valores – observe que zero não deve ser considerada uma idade válida, apenas a indicação de não haver mais valores a serem fornecidos (flag). As idades lidas deverão ser armazenadas no arquivo “idade.dat”. Após a leitura das idades, o arquivo deverá ser fechado. Para realizar os cálculos, o arquivo deverá ser aberto no modo leitura.
*/

void saveStudentsAge(char* fileName) {
  FILE* file = fopen(fileName, "w");

  int input;
  bool hasInputError;

  printf("\nEnter the students age, enter 0 to stop.");

  do {
    printf("\nEnter the student age: ");
    scanf(" %i", &input);

    hasInputError = input < 0;

    if (hasInputError) {
      printf("\aWarning: input error, age should be posite.");
    } else if (input != 0) {
      fprintf(file, "%i\n", input);
    }
  } while (input != 0 || hasInputError);

  fclose(file);
}

float studentsAverageAge(char* fileName) {
  FILE* file;

  int sum = 0;
  int studentsCount = 0;

  if ((file = fopen(fileName, "r")) != NULL) {
    int age;

    fscanf(file, "%i", &age);

    while (!feof(file)) {
      sum += age;
      studentsCount++;

      fscanf(file, "%i", &age);
    }
  }

  fclose(file);

  float average = 0;

  if (studentsCount > 0) {
    average = (float)sum / studentsCount;
  }

  return average;
}

int studentsAboveAverageAge(char* fileName) {
  FILE* file;
  int count = 0;

  float average = studentsAverageAge(fileName);

  if ((file = fopen(fileName, "r")) != NULL) {
    int age;

    fscanf(file, "%i", &age);

    while (!feof(file)) {
      if (age > average) {
        count++;
      }

      fscanf(file, "%i", &age);
    }
  }

  return count;
}

int main() {
  char* fileName = "lista-21_7.dat";

  saveStudentsAge(fileName);

  printf("Average: %f", studentsAverageAge(fileName));

  printf("Above Average: %i", studentsAboveAverageAge(fileName));

  return 0;
}