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

Student::Student(Student&& other): id(id), fio(fio), group(group) {
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