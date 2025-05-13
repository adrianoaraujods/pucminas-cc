#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main() {
  printf("Solve a 2nd degree equation!\n");

  int a;
  printf("\nEnter the value of 'a': ");
  scanf(" %d", &a);

  int b;
  printf("\nEnter the value of 'b': ");
  scanf(" %d", &b);

  int c;
  printf("\nEnter the value of 'c': ");
  scanf(" %d", &c);

  float delta = (b * b) - (4 * a * c);

  float root1 = (-b + sqrt(delta)) / (2 * a);

  float root2 = (-b - sqrt(delta)) / (2 * a);

  printf("Your equation is:\n (%dx)e2 + (%dx) + (%d) = 0\n The roots are: %f and %f", a, b, c, root1, root2);
}
