#include "..\include\Student.h"

Student::Student() {
  id = -1;
  fio = "";
  group = nullptr;
}

Student::Student(int id, std::string fio) {
  this->id = id;
  this->fio = fio;
  this->group = nullptr;
}

Student::Student(const Student& other) {
  this->id = other.id;
  this->fio = other.fio;
  this->group = other.group;

  this->marks.resize(other.marks.size());
  for (int i = 0; i < other.marks.size(); i++) {
    this->marks[i] = other.marks[i];
  }
}

Student::Student(Student&& other) {
  this->id = other.id;
  this->fio = other.fio;
  this->group = other.group;

  this->marks = std::move(other.marks);
  other.group = nullptr;
}

std::string Student::getFio() const{
  return fio;
}

int Student::getID() const {
  return id;
}

Group* Student::getGroup() const {
  return group;
}

std::vector<int> Student::getMarks() const {
  return marks;
}

void Student::addMark(int mark) {
  if (0 <= mark && mark <= 10)
  {
    marks.push_back(mark);
  } else {
    throw "Invalid mark";
  }
}

double Student::getAverageMark() const {
  double res = 0;
  for (auto mark: marks) {
    res += mark;
  }
  return res / marks.size();
}

void Student::addToGroup(Group* group) {
  this->group = group;
}