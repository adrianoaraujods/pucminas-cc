#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void init()
{
  printf("\nFind the sum of all the digits of a given number!");
}

int readNumber()
{
  int number;
  bool hasInputError;

  do
  {
    printf("\nEnter the number: ");
    scanf(" %d", &number);

    hasInputError = number < 0;

    if (hasInputError)
    {
      printf("\aWarning: invalid input, the value should be greater than zero.");
    }
  } while (hasInputError);

  return number;
}

int sumOfDigits(int number, int sum)
{
  if (number > 0)
  {
    sum += sumOfDigits(number / 10, number % 10);
  }

  return sum;
}

int main()
{
  init();

  int number = readNumber();

  printf("\nThe sum of the digits is: %i", sumOfDigits(number, 0));

  return 0;
}