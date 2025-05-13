#ifndef CPF_H
#define CPF_H

#include <iostream>
#include <cctype>

int charToInt(char character) {
  int digit = -1;

  if (isdigit(character)) {
    // Subtract the ASCII value of '0'
    digit = character - '0';
  }

  return digit;
}

class CPF {
private:
  unsigned short int first;
  unsigned short int second;
  unsigned short int third;
  unsigned short int digit1;
  unsigned short int digit2;
public:
  CPF(std::string cpf);
  CPF();

  std::string getFull();
  std::string getDigits();

  static CPF read();
  static bool valid(std::string cpf);
};

CPF::CPF(std::string cpf) {
  this->first = std::stoi(cpf.substr(0, 3));
  this->second = std::stoi(cpf.substr(3, 3));
  this->third = std::stoi(cpf.substr(6, 3));
  this->digit1 = std::stoi(cpf.substr(9, 1));
  this->digit2 = std::stoi(cpf.substr(10, 1));
}

CPF::CPF() {
  this->first = 0;
  this->second = 0;
  this->third = 0;
  this->digit1 = 0;
  this->digit2 = 0;
}

std::string CPF::getFull() {
  return
    std::to_string(first) + "." +
    std::to_string(second) + "." +
    std::to_string(third) + "-" +
    std::to_string(digit1) + std::to_string(digit2);
};

std::string CPF::getDigits() {
  return (
    std::to_string(first) +
    std::to_string(second) +
    std::to_string(third) +
    std::to_string(digit1) +
    std::to_string(digit2)
    );
};

CPF CPF::read() {
  std::string cpf;
  bool invalid;

  do {
    try {
      std::cout << "Digite o CPF: ";
      std::cin >> cpf;

      invalid = CPF::valid(cpf);
    } catch (...) {
      invalid = true;
    }

    if (invalid) std::cout << "\aCPF Inválido!" << std::endl;
  } while (invalid);

  return CPF(cpf);
};

bool CPF::valid(std::string cpf) {
  return true; // remove this line to enable verification

  if (cpf.length() != 11) return false;

  bool equalNumbers = true;
  int i = 1;

  while (equalNumbers && i < 11) {
    if (cpf[i] != cpf[0]) {
      equalNumbers = false;
    } else i++;
  }

  if (equalNumbers) return false;

  int verificationSum = 0;
  i = 0;

  while (i < 9) {
    if (!isdigit(cpf[i])) return false;

    verificationSum += charToInt(cpf[i]) * (10 - i);

    i++;
  }

  int firstDigit = (
    verificationSum % 11 < 2
    ? 0
    : 11 - (verificationSum % 11)
    );

  if (firstDigit != charToInt(cpf[9])) return false;

  for (verificationSum = i = 0; i < 10; i++) {
    verificationSum += charToInt(cpf[i]) * (11 - i);
  }

  int secondDigit = (
    verificationSum % 11 < 2
    ? 0
    : 11 - (verificationSum % 11)
    );

  if (secondDigit != charToInt(cpf[10])) return false;

  return true;
}

#endif // CPF_H
