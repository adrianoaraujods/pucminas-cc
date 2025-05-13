#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>

void main() {
  printf("\nGrades Checker!");

  int nGrades;
  printf("\nEnter how many grades you will enter: ");
  scanf(" %i", &nGrades);

  float avarage = 0;
  float minGrade = 100;
  float maxGrade = 0;

  for (int i = 1; i <= nGrades; i++) {
    float grade;

    do {
      printf("\nGrade %i: ", i);
      scanf(" %f", &grade);
    } while (
      (grade < 0 || grade > 100)                                          //
      && printf("\aWarning: invalid grade. Enter a value from 0 to 100.") //
      );

    printf(grade >= 60 ? "PASS" : "FAIL");

    if (grade > maxGrade) {
      maxGrade = grade;
    }

    if (grade < minGrade) {
      minGrade = grade;
    }

    avarage += grade;
  }

  avarage /= nGrades;

  printf("\nAvarage Grade: %f", avarage);
  printf("\nMin grade: %f", minGrade);
  printf("\nMax grade: %f", maxGrade);
}
