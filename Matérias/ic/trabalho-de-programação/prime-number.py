# Importa a biblioteca para o uso da função de rais quadrada
import math

# Função que retorna lê um número positivo do terminal
def readPositiveInteger():
  number = -1

  # Estrutura de repetição para garantir que o número seja positivo
  while number < 0:
    try:
      number = int(input("Enter a number: "))
      
      # Escreve mensagem de aviso quando o número é negativo
      if number >= 0:
        return number
      else:
        print("Warning: invalid input, the number should be positive.")
    # Escreve mensagem de aviso quando o usuário não escreve um número
    except ValueError:
      print("Warning: invalid input, enter a number.")

# Função que recebe um número e retorna Verdadeiro se ele for primo ou Falso caso contrário
def numberIsPrime(number: int):
  # Teste executado para números negativos e um que pela definição não são primos
  isPrime = number > 1

  # Variável de controle para evitar testes desnecessários
  maxTest = int(math.sqrt(number))
  i = 2

  # Estrutura de repetição para verificar se o número não tem nenhum divisor fora 1 e ele mesmo
  while isPrime and i <= maxTest:
    if number % i == 0:
      isPrime = False

    i += 1
  
  return isPrime

# Função principal para a execução do algoritmo
def main():
  number = readPositiveInteger()

  # Escreve no terminal se o número é primo ou não
  if numberIsPrime(number):
    print(f"The number {number} is prime!")
  else:
    print(f"The number {number} is not prime!")

main()