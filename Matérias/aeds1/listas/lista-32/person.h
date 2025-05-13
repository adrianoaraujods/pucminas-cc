#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "date.h"
#include "parse.h"

#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

#define MAX_LENGTH 255
#define MAX_STRING 64

typedef struct {
  char name[MAX_STRING];
  char cpf[12];
  Date birthday;
} Person;

bool validCPF(const char* CPF, const bool PRINT_ERRORS) {
  bool valid = true;

  if (strlen(CPF) != 11) {
    valid = false;

    if (PRINT_ERRORS) printf("\aError: invalid size");
  }

  if (valid) {
    bool equalNumbers = true;
    int i = 1;

    while (equalNumbers && i < 11) {
      if (CPF[i] != CPF[0]) {
        equalNumbers = false;
      } else i++;
    }

    if (equalNumbers) {
      valid = false;

      if (PRINT_ERRORS) printf("\aError: all digits should be diffrent.");
    }
  }

  int i = 0, verificationSum = 0;
  while (valid && i < 9) {
    if (!isdigit(CPF[i])) {
      valid = false;

      if (PRINT_ERRORS) printf("\aError: invalid character '%c'", CPF[i]);
    } else {
      verificationSum += toInt(CPF[i]) * (10 - i);

      i++;
    };
  }

  if (valid) {
    int firstDigit = (
      verificationSum % 11 < 2
      ? 0
      : 11 - (verificationSum % 11));

    if (firstDigit != toInt(CPF[9])) {
      valid = false;

      if (PRINT_ERRORS) printf("\aError: invalid 1st verification digit.");
    };
  }

  if (valid) {
    verificationSum = 0;

    for (int i = 0; i < 10; i++) {
      verificationSum += toInt(CPF[i]) * (11 - i);
    }

    int secondDigit = (
      verificationSum % 11 < 2
      ? 0
      : 11 - (verificationSum % 11));

    if (secondDigit != toInt(CPF[10])) {
      valid = false;

      if (PRINT_ERRORS) printf("\aError: invalid 2nd verification digit");
    };
  }

  return valid;
}

void scanCPF(char cpf[12]) {
  bool invalid;

  do {
    printf("\nEnter CPF, only digits: ");
    fflush(stdin);
    fgets(cpf, 12, stdin);

    invalid = !validCPF(cpf, true);
  } while (invalid);
}

char* scanName(char* name) {
  bool invalid;

  do {
    printf("\nEnter the name: ");
    getchar();
    fgets(name, MAX_STRING - 1, stdin);

    invalid = strlen(name) < 3;

    if (invalid) printf("\aWarning: invalid input, must have at least 3 characters.");
  } while (invalid);

  return name;
}

Person scanPerson() {
  Person person;

  scanName(person.name);

  person.birthday = scanDate();

  scanCPF(person.cpf);

  return person;
}

void printPerson(Person person) {
  printf("\n");

  printf(
    "\nName: %s Age: %d years old.",
    person.name,
    yearsElapsedSince(person.birthday)
  );
}

void printPeopleByName(Person people[MAX_LENGTH], int lenght, char* name) {
  for (int i = 0; i < lenght; i++) {
    if (strcmp(people[i].name, name) == 0) {
      printPerson(people[i]);
    }
  }
}

void searchByName(Person people[], int lenght) {
  char name[MAX_STRING];

  scanName(name);

  printPeopleByName(people, lenght, name);
}

int findPersonByCPF(Person people[MAX_LENGTH], int lenght, char cpf[12]) {
  int personIndex = -1;
  bool find = false;
  int i = 0;

  while (!find && i < lenght) {
    if (strcmp(people[i].cpf, cpf) == 0) {
      find = true;
      personIndex = i;
    };

    i++;
  }

  return personIndex;
}

void searchByCPF(Person people[], int lenght) {
  char cpf[12];
  scanCPF(cpf);

  int index = findPersonByCPF(people, lenght, cpf);

  if (index >= 0) {
    printPerson(people[index]);
  } else {
    printf("\nNo person find with the CPF: %s", cpf);
  }
}

#endif
