#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ARRAY_SIZE 10
#define MININUM_APROVED_GRADE 60

/*
  1)

  Construa um programa que ofereça ao usuário um menu com as seguintes funcionalidades:
    0 - Sair do Programa
    1 - Cadastrar uma nota
    2 - Informar o número de alunos aprovados
    3 - Informar a amplitude

  Considere as seguintes regras para as respectivas opções:
    0 - Ao sair, deverá ser exibida uma mensagem de agradecimento pelo uso do programa
    1 - Considere o seguinte domínio para a nota: 0..100. Rejeitar a leitura de valor inválido
    2 - Considere ser sessenta a nota mínima para aprovação
    3 - Lembre-se que a amplitude corresponde à diferença entre o maior e o menor valor

  Um vetor de reais deverá representar o conjunto das notas da turma. Considere oitenta o tamanho máximo de uma turma. Implemente rotinas que impeçam o acesso a posições inexistentes do array.
*/

float array[MAX_ARRAY_SIZE];
int head = 0;

float arraySmallestIndex() {
  int index = -1;

  if (head > 0) {
    index = 0;

    for (int i = 1; i < head; i++) {
      if (array[i] < array[index]) {
        index = i;
      }
    }
  }

  return index;
}

float arrayLargestIndex() {
  int index = -1;

  if (head > 0) {
    index = 0;

    for (int i = 1; i < head; i++) {
      if (array[i] > array[index]) {
        index = i;
      }
    }
  }

  return index;
}

bool arrayAppend(float value) {
  bool success = true;

  if (head < MAX_ARRAY_SIZE - 1) {
    array[head] = value;

    head++;
  } else {
    success = false;
  }

  return success;
}

void printMenu() {
  printf("\n\nOPTIONS MENU");
  printf("\n\t0 - Exit program");
  printf("\n\t1 - Register grade");
  printf("\n\t2 - Approved students");
  printf("\n\t3 - Grade amplitude");
}

float readGrade() {
  float grade;
  bool hasInputError;

  do {
    printf("\nEnter the student %i grade: ", head + 1);
    scanf(" %f", &grade);

    hasInputError = grade < 0 || grade > 100;

    if (hasInputError) {
      printf("\aWarnig: invalid input, the value should be from 0 to 100.");
    }
  } while (hasInputError);

  return grade;
}

void registerGrade() {
  bool success = arrayAppend(readGrade());

  if (success) {
    printf("\nGrade saved successfully!");
  } else {
    printf("Max grades reached, grade was not saved!");
  }
}

/* Recursive solution */
int approvedStudents(int lenght) {
  lenght--;

  int count = array[lenght] >= MININUM_APROVED_GRADE ? 1 : 0;

  if (lenght > 0) {
    count += approvedStudents(lenght);
  };

  return count;
}

void printApprovedStudents() {
  if (head > 0) {
    /* Iterative solution */
    // int count = 0;

    // for (int i = 0; i < head; i++) {
    //   if (array[i] >= MININUM_APROVED_GRADE) count++;
    // }

    /* Recursive solution */
    int count = approvedStudents(head);

    printf("\nApproved Studens Number: %i", count);
  } else {
    printf("\nNo grades registered.");
  }
}

void printGradesAmplitude() {
  int minGradeIndex = arraySmallestIndex();
  int maxGradeIndex = arrayLargestIndex();

  if (minGradeIndex >= 0 || maxGradeIndex >= 0) {
    printf("\nThe worst grade was from the student %i: %.2f", minGradeIndex + 1, array[minGradeIndex]);
    printf("\nThe best grade was from the student %i: %.2f", maxGradeIndex + 1, array[maxGradeIndex]);

    printf("\nThe grades amplitude is: %.2f", array[maxGradeIndex] - array[minGradeIndex]);
  } else {
    printf("\nNo grades registered.");
  }
}

int main() {
  int option;

  do {
    printMenu();

    printf("\n\nEnter a option from above: ");
    scanf("%i", &option);

    switch (option) {
    case 0: printf("\nThanks for using this program!");
      break;
    case 1: registerGrade();
      break;
    case 2: printApprovedStudents();
      break;
    case 3: printGradesAmplitude();
      break;
    default: printf("\nInvalid option, try again.");
      break;
    }
  } while (option != 0);

  return 0;
}