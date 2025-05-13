#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
  Considere uma turma com N alunos, sendo N um valor lido. Para cada aluno, ler a nota obtida em uma avaliação de valor igual a 100. Ao final das leituras, calcular e escrever a nota média da turma e o número de alunos com nota superior à nota média da turma.

  Construa uma nova versão para o problema anterior de forma que, ao final das leituras, também seja informada a menor nota entre os alunos aprovados. Sabe-se que a nota mínima para aprovação é igual ou superior a sessenta pontos.
*/

int readStudents() {
  int students;
  bool hasInputError;

  do {
    printf("\nEnter how many students: ");
    scanf("%i", &students);

    hasInputError = students <= 0;

    if (hasInputError) {
      printf("\aWarning: input error, the value should be greater than zero.");
    }

  } while (hasInputError);

  return students;
}

void readGrades(float grades[], int count) {
  for (int i = 0; i < count; i++) {
    printf("\nEnter the student %i grade: ", i + 1);
    scanf(" %f", &grades[i]);
  }
}

float arrayAverage(float array[], int lenght) {
  float sum = 0;

  for (int i = 0; i < lenght; i++) {
    sum += array[i];
  }

  return sum / lenght;
}

int arrayElementsGreaterThan(float array[], int lenght, float min) {
  int count = 0;

  for (int i = 0; i < lenght; i++) {
    if (array[i] >= min) {
      count++;
    }
  }

  return count;
}

float worstAprovedGrade(float grades[], int count) {
  const int MIN_GRADE = 60;

  float worst = 101;

  for (int i = 1; i < count; i++) {
    if (grades[i] < worst && grades[i] >= MIN_GRADE) {
      worst = grades[i];
    }
  }

  if (worst > 100) {
    worst = 0;
  }

  return worst;
}

int main() {
  const int STUDENTS_COUNT = readStudents();

  float grades[STUDENTS_COUNT];

  readGrades(grades, STUDENTS_COUNT);

  float average = arrayAverage(grades, STUDENTS_COUNT);
  printf("\nAverage: %.2f", average);

  int aboveAverage = arrayElementsGreaterThan(grades, STUDENTS_COUNT, average);
  printf("\nStudents Grades Above Average: %i", aboveAverage);

  float worstAproved = worstAprovedGrade(grades, STUDENTS_COUNT);
  printf("\nWorst Aproved Grade: %.2f", worstAproved);

  return 0;
}