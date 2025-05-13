#include <stdio.h>

#define MAX_STRING 64

typedef struct {
  char brand[MAX_STRING];
  unsigned int year;
  float price;
} Car;

int main() {
  unsigned int amount;
  scanf("%d", &amount);

  Car cars[amount];

  for (int i = 0; i < amount; i++) {
    scanf("%s", &cars[i].brand);
    scanf("%d", &cars[i].year);
    scanf("%f", &cars[i].price);
  }

  float price;
  scanf("%f", &price);

  printf("Carros com preco menor que %.2f:\n", price);

  for (int i = 0; i < amount; i++) {
    if (cars[i].price < price) {
      printf("Marca: %s, Ano: %d, Preco: %.2f\n",
        cars[i].brand,
        cars[i].year,
        cars[i].price
      );
    }
  }
}