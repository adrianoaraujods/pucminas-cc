#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void init()
{
  printf("\nDiamond Generator!");
}

int readLines()
{
  int lines;
  bool inputHasError;

  do
  {
    printf("\nEnter the diamond size in lines: ");
    scanf(" %i", &lines);

    inputHasError = lines < 0;

    if (inputHasError)
    {
      printf("\aWarning: invalid input, the value should be positive.");
    }
  } while (inputHasError);

  return lines;
}

void writeDiamondLine(int spaces, int asterisks)
{
  printf("\n");

  for (int i = 0; i < spaces; i++)
  {
    printf(" ");
  }

  for (int i = 0; i < asterisks; i++)
  {
    printf("*");
  }
}

void writeDiamond(int size, int line)
{
  int halfSize = size / 2;

  bool isEven = size % 2 == 0;

  if (isEven)
  {
    halfSize--;
  }

  int tipSize = isEven ? 2 : 1;

  int spaces = halfSize - line;
  int asterisks = tipSize + (line * 2);

  writeDiamondLine(spaces, asterisks);

  if (line < halfSize)
  {
    writeDiamond(size, line + 1);

    writeDiamondLine(spaces, asterisks);
  }
}

int main()
{
  init();

  int lines = readLines();

  writeDiamond(lines, 0);

  return 0;
}