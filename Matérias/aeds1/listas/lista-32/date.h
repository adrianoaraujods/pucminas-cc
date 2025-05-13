#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

const unsigned int MONTH_DAYS[] = {
  31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

char* MONTH_NAMES[] = {
  "January",
  "February",
  "March",
  "April",
  "May",
  "June",
  "July",
  "August",
  "September",
  "October",
  "November",
  "December"
};

char* WEEK_NAMES[] = {
  "Sunday",
  "Monday",
  "Tuesday",
  "Wednesday",
  "Thursday",
  "Friday",
  "Saturday"
};

typedef struct {
  unsigned int seconds, minutes, hours;
} Time;

typedef struct {
  unsigned int day, month;
  int year;
  Time time;
} Date;

void printTime(const Time TIME) {
  printf(
    "%d:%d:%d",
    TIME.hours, TIME.minutes, TIME.seconds
  );
}

void printDate(const Date DATE) {
  printf(
    "%d/%d/%d",
    DATE.day, DATE.month, DATE.year
  );
}

void printDateTime(const Date DATE) {
  printf(
    "%d/%d/%d, ",
    DATE.day, DATE.month, DATE.year
  );

  printTime(DATE.time);
}

bool isLeapYear(const unsigned int YEAR) {
  bool isLeapYear = false;

  if (
    (YEAR % 400) == 0 ||
    (YEAR % 4) == 0 && (YEAR % 100) == 0
    ) {
    isLeapYear = true;
  }

  return isLeapYear;
}

bool validTime(const Time TIME, const bool PRINT_ERRORS) {
  bool valid = true;

  if (TIME.seconds >= 60) {
    valid = false;

    if (PRINT_ERRORS) printf("\aError: invalid seconds.");
  }

  if (TIME.minutes >= 60) {
    valid = false;

    if (PRINT_ERRORS) printf("\aError: invalid minutes.");
  }

  if (TIME.hours >= 24) {
    valid = false;

    if (PRINT_ERRORS) printf("\aError: invalid hours.");
  }

  return valid;
}

bool validDate(const Date DATE, const bool PRINT_ERRORS) {
  bool valid = true;

  bool leapYear = isLeapYear(DATE.year);

  if (DATE.month) {}

  if (DATE.month > 12) {
    valid = false;

    if (PRINT_ERRORS) printf("\aError: invalid month.");
  } else if (DATE.day > MONTH_DAYS[DATE.month - 1]) {
    valid = false;

    if (PRINT_ERRORS) printf("\aError: invalid month.");
  }

  return valid;
}

char* weekdayName(const Date DATE) {
  if (validDate(DATE, true)) {
    int m = DATE.month;
    int y = DATE.year;

    if (m < 3) {
      m += 12;
      y -= 1;
    }

    int k = y % 100;
    int j = y / 100;
    int dayOfWeek = (DATE.day + (13 * (m + 1)) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;

    char* name = WEEK_NAMES[dayOfWeek];

    return name;
  } else {
    return "";
  }
}

char* monthName(const unsigned int MONTH) {
  if (MONTH <= 12) {
    char* name = MONTH_NAMES[MONTH - 1];

    return name;
  } else {
    printf("\aError: invalid month.");

    return "";
  }
}

int yearsElapsedSince(Date date) {
  time_t now = time(NULL);
  struct tm* today = localtime(&now);

  int year = today->tm_year + 1900;
  int month = today->tm_mon + 1;
  int day = today->tm_mday;

  int years = year - date.year;

  if (month < date.month || (month == date.month && day < date.day)) years--;

  return years;
};

Time scanTime() {
  bool invalid;
  Time time;

  do {
    printf("\nEnter time [hh:mm:ss]: ");
    fflush(stdin);
    scanf(
      "%d:%d:%d",
      &time.hours,
      &time.minutes,
      &time.seconds
    );

    invalid = !validTime(time, true);
  } while (invalid);

  return time;
}

Date scanDate() {
  bool invalid;
  Date date;

  do {
    printf("\nEnter date [d/m/y]: ");
    fflush(stdin);
    scanf(
      "%d/%d/%d",
      &date.day,
      &date.month,
      &date.year
    );

    invalid = !validDate(date, true);
  } while (invalid);

  bool useTime;
  char temp;

  do {
    printf("\nEnter time? [Y/n]: ");
    fflush(stdin);
    scanf("%1c", &temp);

    temp = tolower(temp);



  } while (invalid);

  if (useTime) {

  }

  return date;
}

#endif // DATE_H_INCLUDED