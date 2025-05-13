class PrimeNumber
{
  // Função que retorna lê um número positivo do terminal
  static int ReadPositiveInteger()
  {
    int number;
    bool invalid;

    // Estrutura de repetição para garantir que o número seja positivo
    do
    {
      Console.Write("\nEnter a number: ");

      number = Convert.ToInt16(Console.ReadLine());

      invalid = number < 0;

      // Escreve mensagem de aviso quando o número é negativo
      if (invalid) Console.Write("\aWarning: invalid input, the  number should be positive.");
    } while (invalid);

    return number;
  }

  // Função que recebe um número e retorna Verdadeiro se ele for primo ou Falso caso contrário
  static bool NumberIsPrime(int number)
  {
    // Teste executado para números negativos e um que pela definição não são primos
    bool isPrime = number > 1;

    // Variável de controle para evitar testes desnecessários
    int maxTest = (int)Math.Sqrt(number);
    int i = 2;

    // Estrutura de repetição para verificar se o número não tem nenhum divisor fora 1 e ele mesmo
    while (isPrime && i <= maxTest)
    {
      if (number % i == 0) isPrime = false;

      i++;
    }

    return isPrime;
  }

  // Função principal para a execução do algoritmo
  static void Main()
  {
    int number = ReadPositiveInteger();

    // Escreve no terminal se o número é primo ou não
    if (NumberIsPrime(number))
    {
      Console.Write("The number %d is prime!", number);
    }
    else
    {
      Console.Write("The number %d is not prime!", number);
    }
  }
}
