#include "..\include\Group.h"

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
  if (student.getGroup() != this) {
    students.push_back(&student);
    student.group = this;
  }
}

Student* Group::chooseHead() {
  head = students[0];
  for (int i = 1; i < students.size(); i++) {
    if (students[i]->getAverageMark() > head->getAverageMark()) {
      head = students[i];
    }
  }
  head->setAsHead();
  return head;
}

Student* Group::findStudent(const int ID) {
  for (int i = 0; i < students.size(); i++) {
    if (students[i]->getID() == ID) {
      return students[i];
    }
  }
  return nullptr;
}

Student* Group::findStudent(const std::string& fio) {
  for (int i = 0; i < students.size(); i++) {
    if (students[i]->getFio() == fio) {
      return students[i];
    }
  }
  return nullptr;
}

double Group::getAverageMarkOfStudents() {
  double res;
  for (int i = 0; i < students.size(); i++) {
    res += students[i]->getAverageMark();
  }
  return res / students.size();
}

void Group::expelStudent(Student& student) {
  if (student.getGroup() == this) {
    for (int i = 0; i < this->students.size(); i++) {
      if (this->students[i]->getID() == student.id) {
        this->students.erase(students.begin() + i);
        break;
      }
    }
    student.group = nullptr;
    if (student.isHead) {
      student.isHead = false;
      this->head = nullptr;
    }
  }
}

void Group::setTitle(std::string newTitle) { this->title = newTitle; }

void Group::setSpec(std::string newSpec) { this->spec = newSpec; }

void Group::setHead(Student* newHead) {
  if (this->head != newHead) {
    if (this->head != nullptr) {
      this->head->isHead = false;
    }
    this->head = newHead;
    this->head->isHead = true;
  }
}

std::string Group::getTitle() const { return title; }

Student* Group::getHead() const { return head; }

std::string Group::getSpec() const { return spec; }

std::vector<Student*> Group::getStudents() const { return students; }