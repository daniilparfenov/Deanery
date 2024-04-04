#include <fstream>
#include <random>
#include <string>

int main() {
  setlocale(LC_ALL, "Russian");
  std::ifstream fileForInit("init.txt");
  std::ofstream outputFile;

  outputFile.open("../students.txt");
  std::string line;
  int id = 0;
  int groupNumber = 4;

  while (std::getline(fileForInit, line)) {
    outputFile << id << ' ' << line << " 23КНТ-" << groupNumber << ' ';
    for (int i = 0; i < 10; i++) {
      outputFile << rand() % 11 << ' ';
    }
    id++; 
    if ((id%29==0) && id != 0) {
      groupNumber++;
    }
    outputFile << std::endl;
  }
  outputFile.close();
  fileForInit.close();
  return 0;
}