#ifndef CLASSROOM_H
#define CLASSROOM_H

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "person.h"

#define MAX_LENGHT 100
#define FILE_AMOUNT "_amount.bin"
#define FILE_PROFESSORS "_professors.bin"
#define FILE_STUDENTS "_students.bin"

Professor* professors[MAX_LENGHT];
Student* students[MAX_LENGHT];

class Classroom {
public:
  static void addProfessor(Professor* professor);
  static void addProfessor();
  static void addStudent(Student* student);
  static void addStudent();

  static void listProfessors();
  static void listStudents();

  static void findProfessorsByName(std::string name);
  static void findStudentsByName(std::string name);

  static void findProfessorsByCPF(CPF cpf);
  static void findStudentsByCPF(CPF cpf);

  static void deleteProfessorsByCPF(CPF cpf);
  static void deleteStudentsByCPF(CPF cpf);

  static void deleteAllProfessors();
  static void deleteAllStudents();

  static void listBirthdaysFromMonth(int month);

  static bool saveData();
  static bool loadData();
};

void Classroom::addProfessor(Professor* professor) {
  try {
    int head = Professor::getCount();

    professors[head] = professor;
  } catch (const std::bad_alloc& e) {
    // Tratar falta de memória primária
    std::cerr << "Erro: Falta de memória primária ao criar professor. Detalhes: " << e.what() << std::endl;
  }
}

void Classroom::addProfessor() {
  try {
    int head = Professor::getCount();

    professors[head] = new Professor(Professor::read());
  } catch (const std::bad_alloc& e) {
    // Tratar falta de memória primária
    std::cerr << "Erro: Falta de memória primária ao criar professor. Detalhes: " << e.what() << std::endl;
  }
}

void Classroom::addStudent(Student* student) {
  try {
    int head = Student::getCount();

    students[head - 1] = student;
  } catch (const std::bad_alloc& e) {
    // Tratar falta de memória primária
    std::cerr << "Erro: Falta de memória primária ao criar aluno. Detalhes: " << e.what() << std::endl;
  }
}

void Classroom::addStudent() {
  try {
    int head = Student::getCount();

    students[head - 1] = new Student(Student::read());
  } catch (const std::bad_alloc& e) {
    // Tratar falta de memória primária
    std::cerr << "Erro: Falta de memória primária ao criar aluno. Detalhes: " << e.what() << std::endl;
  }
}

void Classroom::listProfessors() {
  int head = Professor::getCount();

  if (head > 0) {
    for (int i = 0; i < head; i++) {
      professors[i]->print();
    }
  } else {
    std::cout << "Nenhum professor está cadastrado." << std::endl;
  }
}

void Classroom::listStudents() {
  int head = Student::getCount();

  if (head > 0) {
    for (int i = 0; i < head; i++) {
      students[i]->print();
    }
  } else {
    std::cout << "Nenhum aluno está cadastrado." << std::endl;
  }
}

void Classroom::findProfessorsByName(std::string name) {
  bool find = false;

  for (int i = 0; i < Professor::getCount(); i++) {
    if (professors[i]->getName() == name) {
      professors[i]->print();
      find = true;
    }
  }

  if (!find) std::cout << "Nenhum professor encontrado." << std::endl;
}

void Classroom::findStudentsByName(std::string name) {
  bool find = false;

  for (int i = 0; i < Student::getCount(); i++) {
    if (students[i]->getName() == name) {
      students[i]->print();
      find = true;
    }
  }

  if (!find) std::cout << "Nenhum aluno encontrado." << std::endl;
}

void Classroom::findProfessorsByCPF(CPF cpf) {
  bool find = false;
  int i = 0;

  while (!find && i < Professor::getCount()) {
    if (professors[i]->getCPF().getDigits() == cpf.getDigits()) {
      find = true;
    } else i++;
  }

  if (find) {
    professors[i]->print();
  } else {
    std::cout << "Nenhum aluno encontrado." << std::endl;
  }
}

void Classroom::findStudentsByCPF(CPF cpf) {
  bool find = false;
  int i = 0;

  while (!find && i < Student::getCount()) {
    if (students[i]->getCPF().getDigits() == cpf.getDigits()) {
      find = true;
    } else i++;
  }

  students[i]->print();
}

