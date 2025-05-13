#include <iostream>
#include <ctime>
#include <cstdlib>

void loteryNumbers(int n) {
  std::cout << (rand() % 60) + 1 << std::endl;

  if (n > 1) loteryNumbers(n - 1);
}

bool isPerfect(int number) {
  bool perfect = false;

  if (number > 1) {
    int sum = 1;

    for (int i = 2; i <= number / 2; i++) {
      if (number % i == 0) {
        sum += i;

        std::cout << "SUM: " << sum << std::endl;
      }
    }

    perfect = number == sum;
  }

  return perfect;
}

int main() {
  std::srand(std::time(NULL));

  return 0;
}
