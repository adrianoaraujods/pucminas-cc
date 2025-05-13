// Importa a biblioteca para o uso de funções de input e output
#include <stdio.h>

// Importa a biblioteca para o uso do tipo boolean
#include <stdbool.h>

// Importa a biblioteca para o uso da função de rais quadrada
#include <math.h>

// Função que retorna lê um número positivo do terminal
int readPositiveInteger() {
  int number;
  bool invalid;

  // Estrutura de repetição para garantir que o número seja positivo
  do {
    printf("\nEnter a number: ");
    scanf("%d", &number);

    invalid = number < 0;

    // Escreve mensagem de aviso quando o número é negativo
    if (invalid) printf("\aWarning: invalid input, the number should be positive.");
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
    printf("The number %d is prime!", number);
  } else {
    printf("The number %d is not prime!", number);
  }

  return 0;
}
