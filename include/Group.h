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
  Group(Group& other);
  Group(Group&& other);
  
  void addStudent(Student& student);
  Student* chooseHead();
  Student* findStudent(const int ID);
  Student* findStudent(const std::string& fio);
  double getAverageMarkOfStudents();
  void expelStudent(Student& student);
};

#endif  // GROUP_H