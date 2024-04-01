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
  Group(std::string title);
  void addStudent(Student& student);
  void chooseHead();
  Student* findStudent(int ID);
  Student* findStudent(std::string fio);
  double getAverageMark();
  void expelStudent(Student& student);
};

#endif // GROUP_H