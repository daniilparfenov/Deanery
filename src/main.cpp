#include <Windows.h>

#include <cstdlib>
#include <iostream>

#include "Deanery.h"
#include "Student.h"

int main() {
  std::system("chcp 65001");

  Deanery deanery;
  deanery.loadData();
  std::cout << "OK" << std::endl;
  deanery.printData();
  deanery.saveData();
  
  return 0;
}