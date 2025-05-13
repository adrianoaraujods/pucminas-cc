#include <stdio.h>

int getLargestIndex(int array[], int n) {
  int largestIndex = 0;

  for (int i = 1; i < n; i++) {
    if (array[i] < array[largestIndex]) largestIndex = i;
  }

  return largestIndex;
}

int evenInNumber(int number) {
  int count = 0, n = number, digit;

  do {
    digit = n % 10;
    n = n / 10;

    if ((digit % 2) == 0) count++;
  } while (n > 0);

  return count;
}

int main() {
  int count, position;
  scanf("%d %d\n", &count, &position);

  int sacks[count];
  for (int i = 0; i < count; i++) {
    int value;
    scanf("%d ", &value);
    sacks[i] = value;
  }

  int largestIndex, recived;
  while (position > 1) {
    largestIndex = getLargestIndex(sacks, count);
    recived = evenInNumber(sacks[largestIndex]);

    sacks[largestIndex] -= recived;

    position--;
  }

  printf("%d", recived);

  return 0;
}