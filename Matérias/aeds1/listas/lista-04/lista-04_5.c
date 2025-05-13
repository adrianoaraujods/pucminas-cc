#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main() {
  printf("\nCalculator Program!");

  do {
    int operation;

    do {
      printf("\n\nOperations Menu:");
      printf("\n0. Exit program");
      printf("\n1. Sum (+)");
      printf("\n2. Subtract (-)");
      printf("\n3. Multiply (x)");
      printf("\n4. Divide (/)");

      printf("\n\nChoose an operation: ");
      scanf(" %i", &operation);

      if (operation == 0) {
        printf("\nEnd of the program");

        return;
      };
    } while (
      (operation < 0 || operation > 4)          //
      && printf("\aWarning: Invalid operation") //
      );

    float n1, n2;

    printf("\nEnter the 1st number: ");
    scanf(" %f", &n1);

    do {
      printf("\nEnter the 2nd number: ");
      scanf(" %f", &n2);
    } while (
      (operation == 4 || n2 == 0)                              //
      && printf("\aWarning: Division by zero is not allowed.") //
      );

    float result;

    switch (operation) {
    case 1:
      printf("\nSum operation: %f + %f = ", n1, n2);
      result = n1 + n2;

      break;
    case 2:
      printf("\nSubtract operation: %f - %f = ", n1, n2);
      result = n1 - n2;

      break;
    case 3:
      printf("\nMultiply operation: %f * %f = ", n1, n2);
      result = n1 * n2;

      break;
    case 4:
      printf("\nDivide operation: %f / %f = ", n1, n2);
      result = n1 / n2;

      break;
    }

    printf("%f", result);
  } while (1);
}
