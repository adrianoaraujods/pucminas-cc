#ifndef PERSON_H
#define PERSON_H

#include <iostream>

#include "date.h"
#include "cpf.h"

enum Title { Especialista, Mestre, Doutor };

class Person {
private:
  static unsigned peopleCount;

  std::string name;
  CPF cpf;
  Date birth;
public:
  static void setCount(unsigned value);
  static unsigned getCount();
  static Person read();

  Person(std::string name, CPF cpf, Date birth);
  Person();
  ~Person();

  std::string getName();
  CPF getCPF();
  Date getBirth();

  void print();
};

class Professor : public Person {
private:
  static unsigned professorsCount;

  Title title;
public:
  static void setCount(unsigned value);
  static unsigned getCount();
  static Professor read();

  Professor(std::string name, CPF cpf, Date birth, Title title);
  Professor(Person person, Title title);
  Professor();
  ~Professor();

  Title getTitle();

  void print();
};

class Student : public Person {
private:
  static unsigned studentsCount;

  unsigned id;
public:
  static void setCount(unsigned value);
  static unsigned getCount();
  static Student read();

  Student(std::string name, CPF cpf, Date birth, unsigned id);
  Student(Person person, unsigned id);
  Student();
  ~Student();

  unsigned getId();

  void print();
};

Person::Person(std::string name, CPF cpf, Date birth) {
  this->name = name;
  this->cpf = CPF(cpf);
  this->birth = Date(birth);

  peopleCount++;
}

Person::Person() {
  this->name = "";
  this->cpf = CPF("00000000000");
  this->birth = Date();

  peopleCount++;
}

Professor::Professor(std::string name, CPF cpf, Date birth, Title title)
  : Person::Person(name, cpf, birth) {
  this->title = title;

  professorsCount++;
}

Professor::Professor(Person person, Title title)
  : Person::Person(person) {
  this->title = title;

  professorsCount++;
}

Professor::Professor()
  : Person::Person() {
  this->title = Especialista;

  professorsCount++;
}

Student::Student(std::string name, CPF cpf, Date birth, unsigned id)
  : Person::Person(name, cpf, birth) {
  this->id = id;

  studentsCount++;
}

Student::Student(Person person, unsigned id)
  : Person::Person(person) {
  this->id = id;

  studentsCount++;
}

Student::Student()
  : Person::Person() {
  this->id = 0;

  studentsCount++;
}

Person::~Person() {
  this->peopleCount--;
}

Professor::~Professor() {
  this->professorsCount--;
}

Student::~Student() {
  this->studentsCount--;
}

void Person::setCount(unsigned value) {
  peopleCount = value;
}

void Professor::setCount(unsigned value) {
  professorsCount = value;
}

void Student::setCount(unsigned value) {
  studentsCount = value;
}

unsigned Person::getCount() {
  return peopleCount;
}

unsigned Professor::getCount() {
  return professorsCount;
}

unsigned Student::getCount() {
  return studentsCount;
}

std::string Person::getName() {
  return this->name;
}

CPF Person::getCPF() {
  return this->cpf;
}

Date Person::getBirth() {
  return this->birth;
}

Title Professor::getTitle() {
  return this->title;
}

unsigned Student::getId() {
  return this->id;
}

void Person::print() {
  std::cout << this->name << std::endl;
  std::cout << "CPF: " << this->cpf.getFull() << std::endl;
  std::cout << "Data de nascimento: "; this->birth.print();
}

void Professor::print() {
  this->Person::print();

  std::cout << "Titulo: " << this->title << std::endl;
}

void Student::print() {
  this->Person::print();

  std::cout << "Matricula: " << id << std::endl;
}

Person Person::read() {
  std::string name;
  std::cout << "Digite o nome: ";
  std::cin >> name;

  CPF cpf = CPF::read();
  Date date = Date::read();

  return Person(name, cpf, date);
}

Professor Professor::read() {
  Person person = Person::read();

  int option;
  bool invalid;

  do {
    std::cout << "Menu de Títulos" << std::endl;
    std::cout << "\t1 - Especialista" << std::endl;
    std::cout << "\t2 - Mestre" << std::endl;
    std::cout << "\t3 - Doutor" << std::endl;
    std::cout << "Escolha um título [1-3]: ";
    std::cin >> option;

    invalid = option < 1 || option > 3;

    if (invalid) std::cout << "\aOpção Inválida!" << std::endl;
  } while (invalid);

  Title title = static_cast<Title>(option - 1);

  return Professor(person, title);
}

Student Student::read() {
  Person person = Person::read();

  unsigned id;
  std::cout << "Digite o número da matrícula: ";
  std::cin >> id;

  return Student(person, id);
}

#endif // PERSON_H
