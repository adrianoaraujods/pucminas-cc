#include <iostream>

#define _MAX 100

using namespace std;

class Candidate {
private:
  string name;
  double grade;

public:
  bool setName(string name) {
    this->name = name;

    return true;
  }

  bool setGrade(double grade) {
    this->grade = grade;

    return true;
  }

  string getName() {
    return this->name;
  }

  double getGrade() {
    return this->grade;
  }

  Candidate(string name, double grade) {
    setName(name);
    setGrade(grade);
  }
};

int readCandidatesCount() {
  int count;

  cin >> count; // skip line number
  cin >> count;

  return count;
}

Candidate* readCandidate() {
  string name;
  double grade;

  cin >> name; // skip line number
  cin >> name;
  cin >> grade;

  Candidate* candidate = new Candidate(name, grade);

  return candidate;
}

float gradesAverage(Candidate* candidates[_MAX], int candidatesCount) {
  int sum = 0;

  for (int i = 0; i < candidatesCount; i++) {
    sum += candidates[i]->getGrade();
  }

  return (float)sum / candidatesCount;
}

void printCandidatesAboveAverage(
  Candidate* candidates[_MAX], int candidatesCount, float average
) {
  int count = 0;

  for (int i = 0; i < candidatesCount; i++) {
    if (candidates[i]->getGrade() > average) {
      count++;

      cout << count; // number of the line
      cout << " ";
      cout << candidates[i]->getName();
      cout << " ";
      cout << candidates[i]->getGrade();
      cout << endl;
    }
  }

  cout << count + 1; // print empty line with number of the line
}

int main() {
  Candidate* candidates[_MAX];

  int candidatesCount = readCandidatesCount();

  for (int i = 0; i < candidatesCount; i++) {
    candidates[i] = readCandidate();
  }

  float average = gradesAverage(candidates, candidatesCount);

  printCandidatesAboveAverage(candidates, candidatesCount, average);

  for (int i = 0; i < candidatesCount; i++) {
    delete candidates[i];
  }

  return 0;
}
