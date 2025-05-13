#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LENGTH 255

int head = 0;

typedef struct {
  char name[MAX_LENGTH];
  int age;
} Student;

int optionsMenu() {
  int option; bool invalid;

  do {
    printf("\n\tOPTIONS MENU\n");
    printf("\t0. Exit program\n");
    printf("\t1. Register student\n");
    printf("\t2. List all students\n");
    printf("\t3. Get class average age\n");

    printf("\nEnter the desired option: ");
    scanf("%d", &option);

    invalid = option < 0 || option > 3;

    if (invalid) {
      printf("\aWarning: invalid input, choose a value from 0 to 3.\n");
    }
  } while (invalid);

  return option;
}

Student createStudent() {
  Student student;
  bool invalid;

  do {
    printf("\nEnter the student name: ");
    getchar();
    fgets(student.name, MAX_LENGTH - 1, stdin);

    int lenght = strlen(student.name);

    if (lenght > 0 && student.name[lenght - 1] == '\n') {
      student.name[lenght - 1] = '\0';
    }

    invalid = lenght < 3;

    if (invalid) {
      printf("\aWarning: invalid input, the name should have at least 3 characters.");
    }
  } while (invalid);

  do {
    printf("\nEnter the student age: ");
    scanf("%d", &student.age);

    getchar();

    invalid = student.age < 0;

    if (invalid) {
      printf("\aWarning: invalid input, the age should be greather than zero.");
    }
  } while (invalid);

  return student;
}

void registerStudent(Student students[MAX_LENGTH]) {
  if (head <= MAX_LENGTH) {
    Student student = createStudent();

    students[head] = student;

    head++;

    printf("\nStudent %d registered successfully!\n", head);
  } else {
    printf("\aError: Maximum students registered reached.\n");
  }
}

void printStudent(Student students[MAX_LENGTH], int index) {
  printf("\n");

  printf(
    "\tStudent %d - %s, %d years old.\n",
    index + 1, students[index].name, students[index].age
  );
}

void printAllStudents(Student students[MAX_LENGTH]) {
  if (head > 0) {
    for (int i = 0; i < head; i++) {
      printStudent(students, i);
    }
  } else {
    printf("\nNo students registered.");
  }
}

float classAverageAge(Student students[MAX_LENGTH]) {
  int sum = 0;

  for (int i = 0; i < head; i++) {
    sum += students[i].age;
  }

  return (float)sum / head;
}

void printClassAverageAge(Student students[MAX_LENGTH]) {
  if (head > 0) {
    printf("\nThe class average age is %.1f years old.\n", classAverageAge(students));
  } else {
    printf("\nNo students registered.");
  }
}

int main() {
  Student students[MAX_LENGTH] = {};

  int option;

  printf("Class Functions!\n");

  do {
    option = optionsMenu();

    switch (option) {
    case 0:
      printf("Thanks for using this program!\n");
      break;
    case 1:
      registerStudent(students);
      break;
    case 2:
      printAllStudents(students);
      break;
    case 3:
      printClassAverageAge(students);
      break;
    default:
      printf("\aError: invalid option.");
      break;
    }
  } while (option != 0);

  return 0;
}
