#include <stdio.h>

#define MAX_STRING 64

typedef struct {
  char name[MAX_STRING];
  int age;
} Person;

void printPeople(Person people[], int amount) {
  for (int i = amount - 1; i >= 0; i--) {
    printf("\n%s, %d anos", people[i].name, people[i].age);
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