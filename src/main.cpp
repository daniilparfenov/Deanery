#include <iostream>
#include "Student.h"
#include "Deanery.h"
#include <cstdlib>  
#include <Windows.h>

int main() {
  setlocale(LC_ALL, "");
  std::system("chcp 1251");
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  Deanery deanery;
  deanery.loadData();
  std::cout << "OK" << std::endl;
  deanery.printData();
  return 0;
}