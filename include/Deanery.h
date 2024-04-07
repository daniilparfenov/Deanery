
// Copyright 2024 by Parfenov Daniil#pragma once
#ifndef INCLUDE_DEANERY_H_
#define INCLUDE_DEANERY_H_

#include <vector>
#include <string>

#include "Group.h"
#include "Student.h"

class Deanery {
 private:
  std::vector<Group*> groups;
  void loadStudentsData();
  void loadGroupsData();
  void saveStudentsData() const;
  void saveGroupsData() const;

 public:
  ~Deanery();
  void addGroup(Group* newGroup);
  void loadData();
  void addRandomMarksForStudents(int numberOfMarks);
  void replaceAllMarksWithRandom(int numberOfMarks);
  void printStatistics() const;
  void transferStudentToOtherGroup(int studentsID,
                                   std::string titleOfOtherGroup);
  void transferStudentToOtherGroup(std::string fioOfStudent,
                                   std::string titleOfOtherGroup);
  void fireStudents();
  void saveData() const;
  void printData() const;
};

#endif  // INCLUDE_DEANERY_H_
