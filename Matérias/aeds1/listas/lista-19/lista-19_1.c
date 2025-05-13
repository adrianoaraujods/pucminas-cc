#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/*
  Considere  que  o  seu  herói  foi  designado  para  um  reino  em  que  o  Rei  decretou  a  proibição  de variáveis convencionais, permitindo o uso unicamente de alocação dinâmica de memória. A missão de seu herói é ajudar a população daquele reino calculando o peso ideal de cada indivíduo.
*/

float* readHeight() {
  float* height = malloc(sizeof(float));
  bool* hasInputError = malloc(sizeof(bool));

  do {
    printf("\nEnter the height in meters: ");
    scanf(" %f", height);

    *hasInputError = *height <= 0 || *height > 2.5;

    if (*hasInputError) {
      printf("\aWarning: input error, the height should be greater than 0, and at maximum 2.5");
    }
  } while (*hasInputError);

  return height;
};

bool* readIsMale() {
  char* input = malloc(sizeof(char));
  bool* hasInputError = malloc(sizeof(bool));

  do {
    printf("\nEnter the gender [M/f]: ");
    scanf(" %c", input);

    *input = toupper(*input);
    *hasInputError = *input != 'M' && *input != 'F';

    if (*hasInputError) {
      printf("\aWarning: input error, enter 'M' for male and 'F' for female");
    }
  } while (*hasInputError);

  bool* isMale = malloc(sizeof(bool));

  *isMale = *input == 'M';

  return isMale;
};

float* idealWeight(float* height, bool* isMale) {
  float* weight = malloc(sizeof(float));

  if (*isMale) {
    *weight = (72.7 * *height) - 58;
  } else {
    *weight = (62.1 * *height) - 44.7;
  }

  return weight;
}

int main() {
  printf("\nGet a person Ideal Weight!");

  float* height = readHeight();
  bool* isMale = readIsMale();

  float* weight = idealWeight(height, isMale);

  printf("\nThe Ideal Weight is %.2f kg.", *weight);

  return 0;
}