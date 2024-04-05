#include "..\include\Deanery.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <ctime>

#include "..\include\Group.h"
#include "..\include\Student.h"

void Deanery::loadData() {
  loadGroupsData();
  loadStudentsData();
}

void Deanery::loadGroupsData() {
  std::string line = "";
  std::ifstream FILE("../data_base/groups.txt");

  if (!FILE.is_open()) {
    std::cout << "File \"groups.txt\" not found" << std::endl;
    return;
  }

  std::string title, spec, surNameOfHead, nameOfHead, midNameOfHead;
  std::string fioOfHead;
  while (std::getline(FILE, line)) {
    std::istringstream lineStream(line);
    lineStream >> title >> spec >> surNameOfHead >> nameOfHead >> midNameOfHead;

    Group* newGroup = new Group(title, spec);
    fioOfHead = surNameOfHead + ' ' + nameOfHead + ' ' + midNameOfHead;
    Student* head = new Student(-1, fioOfHead);

    this->addGroup(newGroup);
    head->addToGroup(newGroup);
    head->setAsHead();
  }

  FILE.close();
}

void Deanery::loadStudentsData() {
  std::string line = "";
  std::ifstream FILE("../data_base/students.txt");

  if (!FILE.is_open()) {
    std::cout << "File \"students.txt\" not found" << std::endl;
    return;
  }

  int id, mark;
  std::string name, surName, midName, groupName, fio;

  while (std::getline(FILE, line)) {
    std::istringstream lineStream(line);

    lineStream >> id >> surName >> name >> midName >> groupName;
    fio = surName + ' ' + name + ' ' + midName;
    Student* newStudent = new Student(id, fio);

    while (lineStream >> mark) {
      newStudent->addMark(mark);
    }

    for (int i = 0; i < groups.size(); i++) {
      if (groups[i]->getTitle() == groupName) {
        Student* head = groups[i]->getHead();
        if (head->getFio() == fio) {
          head->setID(id);
          for (int& mark : newStudent->getMarks()) {
            head->addMark(mark);
          }
        } else {
          groups[i]->addStudent(*newStudent);
        }
        break;
      }
    }
  }
  FILE.close();
}

void Deanery::addGroup(Group* newGroup) { this->groups.push_back(newGroup); }

void Deanery::printData() const {
  if (groups.size() == 0) {
    std::cout << "There are no groups. Try to load the data" << std::endl;
    return;
  }

  for (Group* group : groups) {
    std::cout << "Title: " << group->getTitle() << std::endl;
    std::cout << "Speciality: " << group->getSpec() << std::endl;
    std::cout << "Headman: " << group->getHead()->getFio() << std::endl;
    std::cout << "Students:" << std::endl;
    for (const Student* student : group->getStudents()) {
      std::cout << "FIO: " << student->getFio() << std::endl;
      std::cout << "ID: " << student->getID() << std::endl;
      std::cout << "Marks: ";
      for (const auto& mark : student->getMarks()) {
        std::cout << mark << ' ';
      }
      std::cout << std::endl;
    }
  }
}

void Deanery::saveData() const {
  saveStudentsData();
  saveGroupsData();
}

void Deanery::saveStudentsData() const {
  std::ofstream FILE("../data_base/students.txt");

  for (auto& group: groups)
  {
    for (auto& student: group->getStudents())
    {
      FILE << student->getID() << ' ' << student->getFio() << ' '
           << group->getTitle() << ' ';
      for (auto& mark: student->getMarks())
      {
        FILE << mark << ' ';
      }
      FILE << std::endl;
    }
  }
  FILE.close();
}

void Deanery::saveGroupsData() const {
  std::ofstream FILE("../data_base/groups.txt");

  for (auto& group: groups)
  {
    FILE << group->getTitle() << ' '
         << group->getSpec() << ' '
         << group->getHead()->getFio() << std::endl;
  }
 FILE.close(); 
}

// void Deanery::addRandomMarksForStudents(int numberOfMarks) {
//   std::srand(std::time(0));
// }