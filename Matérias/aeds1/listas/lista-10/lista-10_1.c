#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>

void main() {
  printf("\nPrice policy!");

  int products;
  bool inputHasError;

  do {
    printf("\nEnter how many products: ");
    scanf(" %i", &products);

    inputHasError = products <= 0;

    if (inputHasError) {
      printf("\aWarning: invalid input, should be greater than zero.");
    }
  } while (inputHasError);

  float expensiveIn2k = 0;
  float expensiveOut2k = 0;

  for (int i = 1; i <= products; i++) {
    float price;

    do {
      printf("\nEnter product %i price: ", i);
      scanf(" %f", &price);

      inputHasError = price <= 0;

      if (inputHasError) {
        printf("\aWarning: invalid input, should be greater than zero.");
      }
    } while (inputHasError);

    if (price < 2000) {
      if (price > expensiveIn2k) {
        expensiveIn2k = price;
      }
    } else {
      if (price > expensiveOut2k) {
        expensiveOut2k = price;
      }
    }
  }

  if (expensiveIn2k > 0) {
    printf("\nThe most expensive product less than $ 2.000 cost: $ %.2f", expensiveIn2k);
  }

  if (expensiveOut2k > 0) {
    printf("\nThe most expensive product more than $ 2.000 cost: $ %.2f", expensiveOut2k);
  }
}
