#include <stdio.h>
#include <ctype.h>

#define VOWELS_COUNT 5

/*
  3. Construa uma função que receba uma string e um arranjo de inteiros de tamanho igual a cinco. A função deverá preencher o vetor de inteiros com o número da vogal correspondente, considerando a seguinte sequência: ‘a’ na posição 0, ‘e’ na posição 1 e assim sucessivamente.
*/

void stringVowelsCount(char string[], int count[VOWELS_COUNT]) {
  for (int vow = 0; vow < VOWELS_COUNT; vow++) {
    count[vow] = 0;
  }

  char vowles[VOWELS_COUNT] = { 'a', 'e', 'i', 'o', 'u' };
  int cha = 0;

  while (string[cha] != '\0') {
    for (int vow = 0; vow < VOWELS_COUNT; vow++) {
      if (tolower(string[cha]) == vowles[vow]) count[vow]++;
    }

    cha++;
  }
}

int main() {
  char string[] = "ROMA";
  int vowels[VOWELS_COUNT] = {};

  stringVowelsCount(string, vowels);

  printf("\na: %i", vowels[0]);
  printf("\ne: %i", vowels[1]);
  printf("\ni: %i", vowels[2]);
  printf("\no: %i", vowels[3]);
  printf("\nu: %i", vowels[4]);

  return 0;
}