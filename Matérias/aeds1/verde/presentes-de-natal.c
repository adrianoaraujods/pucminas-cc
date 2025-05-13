#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING 100
#define MAX_GIFTS 100
#define MAX_LISTS 100

typedef struct {
  char name[MAX_STRING];
  float price;
  unsigned int preference;
} Gift;

typedef struct {
  char name[MAX_STRING];
  int amount;
  Gift gifts[MAX_GIFTS];
} List;

int compareGift(const void* a, const void* b) {
  Gift* p1 = (Gift*)a;
  Gift* p2 = (Gift*)b;

  int comparison;

  if (p1->preference != p2->preference) {
    comparison = p2->preference - p1->preference;
  } else if (p1->price != p2->price) {
    comparison = (p1->price > p2->price) ? 1 : -1;
  } else {
    comparison = strcmp(p1->name, p2->name);
  }

  return comparison;
}


void sortGiftsOfList(List* list) {
  qsort(list->gifts, list->amount, sizeof(Gift), compareGift);
}

int main() {
  List lists[MAX_LISTS];
  unsigned int head = 0;

  while (scanf("%s %d", &lists[head].name, &lists[head].amount) != EOF) {
    for (int i = 0; i < lists[head].amount; i++) {
      getchar();
      fgets(lists[head].gifts[i].name, MAX_STRING, stdin);
      lists[head].gifts[i].name[strlen(lists[head].gifts[i].name) - 1] = '\0';

      scanf("%f %d",
        &lists[head].gifts[i].price,
        &lists[head].gifts[i].preference
      );
    }

    head++;
  }

  for (int list = 0; list < head; list++) {
    sortGiftsOfList(&lists[list]);

    printf("Lista de %s\n", lists[list].name);

    for (int gift = 0; gift < lists[list].amount; gift++) {
      printf("%s - R$%.2f\n",
        lists[list].gifts[gift].name,
        lists[list].gifts[gift].price
      );
    }

    printf("\n");
  }

  return 0;
}