void Classroom::deleteProfessorsByCPF(CPF cpf) {
  bool find = false;
  int i = 0;

  while (!find && i < Professor::getCount()) {
    if (professors[i]->getCPF().getDigits() == cpf.getDigits()) {
      find = true;
    } else i++;
  }

  if (find) {
    delete professors[i];

    while (i < Professor::getCount()) {
      professors[i] = professors[i + 1];
      i++;
    }
  } else {
    std::cout << "Professor não encontrado." << std::endl;
  }
}

void Classroom::deleteStudentsByCPF(CPF cpf) {
  bool find = false;
  int i = 0;

  while (!find && i < Student::getCount()) {
    if (students[i]->getCPF().getDigits() == cpf.getDigits()) {
      find = true;
    } else i++;
  }

  if (find) {
    delete students[i];

    while (i < Student::getCount()) {
      students[i] = students[i + 1];
      i++;
    }
  } else {
    std::cout << "Aluno não encontrado." << std::endl;
  }
}

void Classroom::deleteAllProfessors() {
  for (int i = 0; i < Professor::getCount(); i++) {
    delete professors[i];
  }

  Professor::setCount(0);
}

void Classroom::deleteAllStudents() {
  for (int i = 0; i < Student::getCount(); i++) {
    delete students[i];
  }

  Student::setCount(0);
}

void Classroom::listBirthdaysFromMonth(int month) {
  for (int i = 0; i < Professor::getCount(); i++) {
    if (professors[i]->getBirth().getMonth() == month) {
      professors[i]->print();
    }
  }

  for (int i = 0; i < Student::getCount(); i++) {
    if (students[i]->getBirth().getMonth() == month) {
      students[i]->print();
    }
  }
}

bool Classroom::saveData() {
  bool success = false;

  FILE* file = fopen(FILE_AMOUNT, "wb");

  unsigned professorsCount = Professor::getCount();
  unsigned studentsCount = Student::getCount();

  if (file != NULL) {
    fwrite( // Salva o contador de professores
      &professorsCount,
      sizeof(professorsCount),
      1, file
    );

    fwrite( // Salva o contador de alunos
      &studentsCount,
      sizeof(studentsCount),
      1, file
    );

    fclose(file);
    success = true;
  };

  file = fopen(FILE_PROFESSORS, "wb");

  if (file != NULL) { // Salva os professores
    for (int i = 0; i < professorsCount; i++) {
      fwrite(professors[i], sizeof(Professor), 1, file);
    }

    fclose(file);
    success = true;
  };

  file = fopen(FILE_STUDENTS, "wb");

  if (file != NULL) { // Salva os alunos
    for (int i = 0; i < studentsCount; i++) {
      fwrite(students[i], sizeof(Student), 1, file);
    }

    fclose(file);
    success = true;
  };

  return success;
}

bool Classroom::loadData() {
  bool success = true;

  FILE* file = fopen(FILE_AMOUNT, "rb");

  unsigned professorsCount = 0, studentsCount = 0;

  if (file != NULL) {
    fread( // Carrega o contador de professores
      &professorsCount,
      sizeof(professorsCount),
      1, file
    );

    fread( // Carrega o contador de alunos
      &studentsCount,
      sizeof(studentsCount),
      1, file
    );

    fclose(file);
  } else {
    success = false;
  };

  file = fopen(FILE_PROFESSORS, "rb");

  if (file != NULL) { // Carrega todos os professores
    for (int i = 0; i < professorsCount; i++) {
      professors[i] = new Professor();

      if (fread(professors[i], sizeof(Professor), 1, file) != 1) {
        std::cerr << "Error reading object from file!" << std::endl;
        return false;
      };
    }

    Professor::setCount(professorsCount);

    fclose(file);
  } else {
    success = false;
  };

  file = fopen(FILE_STUDENTS, "rb");

  if (file != NULL) { // Carrega todos os alunos
    for (int i = 0; i < studentsCount; i++) {
      students[i] = new Student();

      fread(students[i], sizeof(Student), 1, file);
    }

    Student::setCount(studentsCount);

    fclose(file);
  } else {
    success = false;
  };

  if (success) {
    Person::setCount(professorsCount + studentsCount);
  }

  return success;
}

#endif // CLASSROOM_H
