#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <ctime>

const unsigned MONTH_DAYS[] = {
  31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

const std::string MONTH_NAMES[] = {
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

const std::string WEEK_NAMES[] = {
  "Sunday",
  "Monday",
  "Tuesday",
  "Wednesday",
  "Thursday",
  "Friday",
  "Saturday"
};

class Date {
private:
  int day, month, year;

public:
  static bool valid(int day, int month, int year);
  static bool leapYear(int year);
  static Date read();

  Date(int day, int month, int year);
  Date();

  int getDay();
  int getMonth();
  int getYear();
  std::string getDate();

  std::string getMonthName();
  std::string getWeekday();

  void print();
};

bool Date::leapYear(int year) {
  bool leap = false;

  if (
    (year % 400) == 0 ||
    (year % 4) == 0 &&
    (year % 100) == 0
    ) {
    leap = true;
  }

  return leap;
}

bool Date::valid(int day, int month, int year) {
  bool valid = true;

  bool leap = Date::leapYear(year);

  int daysInMonth = (month == 2 && leap) ? 29 : MONTH_DAYS[month - 1];

  if (
    month < 1 ||
    month > 12 ||
    day < 1 ||
    day > daysInMonth
    ) {
    valid = false;
  }

  return valid;
}

Date Date::read() {
  int day, month, year;
  bool invalid;

  do {
    try {

      std::cout << "Digite a data [dd/mm/yyyy]: ";
      scanf("%d/%d/%u", &day, &month, &year);

      invalid = Date::valid(day, month, year);
    } catch (...) {
      invalid = true;
    }

    if (invalid) std::cout << "\aData inválida!" << std::endl;
  } while (invalid);

  return Date(day, month, year);
}

Date::Date(int day, int month, int year) {
  if (Date::valid(day, month, year)) {
    this->day = day;
    this->month = month;
    this->year = year;
  } else {
    Date();
  }
}

Date::Date() {
  std::time_t today = std::time(nullptr);
  std::tm* local_time = std::localtime(&today);

  this->day = local_time->tm_mday;
  this->month = local_time->tm_mon + 1;
  this->year = local_time->tm_year + 1900;
}

int Date::getDay() {
  return this->day;
}

int Date::getMonth() {
  return this->month;
}

int Date::getYear() {
  return this->year;
}

std::string Date::getDate() {
  return std::to_string(this->day) +
    "/" + std::to_string(this->month) +
    "/" + std::to_string(this->year);
}

void Date::print() {
  std::cout << this->day << "/" << this->month << "/" << this->year << std::endl;
}

std::string Date::getMonthName() {
  return MONTH_NAMES[(int)(this->month) - 1];
}

std::string Date::getWeekday() {
  int m = this->month;
  int y = this->year;

  if (m < 3) {
    m += 12;
    y -= 1;
  }

  int k = y % 100;
  int j = y / 100;
  int dayOfWeek = ((int)(this->day) + (13 * (m + 1)) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;

  return WEEK_NAMES[dayOfWeek];
}

#endif // DATE_H
