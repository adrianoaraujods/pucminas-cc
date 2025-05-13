#include <iostream>
#include <cstdlib>

#include "cpf.h"
#include "date.h"
#include "person.h"
#include "classroom.h"

unsigned Person::peopleCount = 0;
unsigned Professor::professorsCount = 0;
unsigned Student::studentsCount = 0;

int main() {
  setlocale(LC_ALL, "portuguese");

  // Classroom::loadData();

  Classroom::addStudent(new Student("Adriano", CPF("12345678910"), Date(2, 12, 2000), 1));
  Classroom::addStudent(new Student("João", CPF("12345678911"), Date(1, 1, 2001), 1));
  Classroom::addStudent(new Student("Pedro", CPF("12345678912"), Date(3, 12, 2002), 1));
  Classroom::addStudent(new Student("Adriano", CPF("12345678913"), Date(1, 1, 2003), 1));

  int option;
  bool exit = false;

  do {
    std::cout << "Menu de opções:" << std::endl;
    std::cout << "0 - Sair do programa" << std::endl;
    std::cout << "1 - Cadastrar uma pessoa" << std::endl;
    std::cout << "2 - Listar todas as pessoas" << std::endl;
    std::cout << "3 - Pesquisar por nome" << std::endl;
    std::cout << "4 - Pesquisar por CPF" << std::endl;
    std::cout << "5 - Excluir pessoa" << std::endl;
    std::cout << "6 - Apagar todas as pessoas" << std::endl;
    std::cout << "7 - Aniversariantes do mês" << std::endl;

    std::cout << "Digite a opção desejada: ";
    std::cin >> option;

    switch (option) {
    case 0:
      std::cout << "Obrigado por usar o programa!" << std::endl;
      exit = true;
      break;
    case 1:
      do {
        std::cout << "1 - Cadastrar uma pessoa" << std::endl;
        std::cout << "\t1.0 - Voltar ao menu anterior" << std::endl;
        std::cout << "\t1.1 - Cadastrar um Professor" << std::endl;
        std::cout << "\t1.2 - Cadastrar um Aluno" << std::endl;

        std::cout << "Digite a opção desejada: ";
        std::cin >> option;

        switch (option) {
        case 0:
          break;
        case 1:
          Classroom::addProfessor();
          break;
        case 2:
          Classroom::addStudent();
          break;
        default:
          std::cout << "\aOpção inválida!" << std::endl;
          break;
        }
      } while (option < 0 || option > 2);

      break;
    case 2:
      do {
        std::cout << "2 - Listar todas as pessoas" << std::endl;
        std::cout << "\t2.0 - Voltar ao menu anterior" << std::endl;
        std::cout << "\t2.1 - Listar todos os Professores" << std::endl;
        std::cout << "\t2.2 - Listar todos os Alunos" << std::endl;

        std::cout << "Digite a opção desejada: ";
        std::cin >> option;

        switch (option) {
        case 0:
          break;
        case 1:
          Classroom::listProfessors();
          break;
        case 2:
          Classroom::listStudents();
          break;
        default:
          std::cout << "\aOpção inválida!" << std::endl;
          break;
        }
      } while (option < 0 || option > 2);

      break;
    case 3:
      do {
        std::cout << "3 - Pesquisar por nome" << std::endl;
        std::cout << "\t3.0 - Voltar ao menu anterior" << std::endl;
        std::cout << "\t3.1 - Pesquisar Professores pelo nome" << std::endl;
        std::cout << "\t3.2 - Pesquisar Alunos pelo nome" << std::endl;

        std::cout << "Digite a opção desejada: ";
        std::cin >> option;

        std::string name;
        if (option == 1 || option == 2) {
          std::cout << "Digite o nome: ";
          std::cin >> name;
        }

        switch (option) {
        case 0:
          break;
        case 1:
          Classroom::findProfessorsByName(name);
          break;
        case 2:
          Classroom::findStudentsByName(name);
          break;
        default:
          std::cout << "\aOpção inválida!" << std::endl;
          break;
        }
      } while (option < 0 || option > 2);

      break;
    case 4:
      do {
        std::cout << "4 - Pesquisar por CPF" << std::endl;
        std::cout << "\t4.0 - Voltar ao menu anterior" << std::endl;
        std::cout << "\t4.1 - Pesquisar Professores pelo CPF" << std::endl;
        std::cout << "\t4.2 - Pesquisar Alunos pelo CPF" << std::endl;

        std::cout << "Digite a opção desejada: ";
        std::cin >> option;

        switch (option) {
        case 0:
          break;
        case 1:
          Classroom::findProfessorsByCPF(CPF::read());
          break;
        case 2:
          Classroom::findStudentsByCPF(CPF::read());
          break;
        default:
          std::cout << "\aOpção inválida!" << std::endl;
          break;
        }
      } while (option < 0 || option > 2);

      break;
    case 5:
      do {
        std::cout << "5 - Apagar pessoa" << std::endl;
        std::cout << "\t5.0 - Voltar ao menu anterior" << std::endl;
        std::cout << "\t5.1 - Apagar um Professor pelo CPF" << std::endl;
        std::cout << "\t5.2 - Apagar um Aluno pelo CPF" << std::endl;

        std::cout << "Digite a opção desejada: ";
        std::cin >> option;

        switch (option) {
        case 0:
          break;
        case 1:
          Classroom::deleteProfessorsByCPF(CPF::read());
          break;
        case 2:
          Classroom::deleteStudentsByCPF(CPF::read());
          break;
        default:
          std::cout << "\aOpção inválida!" << std::endl;
          break;
        }
      } while (option < 0 || option > 2);

      break;
    case 6:
      do {
        std::cout << "6 - Apagar todas as pessoas" << std::endl;
        std::cout << "\t6.0 - Voltar ao menu anterior" << std::endl;
        std::cout << "\t6.1 - Apagar todos os Professores" << std::endl;
        std::cout << "\t6.2 - Apagar todos os Alunos" << std::endl;

        std::cout << "Digite a opção desejada: ";
        std::cin >> option;

        switch (option) {
        case 0:
          break;
        case 1:
          Classroom::deleteAllProfessors();
          break;
        case 2:
          Classroom::deleteAllStudents();
          break;
        default:
          std::cout << "\aOpção inválida!" << std::endl;
          break;
        }
      } while (option < 0 || option > 2);

      break;
    case 7:
      bool invalid;
      int month;

      do {
        std::cout << "Digite o mês: ";
        std::cin >> month;

        invalid = month < 1 || month > 12;

        if (invalid) std::cout << "\aMês inválido!";
      } while (invalid);

      Classroom::listBirthdaysFromMonth(month);

      break;
    default:
      std::cout << "\aOpção inválida!" << std::endl;
    }
  } while (!exit);

  // Classroom::saveData();

  return 0;
}
