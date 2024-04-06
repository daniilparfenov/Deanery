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
    if ((id % 29 == 0) && id != 0) {
      groupNumber++;
    }
    outputFile << std::endl;
  }
  outputFile.close();
  fileForInit.close();

  outputFile.open("../groups.txt");
  std::string HEADS[6] = {
    "Захарченко Яна Александровна",
    "Майорова Мария Вадимовна",
    "Михеева Алина Андреевна",
    "Макшаева Меланья Александровна", 
    "Батяев Егор Константинович",
    "Цирулев Дмитрий Александрович"
  };
  for (int i = 3; i < 9; i++)
  {
    outputFile << ("23КНТ-" + std::to_string(i+1)) << " ИМИКН " << HEADS[i-3] << std::endl;
  }
  outputFile.close();
  return 0;
}