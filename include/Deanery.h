#pragma once
#ifndef DEANERY_H
#define DEANERY_H

#include <vector>

#include "Group.h"
#include "Student.h"


class Deanery {
 private:
  std::vector<Group*> groups;
 public:
  void loadStudentsData();
  void loadGroupsData();
  void addRandomMarksForStudents();
  void printStatistics();
  void transferStudentToOtherGroup(Student& student, Group& otherGroup);
  void fireStudents();
  void saveData();
  void printData();
};

#endif // DEANERY_H