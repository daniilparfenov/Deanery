#include "Group.h"

Group::Group() {
  title = "";
  spec = "";
  head = nullptr;
}

Group::Group(const std::string& title, const std::string& spec) {
  this->title = title;
  this->spec = spec;
  this->head = nullptr;
}

Group::Group(Group& other) {
  title = other.title;
  spec = other.spec;
  students = other.students;
  head = other.head;
}

Group::Group(Group&& other) {
  title = std::move(other.title);
  spec = std::move(other.spec);
  students = std::move(other.students);
  head = other.head;

  other.head = nullptr;
  other.title = "";
  other.spec = "";
}

void Group::addStudent(Student& student) {
  if (student.getGroup() != this)
  {
    students.push_back(&student);
    student.addToGroup(this);
  }
}