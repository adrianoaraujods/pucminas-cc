#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main() {
  printf("\nFind your ideal weight!");

  float height;
  do {
    printf("\nEnter your height (meters): ");
    scanf(" %f", &height);
  } while (
    (height <= 0 || height > 2.5)                           //
    && printf("\aWarning: Enter a value between 0 and 2.5") //
    );

  char gender;
  do {
    printf("\nEnter your gender [M/F]: ");
    scanf(" %c", &gender);
  } while (
    !(gender == 'M' || gender == 'm' || gender == 'F' || gender == 'f')   //
    && printf("\aWarning: Your response should be: 'M', 'm', 'F' or 'f'") //
    );

  float idealWeight;
  if (gender == 'M' || gender == 'm') {
    idealWeight = (72.7 * height) - 58;
  } else {
    idealWeight = (62.1 * height) - 44.7;
  }

  printf("\nYour ideal weight is: %f kg", idealWeight);
}
