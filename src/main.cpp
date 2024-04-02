#include <iostream>
#include "Student.h"
#include "Deanery.h"

int main() {
 
  Student me(12, "SA");
  Student he(22, "asas");
  Group CST5("CST5", "IMIKN");
  CST5.addStudent(he);
  CST5.addStudent(me);
  me.addToGroup(&CST5);
  CST5.expelStudent(me);
  CST5.expelStudent(he);
  Student* head = CST5.chooseHead();
  if (CST5.findStudent("SA") != nullptr)
  {
    std::cout << CST5.findStudent("SA")->getFio() << std::endl;
  }
  // std::cout << CST5.findStudent(22)->getFio() << std::endl;
  return 0;
}