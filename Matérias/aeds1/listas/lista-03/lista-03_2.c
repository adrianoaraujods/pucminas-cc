#include <stdio.h>
#include <stdlib.h>

void main() {
  printf("\nCheck your new salary!");

  printf("\nRole Code Menu: ");
  printf("\n1. Clerk");
  printf("\n2. Secretary");
  printf("\n3. Cashier");
  printf("\n4. Manager");
  printf("\n5. Director");

  int roleCode;
  printf("\n\nEnter your role code: ");
  scanf("%d", &roleCode);

  if (roleCode < 1 || roleCode > 5) {
    printf("Invalid role code!");

    return;
  }

  float salary;
  printf("\nEnter your current salary: ");
  scanf("%f", &salary);

  char* role;

  switch (roleCode) {
  case 1:
    salary += salary * 0.5;

    printf("\nRole: Clerk");
    printf("\nIncrease: 50%%");

    break;
  case 2:
    salary += salary * 0.35;

    printf("\nRole: Secretary");
    printf("\nIncrease: 35%%");

    break;
  case 3:
    salary += salary * 0.2;

    printf("\nRole: Cashier");
    printf("\nIncrease: 20%%");

    break;
  case 4:
    salary += salary * 0.1;

    printf("\nRole: Manager");
    printf("\nIncrease: 10%%");

    break;
  case 5:
    printf("\nRole: Director");
    printf("\nIncrease: 0%%");

    break;
  }

  printf("\nNew salary: %f", salary);
}
