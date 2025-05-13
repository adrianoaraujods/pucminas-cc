// Importa a biblioteca para o uso da função de rais quadrada
import java.util.Scanner;

public class PrimeNumber {
  // Função que retorna lê um número positivo do terminal
  public static int readPositiveInteger() {
    // Cria o objeto scanner para poder coletar dados do terminal
    Scanner scanner = new Scanner(System.in);

    int number; boolean invalid;

    // Estrutura de repetição para garantir que o número seja positivo
    do {
      System.out.println("Enter a number: ");
      number = scanner.nextInt();

      invalid = number < 0; 

      // Escreve mensagem de aviso quando o número é negativo
      if (invalid) System.out.println(
        "Warning: invalid input, the number should be positive."
      );
    } while (invalid);

    // Remove o objeto scanner para que não vaze recursos
    scanner.close();

    return number;
  }

  // Função que recebe um número e retorna Verdadeiro se ele for primo ou Falso caso contrário
  public static boolean numberIsPrime(int number) {
    // Teste executado para números negativos e um que pela definição não são primos
    boolean isPrime = number > 1;

    // Variável de controle para evitar testes desnecessários
    int maxTest = (int) Math.sqrt(number);
    int i = 2;

    // Estrutura de repetição para verificar se o número não tem nenhum divisor fora 1 e ele mesmo 
    while (isPrime && i <= maxTest) {
      if (number % i == 0) isPrime = false;

      i++;
    }

    return isPrime;
  }

  // Função principal para a execução do algoritmo
  public static void main(String[] args) {
    int number = readPositiveInteger();

    // Escreve no terminal se o número é primo ou não
    if (numberIsPrime(number)) {
      System.out.println("The number "+ number +" is prime!");
    } else {
      System.out.println("The number "+ number +" is not prime!");
    }
  }
}