#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>

void main() {
  printf("\nSalary profile!");

  bool inputHasError;
  float minimumWage;

  do {
    printf("\nEnter the minimum wage: ");
    scanf(" %f", &minimumWage);

    inputHasError = minimumWage <= 0;

    if (inputHasError) {
      printf("\aWarning: invalid input, the minimum wage should be greater than zero.");
    }
  } while (inputHasError);

  int employees;

  do {
    printf("\nEnter the number of employees: ");
    scanf(" %i", &employees);

    inputHasError = employees <= 0;

    if (inputHasError) {
      printf("\aWarning: invalid input, the number of employees should be greater than zero.");
    }
  } while (inputHasError);

  int minimumWageEmployees = 0;
  float minSalary = 99999999.99;
  float maxSalary = minimumWage;

  for (int i = 1; i <= employees; i++) {
    float salary;

    do {
      printf("\nEnter employee %i salary: ", i);
      scanf(" %f", &salary);

      inputHasError = salary < minimumWage;

      if (inputHasError) {
        printf("\aWarning: invalid input, the employee salary should be at least the minimum wage.");
      }
    } while (inputHasError);

    if (salary == minimumWage) {
      minimumWageEmployees++;
    }

    if (salary > maxSalary) {
      maxSalary = salary;
    }

    if (salary < minSalary) {
      minSalary = salary;
    }
  }

  float percentage = minimumWageEmployees * 100.0 / employees;
  float amplitude = maxSalary - minSalary;

  printf("\n\tMinimum wage employees: %i/%i, %.2f%%", minimumWageEmployees, employees, percentage);
  printf("\n\tSalary amplitude: %f", amplitude);
}
