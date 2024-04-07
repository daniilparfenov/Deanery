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
    outputFile << id << ' ' << line << " 23KNT-" << groupNumber << ' ';
    for (int i = 0; i < 10; i++) {
      outputFile << rand() % 11 << ' ';
    }
    id++;
    if ((id % 29 == 0) && id != 0) {
      groupNumber++;
    }
    outputFile << std::endl;
  }
  outputFile.close();
  fileForInit.close();

  outputFile.open("../groups.txt");
  std::string HEADS[6] = {
    "Zaharchenko Yana Aleksandrovna",
    "Majorova Mariya Vadimovna",
    "Miheeva Alina Andreevna",
    "Makshaeva Melanya Aleksandrovna", 
    "Batyaev Egor Konstantinovich",
    "Cirulev Dmitrij Aleksandrovich"
  };
  for (int i = 3; i < 9; i++)
  {
    outputFile << ("23KNT-" + std::to_string(i+1)) << " IMIKN " << HEADS[i-3] << std::endl;
  }
  outputFile.close();
  return 0;
}