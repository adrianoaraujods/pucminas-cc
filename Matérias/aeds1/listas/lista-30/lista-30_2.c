#include <stdio.h>
#include <stdbool.h>

#define MAX_LENGHT 255

int lenght = 0;

/*
  Questão 2:
  Crie uma versão para o programa acima persistindo os triângulos. Um menu deverá prover as seguintes   funcionalidades:
    0 – Sair do programa
    1 – Ler um triângulo
    2 – Informar o número de triângulos equiláteros
    3 – Informar o número de triângulos isósceles
    4 – Informar o número de triângulos escalenos
*/

typedef struct {
  float sideA, sideB, sideC;
} Triangle;

typedef struct {
  int equilateral, isosceles, scalene;
} TriangleTypes;

int menu() {
  int option;
  bool invalid;

  do {
    printf("\nOptions Menu\n");
    printf("\t0 - Exit Program\n");
    printf("\t1 - Register a new triangle\n");
    printf("\t2 - Get equilateral tringles count\n");
    printf("\t3 - Get isosceles tringles count\n");
    printf("\t4 - Get scalene tringles count\n");

    printf("\nEnter the desired option: ");
    scanf(" %d", &option);

    invalid = option < 0 || option > 4;

    if (invalid) printf("\aWarning: invalid input, choose a option from 0 to 4.");
  } while (invalid);

  return option;
}

void updateTriangleTypesCount(Triangle triangles[MAX_LENGHT], TriangleTypes types) {
  types.equilateral = types.isosceles = types.scalene = 0;

  for (int i = 0; i < lenght; i++) {
    float sideA = triangles[i].sideA;
    float sideB = triangles[i].sideB;
    float sideC = triangles[i].sideC;

    if (sideA == sideB || sideA == sideC || sideB == sideC) {
      if (sideA == sideB && sideA == sideC) {
        types.equilateral = types.equilateral + 1;

      } else {
        types.isosceles = types.isosceles + 1;
      }
    } else {
      types.scalene = types.scalene + 1;
    }
  }
}

bool validTriangle(float sideA, float sideB, float sideC) {
  bool isTriangle = true;

  return isTriangle;
}

void registerTriangle(Triangle triangles[MAX_LENGHT], TriangleTypes types) {
  float sideA, sideB, sideC;
  bool invalid;

  do {
    printf("Enter the 1st side: ");
    scanf(" %f", &sideA);

    printf("Enter the 2nd side: ");
    scanf(" %f", &sideB);

    printf("Enter the 3rd side: ");
    scanf(" %f", &sideC);

    invalid = !validTriangle(sideA, sideB, sideC);

    if (invalid) printf("\aWarning: invalid sides lenghts, try again.");
  } while (invalid);

  triangles[lenght].sideA = sideA;
  triangles[lenght].sideB = sideB;
  triangles[lenght].sideC = sideC;

  lenght++;

  updateTriangleTypesCount(triangles, types);
}

int main() {
  Triangle triangles[MAX_LENGHT] = {};
  TriangleTypes types = {};

  updateTriangleTypesCount(triangles, types);

  int option = -1;

  while (option != 0) {
    option = menu();

    // for (int i = 0; i < lenght; i++) {
    //   printf("\nTriangle %i", i + 1);
    //   printf("\nSideA: %f", triangles[i].sideA);
    //   printf("\nSideB: %f", triangles[i].sideB);
    //   printf("\nSideC: %f", triangles[i].sideC);
    // }

    // printf("\nequilateral: %d", types.equilateral);
    // printf("\nisosceles: %d", types.isosceles);
    // printf("\nscalene: %d", types.scalene);

    switch (option) {
    case 0:
      printf("\nThank you for using this program");
      break;
    case 1:
      registerTriangle(triangles, types);
      break;
    case 2:
      printf("\nEquilateral triangles count: %i", types.equilateral);
      break;
    case 3:
      printf("\nIsosceles triangles count: %i", types.isosceles);
      break;
    case 4:
      printf("\nScalene triangles count: %i", types.scalene);
      break;
    default:
      printf("\nError: invalid option.");
      break;
    }
  };

  return 0;
}