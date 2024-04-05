#include "..\include\Student.h"

Student::Student() {
  id = -1;
  fio = "";
  group = nullptr;
  this->isHead = false;
}

Student::Student(int id, std::string fio) {
  this->id = id;
  this->fio = fio;
  this->group = nullptr;
  this->isHead = false;
}

Student::Student(const Student& other) {
  this->id = other.id;
  this->fio = other.fio;
  this->group = other.group;
  this->isHead = other.isHead;

  this->marks.resize(other.marks.size());
  for (int i = 0; i < other.marks.size(); i++) {
    this->marks[i] = other.marks[i];
  }
}

Student::Student(Student&& other) {
  this->id = other.id;
  this->fio = std::move(other.fio);
  this->group = other.group;
  this->isHead = other.isHead;

  this->marks = std::move(other.marks);
  other.group = nullptr;
}

// Student::~Student() {
//   id = -1;
//   group = nullptr;
// }

std::string Student::getFio() const { return fio; }

int Student::getID() const { return id; }

Group* Student::getGroup() const { return group; }

std::vector<int> Student::getMarks() const { return marks; }

void Student::addMark(int mark) {
  if (0 <= mark && mark <= 10) {
    marks.push_back(mark);
  } else {
    throw "Invalid mark";
  }
}

double Student::getAverageMark() const {
  double res = 0;
  for (auto mark : marks) {
    res += mark;
  }
  return res / marks.size();
}

void Student::addToGroup(Group* group) {
  if (this->group != group) {
    group->addStudent(*this);
  }
}

bool Student::isHeadOfGroup() const { return isHead; }

void Student::setAsHead() {
  group->setHead(this);
  this->isHead = true;
}

void Student::setFio(std::string newFio) { this->fio = newFio; }
void Student::setID(int newID) { this->id = newID; }

void Student::deleteAllMarks() { this->marks.clear(); }