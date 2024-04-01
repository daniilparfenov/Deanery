#include <iostream>
#include "Student.h"
#include "Deanery.h"

int main() {
 
  Student me(12, "SA");
  Group CST5("CST5", "IMIKN");
  CST5.addStudent(me);
  me.addToGroup(&CST5);
  return 0;
}