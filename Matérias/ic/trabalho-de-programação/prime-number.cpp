// Importa a biblioteca para o uso de funções de input e output
#include <iostream>

// Importa a biblioteca para o uso da função de rais quadrada
#include <cmath>

// Facilitador de chamadas de funções de input e output
using namespace std;

// Função que retorna lê um número positivo do terminal
int readPositiveInteger() {
  int number;
  bool invalid;

  // Estrutura de repetição para garantir que o número seja positivo
  do {
    cout << "\nEnter a number: ";
    cin >> number;

    invalid = number < 0;

    // Escreve mensagem de aviso quando o número é negativo
    if (invalid) cout << "\aWarning: invalid input, the number should be positive.";
  } while (invalid);

  return number;
}

// Função que recebe um número e retorna Verdadeiro se ele for primo ou Falso caso contrário
bool numberIsPrime(int number) {
  // Teste executado para números negativos e um que pela definição não são primos
  bool isPrime = number > 1;

  // Variável de controle para evitar testes desnecessários
  int maxTest = sqrt(number);
  int i = 2;

  // Estrutura de repetição para verificar se o número não tem nenhum divisor fora 1 e ele mesmo
  while (isPrime && i <= maxTest) {
    if (number % i == 0) isPrime = false;

    i++;
  }

  return isPrime;
}

// Função principal para a execução do algoritmo
int main() {
  int number = readPositiveInteger();

  // Escreve no terminal se o número é primo ou não
  if (numberIsPrime(number)) {
    cout << "The number ";
    cout << number;
    cout << " is prime!";
  } else {
    cout << "The number ";
    cout << number;
    cout << " is not prime!";
  }

  return 0;
}
