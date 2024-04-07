// Copyright 2024 by Parfenov Daniil
#pragma once
#ifndef GROUP_H
#define GROUP_H

#include <string>
#include <vector>

#include "Student.h"
class Student;

class Group {
 private:
  std::string title;
  std::string spec;
  std::vector<Student*> students;
  Student* head;

 public:
  Group();
  Group(const std::string& title, const std::string& spec);
  Group(const Group& other);
  Group(Group&& other);
  ~Group();

  void addStudent(Student* student);
  Student* chooseHead();
  Student* findStudent(const int ID);
  Student* findStudent(const std::string& fio);
  double getAverageMarkOfStudents();
  void expelStudent(Student* student);

  void setTitle(std::string newTitle);
  void setSpec(std::string newSpec);
  void setHead(Student* newHead);

  std::string getTitle() const;
  Student* getHead() const;
  std::string getSpec() const;
  std::vector<Student*> getStudents() const;
};

#endif  // GROUP_H
