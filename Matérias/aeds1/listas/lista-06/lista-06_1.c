#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void main() {
  printf("\nClass profile");

  int members;
  do {
    printf("\nEnter the amount of members in the class: ");
    scanf("%i", &members);
  } while (
    (members < 1)                                                       //
    && printf("\aWarning: invalid input. Enter a value of at least 1.") //
    );

  int oldest = 0, youngest = 100, males = 0, adults = 0;

  for (int i = 1; i <= members; i++) {
    char gender;
    do {
      printf("\nMember %i gender [M/f]: ", i);
      scanf(" %c", &gender);
      gender = toupper(gender);
    } while (
      !(gender == 'M' || gender == 'F')                                                //
      && printf("\aWarning: invalid input. The value should be 'M', 'F', 'm' or 'f'.") //
      );

    int age;
    do {
      printf("Member %i age: ", i);
      scanf(" %i", &age);
    } while (
      (age < 0 || age > 100)                                              //
      && printf("\aWarning: invalid input. Enter a value between 0-100.") //
      );

    if (gender == 'M') {
      males++;
    }

    if (age >= 18) {
      adults++;
    }

    if (age > oldest) {
      oldest = age;
    }

    if (age < youngest) {
      youngest = age;
    }
  }

  int females = (members - males);
  float adultsPercentage = (adults * 100) / members;
  float malesPercentage = (males * 100) / members;
  float femalesPercentage = (females * 100) / members;

  printf("\nClass Profile:");
  printf("\nMales: %i/%i, %f%%", males, members, malesPercentage);
  printf("\nFemales: %i/%i, %f%%", females, members, femalesPercentage);
  printf("\nAdults: %i/%i, %f%%", adults, members, adultsPercentage);
  printf("\nYoungest: %i", youngest);
  printf("\nOldest: %i", oldest);
}
