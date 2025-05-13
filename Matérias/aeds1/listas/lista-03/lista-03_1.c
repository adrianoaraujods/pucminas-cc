#include <stdio.h>
#include <stdlib.h>

void main() {
  printf("\nSort three numbers decreasingly!");

  float n1;
  printf("\nEnter the 1th number");
  scanf(" %f", &n1);

  float n2;
  printf("\nEnter the 2nd number");
  scanf(" %f", &n2);

  float n3;
  printf("\nEnter the 3rd number");
  scanf(" %f", &n3);

  float temp;

  if (n2 > n1) {
    temp = n2;

    n2 = n1;
    n1 = temp;
  };

  if (n3 > n1) {
    temp = n3;

    n3 = n2;
    n2 = n1;
    n1 = temp;
  } else if (n3 > n2) {
    temp = n3;

    n3 = n2;
    n2 = temp;
  };

  printf("The sorted decreasingly numbers are: %f, %f, %f", n1, n2, n3);
}
