#pragma once
#ifndef DEANERY_H
#define DEANERY_H

#include <vector>

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
  void addGroup(Group* newGroup);
  void loadData();
  void addRandomMarksForStudents(int numberOfMarks);
  void printStatistics() const;
  void transferStudentToOtherGroup(Student& student, Group& otherGroup);
  void fireStudents();
  void saveData() const;
  void printData() const;
};

#endif // DEANERY_H