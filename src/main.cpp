#include <iostream>
#include "Student.h"

int main() {
 
  Student he(12, "ASdas");
  // Student me(std::move(he));
  // std::cout << me.getID() << std::endl;
  // std::cout << me.getFio() << std::endl;

  he.addMark(5);
  

  
 std::cout << he.getAverageMark() << std::endl;
  return 0;
}