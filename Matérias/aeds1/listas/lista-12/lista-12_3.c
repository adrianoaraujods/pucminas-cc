#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

// Construa um programa que permita calcular o peso ideal de uma pessoa. Planeje com calma as funções necessárias para atender ao propósito da questão:
// - Uma função deverá fazer a apresentação na tela deste programa.
void presentation();

// - Uma função char deverá ler e retornar o gênero [M/F]. Rejeitar a leitura de caracteres fora deste domínio. A função deverá garantir que o caractere retornado esteja em maiúsculo, independentemente da forma que ele foi digitado pelo usuário do programa.
char readGender();

// - Uma função int deverá ler a idade. Rejeitar a leitura de valores negativos.
float readHeight(); // não existe fórmula que usa idade, então coloquei a altura

// - Uma função float deverá receber dois parâmetros, o gênero e a idade. A partir da interpretação destes dois parâmetros, gerar um valor relativo ao peso ideal.
float idealWeight(char, float); // não existe fórmula que usa idade, então coloquei a altura

// - Uma função void deverá receber um valor relativo ao resultado e escrever o peso ideal.
void writeIdealWeight(char, float); // fiz de outra forma pra ficar mais dinâmico

void main() {
  printf("\nFind a person Ideal Weight!");

  char gender = readGender();
  float height = readHeight();

  writeIdealWeight(gender, height);
}

char readGender() {
  char gender;
  bool hasInputError;

  do {
    printf("\nEnter the gender [M/f]: ");
    scanf(" %c", &gender);
    gender = toupper(gender);

    hasInputError = gender != 'M' && gender != 'F';

    if (hasInputError) {
      printf("\aWarning: invalid input, enter 'M' for male of 'F' for female.");
    }
  } while (hasInputError);

  return gender;
}

float readHeight() {
  float height;
  bool hasInputError;

  do {
    printf("\nEnter the height in meters: ");
    scanf(" %f", &height);

    hasInputError = height <= 0 || height > 2.5;

    if (hasInputError) {
      printf("\aWarning: invalid input, the height should be between 0 and 2.5.");
    }
  } while (hasInputError);

  return height;
}

float idealWeight(char gender, float height) {
  float idealWeight;

  if (gender == 'M') {
    idealWeight = 72.7 * height - 58.0;
  } else {
    idealWeight = 62.1 * height - 44.7;
  }

  return idealWeight;
}

void writeIdealWeight(char gender, float height) {
  char* genderString = (gender == 'M') ? "man" : "woman";

  printf(
    "\nThe ideal weight for a %s of height %.2fm is %.2fkg.",
    genderString, height, idealWeight(gender, height) //
  );
}
