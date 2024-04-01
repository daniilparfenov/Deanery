#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

#include "Group.h"
class Group;

class Student {
 private:
  int id;
  std::string fio;
  Group* group;
  std::vector<int> marks;

 public:
  Student();
  Student(int id, std::string fio);
  Student(const Student& other);
  Student(Student&& other);

  void addToGroup(Group* group);
  void addMark(int mark);
  double getAverageMark() const;

  std::string getFio() const;
  int getID() const;
  Group* getGroup() const;
  std::vector<int> getMarks() const;

};

#endif  // STUDENT_H