#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 255
#define MAX_STRING 64

int head = 0;

typedef struct {
  int day, month, year;
} Date;

typedef struct {
  char name[MAX_STRING];
  Date birthDate;
} Student;

int optionsMenu() {
  int option; bool invalid;

  do {
    printf("\n\tOPTIONS MENU\n");
    printf("\t0. Exit program\n");
    printf("\t1. Register student\n");
    printf("\t2. List all students\n");
    printf("\t3. Get class average age\n");
    printf("\t4. Delete all students\n");

    printf("\nEnter the desired option: ");
    scanf("%d", &option);

    invalid = option < 0 || option > 4;

    if (invalid) {
      printf("\aWarning: invalid input, choose a value from 0 to 4.\n");
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
    fgets(student.name, MAX_STRING - 1, stdin);

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
    printf("\nEnter the student age [d/m/y]: ");
    scanf(
      "%d/%d/%d",
      &student.birthDate.day,
      &student.birthDate.month,
      &student.birthDate.year
    );

    invalid = false;

    if (student.birthDate.day < 1 || student.birthDate.day > 31) {
      printf("\aWarning: invalid input, day outside of range.");
      invalid = true;
    }

    if (student.birthDate.month < 1 || student.birthDate.month > 12) {
      printf("\aWarning: invalid input, month outside of range.");
      invalid = true;
    }

    if (student.birthDate.year < 1) {
      printf("\aWarning: invalid input, year outside of range.");
      invalid = true;
    }
  } while (invalid);

  return student;
}

void openHeadFile() {
  FILE* file = fopen("head.dat", "rb");

  if (file != NULL) {
    int data;

    fread(&data, sizeof(int), 1, file);

    if (data > 0) head = data >= MAX_LENGTH ? MAX_LENGTH : data;
  }

  fclose(file);
}

void openStudentsFile(Student students[MAX_LENGTH]) {
  FILE* file = fopen("students.dat", "rb");

  if (file != NULL) {
    openHeadFile();

    fread(students, sizeof(Student), head, file);

    // while (!feof(file) && head < MAX_LENGTH) {
    //   if (student.name != NULL && student.age >= 0) {
    //     students[head] = student;

    //     head++;
    //   }

    //   fread(&student, sizeof(Student), 1, file);
    // }
  } else {
    printf("\nError: unable to retrive data from 'students.dat' file.");
  }
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

int yearsElapsedSince(Date date) {
  time_t now = time(NULL);
  struct tm* today = localtime(&now);

  int year = today->tm_year + 1900;
  int month = today->tm_mon + 1;
  int day = today->tm_mday;

  int years = year - date.year;

  if (month < date.month || (month == date.month && day < date.day)) years--;

  return years;
};

void printDate(Date date) {
  printf("%d/%d/%d", date.day, date.month, date.year);
}

void printStudent(Student students[MAX_LENGTH], int index) {
  printf("\n");

  printf(
    "\tStudent %d - %s, %d years old.\n",
    index + 1, students[index].name,
    yearsElapsedSince(students[index].birthDate)
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
    sum += yearsElapsedSince(students[i].birthDate);
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

void saveHeadFile() {
  FILE* file = fopen("head.dat", "wb");

  if (file != NULL) {
    for (int i = 0; i < head; i++) {
      fwrite(&head, sizeof(Student), 1, file);
    }
  } else {
    printf("\nError saving students data.");
  }

  fclose(file);
}

void saveStudentsFile(Student students[MAX_LENGTH]) {
  saveHeadFile();

  FILE* file = fopen("students.dat", "wb");

  if (file != NULL) {
    fwrite(students, sizeof(Student), head, file);
  } else {
    printf("\nError saving students data.");
  }

  fclose(file);
}

int main() {
  Student students[MAX_LENGTH] = {};

  openStudentsFile(students);

  int option;

  printf("\nClass Functions!\n");

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
    case 4:
      head = 0;
      printf("\nAll students were deleted!\n");
      break;
    default:
      printf("\aError: invalid option.");
      break;
    }
  } while (option != 0);

  saveStudentsFile(students);

  return 0;
}
