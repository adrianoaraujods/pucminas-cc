#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Construa uma nova versão para o problema dos triângulos. A partir da leitura dos valores dos três lados do triângulo, o programa deverá informar o tipo do triângulo: equilátero, isóscele ou escaleno. Por outro lado, uma mensagem de alerta deverá ser exibida caso os valores fornecidos são permitem a representação de um triângulo. O programa deverá prover as seguintes funcionalidades:

// - Uma função que leia o valor de um lado do triângulo.
// Argumentos da função: nenhum.
// Valor gerado: o valor fornecido pelo usuário através do teclado.
float readFloat() {
  float input;
  scanf(" %f", &input);

  return input;
}

// - Uma função que verifique se os valores apresentados como lados do triângulo atendem ou não à condição para construir triângulos.
// Argumentos da função: os três valores que representam cada lado do triângulo.
// Valor gerado: verdadeiro, se os três lados permitem a construção de um triângulo; ou falso, caso contrário.
bool validTriangle(float sideA, float sideB, float sideC) {
  bool isTriangle = false;

  if (
    sideA > 0 && //
    sideB > 0 && //
    sideC > 0 && //

    sideA + sideB > sideC && //
    sideA + sideC > sideB && //
    sideB + sideC > sideA    //
    ) {
    isTriangle = true;
  }

  return isTriangle;
}

// - Uma função que verifique o tipo do triângulo.
// Argumentos da função: os três lados de um triângulo.
// Valor gerado: 1, se equilátero; 2, se isóscele; 3, se escaleno; 0, caso não se trate de um triângulo (para este caso, evocar a função construída no item acima).
int getTriangleType(float sideA, float sideB, float sideC) {
  int type = 0;

  if (validTriangle(sideA, sideB, sideC)) {
    if (sideA == sideB && sideB == sideC) {
      type = 1;
    } else if (sideA == sideB || sideA == sideC || sideB == sideC) {
      type = 2;
    } else {
      type = 3;
    }
  }

  return type;
}

// - Uma função que leia através do teclado o valor de um lado de um triângulo.
// Argumento da função: Um número inteiro (1..3) que expresse qual o lado a ser lido, a fim de enriquecer a mensagem enviada à tela para o usuário;
// Valor gerado: a função deverá retornar o valor lido.
// Obs: Consistir o dado lido (rejeitar a leitura de lado negativo)
float readTriangleSide(int side) {
  float sideLenght;
  bool hasInputError;

  do {
    printf("\nEnter the side %i lenght: ", side);
    sideLenght = readFloat();

    hasInputError = sideLenght < 0;

    if (hasInputError) {
      printf("\aWarning: input error, side lenght must be positive.");
    }
  } while (hasInputError);

  return sideLenght;
}

// - Uma função que escreva na tela uma string relativa a um tipo do triângulo, a saber: “Equilátero”, “Isóscele” ou “Escaleno”.
// Argumento de entrada: Um valor inteiro relativo ao tipo do triângulo, a saber: 1 (representando equilátero), 2 (representado isóscele); 3 (representando escaleno).
// Valor gerado: nenhum (vazio).
// Obs: Nenhuma mensagem deverá ser escrita se o valor parametrizado for diferentes de 1..3.
void writeTriangleType(int type) {
  char* text;

  if (type >= 1 && type <= 3) {
    switch (type) {
    case 1:
      text = "equilatero";
      break;
    case 2:
      text = "isosceles";
      break;
    case 3:
      text = "escaleno";
      break;
    }

    printf("\nThe triangle is %s", text);
  }
}

// - Uma função que faça uma apresentação ao usuário, com mensagens elucidativas sobre os objetivos do programa.
// Argumentos da função: Nenhum
// Valor gerado: Nenhum (vazio)
void presentation() {
  printf("\nFind the triangle type by entering 3 sides!");
}

// - Uma função principal que gerencie o fluxo das chamadas às demais funções para atender ao propósito do problema tratado
void main() {
  presentation();

  float sideA = readTriangleSide(1);
  float sideB = readTriangleSide(2);
  float sideC = readTriangleSide(3);

  int triangleType = getTriangleType(sideA, sideB, sideC);

  writeTriangleType(triangleType);
}