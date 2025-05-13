#include <stdio.h>

#define MAX_STRING 64

typedef struct {
  char name[MAX_STRING];
  int age;
} Person;

void printPeople(Person people[], int amount) {
  printf("\n%s, %d anos", people[amount - 1].name, people[amount - 1].age);

  if (amount > 1) {
    printPeople(people, amount - 1);
  }
}

int main() {
  Person people[] = {
    { "Adriano", 10 },
    { "Arthur", 20 },
    { "Aline", 30 }
  };

  int amount = sizeof(people) / sizeof(Person);

  printPeople(people, amount);

  return 0;
}