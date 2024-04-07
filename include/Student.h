// Copyright 2024 by Parfenov Daniil#pragma once
#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_

#include <string>
#include <vector>

#include "Group.h"
class Group;

class Student {
  friend class Group;

 private:
  int id;
  std::string fio;
  Group* group;
  std::vector<int> marks;
  bool isHead;

 public:
  Student();
  Student(int id, std::string fio);
  Student(const Student& other);
  Student(Student&& other);
  // ~Student();

  void addToGroup(Group* group);
  void addMark(int mark);
  double getAverageMark() const;
  void setAsHead();

  std::string getFio() const;
  int getID() const;
  Group* getGroup() const;
  std::vector<int> getMarks() const;
  bool isHeadOfGroup() const;

  void setFio(std::string newFio);
  void setID(int newID);
  void deleteAllMarks();
};

#endif  // INCLUDE_STUDENT_H_
