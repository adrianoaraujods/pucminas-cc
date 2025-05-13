#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void main() {
  printf("\nGrade Profile!");
  printf("\nEnter 0 to stop.");

  float grade = 1;
  int approved = 0, i = 0;

  while (grade != 0) {
    i++;

    do {
      printf("\nStudent %i, grade: ", i);
      scanf(" %f", &grade);
    } while (
      (grade < 0 || grade > 100)                                          //
      && printf("\aWarning: invalid input. Enter a value between 0-100.") //
      );

    if (grade >= 60) {
      approved++;
    }
  }

  if (grade == 0 && i == 1) {
    printf("\nNo grades");

    return;
  }

  i--;
  int repproved = (i - approved);
  float approvedPercentage = ((approved * 100) / i);
  float repprovedPercentage = ((repproved * 100) / i);

  printf("\nApproved: %i/%i, %f%%", approved, i, approvedPercentage);
  printf("\nRepproved: %i/%i, %f%%", repproved, i, repprovedPercentage);
}
