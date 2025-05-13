#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main() {
  printf("\nCheck the triangle type!");

  float side1;
  printf("\nEnter the 1st side: ");
  scanf(" %f", &side1);

  float side2;
  printf("\nEnter the 2nd side: ");
  scanf(" %f", &side2);

  float side3;
  printf("\nEnter the 3rd side: ");
  scanf(" %f", &side3);

  if (side1 == side2 && side1 == side3) {
    printf("The triangle is equilateral");
  } else if (side1 == side2 || side1 == side3 || side2 == side3) {
    printf("The triangle is isosceles");
  } else {
    printf("The triangle isscalene");
  }
}
