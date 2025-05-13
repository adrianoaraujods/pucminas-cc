#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "date.h"
#include "person.h"
#include "file.h"

int head = 0;

int optionsMenu() {
  int option;
  bool invalid;

  do {
    printf("\n\tOPTIONS MENU\n");
    printf("\t0. Exit program\n");
    printf("\t1. Register Person\n");
    printf("\t2. List all people\n");
    printf("\t3. Search Person by name\n");
    printf("\t4. Search by CPF\n");
    printf("\t5. Delete Person\n");
    printf("\t6. Delete all people\n");

    printf("\nEnter the desired option: ");
    scanf("%d", &option);

    invalid = option < 0 || option > 6;

    if (invalid) {
      printf("\aWarning: invalid input, choose a value from 0 to 6.\n");
    }
  } while (invalid);

  return option;
}

void registerPerson(Person people[MAX_LENGTH]) {
  if (head <= MAX_LENGTH) {
    Person person = scanPerson();

    people[head] = person;

    head++;

    printf("\nPerson %d registered successfully!\n", head);
  } else {
    printf("\aError: Maximum people registered reached.\n");
  }
}

void printAllPeople(Person people[MAX_LENGTH]) {
  if (head > 0) {
    for (int i = 0; i < head; i++) {
      printPerson(people[i]);
    }
  } else {
    printf("\nNo people registered.");
  }
}

void deletePerson(Person people[MAX_LENGTH]) {
  char cpf[12];
  scanCPF(cpf);

  int index = findPersonByCPF(people, head, cpf);

  if (index >= 0) {
    printPerson(people[index]);

    char confirm;
    bool invalid;

    do {
      printf("\nAre sure you want to delete this person?");
      printf("\nThis action cannot be undone!");
      printf("\nEnter [Y/n]: ");
      fflush(stdin);
      scanf(" %c", &confirm);
      confirm = toupper(confirm);

      invalid = confirm != 'Y' && confirm != 'N';

      if (invalid) printf("\nWarning: invalid input.");
    } while (invalid);

    if (confirm == 'Y') {
      for (int i = index; i < head; i++) {
        people[index] = people[i + 1];
      }

      head--;
    } else {
      printf("\nAction canceled.");
    };
  } else {
    printf("\nNo person with the CPF: %s was found.", cpf);
  }
};

int main() {
  Person people[MAX_LENGTH] = {};

  loadFile("_people-amount.dat", &head, sizeof(head), 1, false);

  if (head > MAX_LENGTH) head = MAX_LENGTH;

  loadFile("_people.dat", people, sizeof(Person), head, false);

  int option;

  printf("\nPeople Functions!\n");

  do {
    option = optionsMenu();

    switch (option) {
    case 0:
      printf("Thanks for using this program!\n");
      break;
    case 1:
      registerPerson(people);
      break;
    case 2:
      printAllPeople(people);
      break;
    case 3:
      searchByName(people, head);
      break;
    case 4:
      searchByCPF(people, head);
      break;
    case 5:
      deletePerson(people);
      break;
    case 6:
      head = 0;
      printf("\nAll people were deleted!\n");
      break;
    default:
      printf("\aError: invalid option.");
      break;
    }
  } while (option != 0);

  saveFile("_people-amount.dat", &head, sizeof(head), 1, true);
  saveFile("_people.dat", people, sizeof(Person), head, true);

  return 0;
}
