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

#endif  // DEANERY_H