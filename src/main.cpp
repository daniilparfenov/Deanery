#include <Windows.h>

#include <iostream>

#include "Deanery.h"

void printMenu() {
  std::cout << "============================ Deanery Project "
               "============================"
            << std::endl;
  std::cout << "======================= Created by Daniil Parfenov "
               "======================"
            << std::endl;
  std::cout << "\t1. Load data from file" << std::endl;
  std::cout << "\t2. Save data to file" << std::endl;
  std::cout << "\t3. Print data" << std::endl;
  std::cout << "\t4. Print statistics" << std::endl;
  std::cout << "\t5. Add random marks to all students" << std::endl;
  std::cout << "\t6. Replace all marks with other random marks for all students"
            << std::endl;
  std::cout << "\t7. Move student to other group" << std::endl;
  std::cout << "\t8. Fire all students with average mark < 4" << std::endl;
  std::cout << "\t9. Exit" << std::endl;
  std::cout << "Your choice: ";
}

int main() {
  // converting console encoding to UTF-8
  std::system("chcp 65001");

  Deanery deanery;

  bool isTimeToExit = false;
  bool isDataSaved = false;
  bool isDataLoaded = false;
  int choice = -1;
  char choiceForExit = ' ';
  std::string identificatorOfStudent = "", titleOfOtherGroup = "";
  int numberOfMarks = 0;

  while (!isTimeToExit) {
    printMenu();
    std::cin >> choice;
    switch (choice) {
      case 1:
        std::cout << "Data loading..." << std::endl;
        deanery.loadData();
        std::cout << "Data loaded successfully!" << std::endl;
        isDataLoaded = true;
        break;
      case 2:
        std::cout << "Data saving..." << std::endl;
        deanery.saveData();
        std::cout << "Data saved successfully!" << std::endl;
        isDataSaved = true;
        break;
      case 3:
        if (isDataLoaded) {
          deanery.printData();
        } else {
          std::cout << "There are no groups. Try to load the data" << std::endl;
        }
        break;
      case 4:
        if (isDataLoaded) {
          deanery.printStatistics();
        } else {
          std::cout << "There are no groups. Try to load the data" << std::endl;
        }
        break;
      case 5:
        numberOfMarks = 0;
        std::cout << "Number of marks: ";
        std::cin >> numberOfMarks;
        deanery.addRandomMarksForStudents(numberOfMarks);
        break;
      case 6:
        numberOfMarks = 0;
        std::cout << "Number of marks: ";
        std::cin >> numberOfMarks;
        deanery.replaceAllMarksWithRandom(numberOfMarks);
        break;
      case 7:
        identificatorOfStudent = "";
        titleOfOtherGroup = "";

        std::cout << "Enter fio or ID of student: ";
        std::cin >> identificatorOfStudent;
        std::cout << "Enter title of the new group: ";
        std::cin >> titleOfOtherGroup;

        if (std::isdigit(identificatorOfStudent[0])) {
          deanery.transferStudentToOtherGroup(std::stoi(identificatorOfStudent),
                                              titleOfOtherGroup);
        } else {
          deanery.transferStudentToOtherGroup(identificatorOfStudent,
                                              titleOfOtherGroup);
        }
        break;
      case 8:
        deanery.fireStudents();
        break;
      case 9:
        if (!isDataSaved) {
          std::cout
              << "Are you sure you want to exit without saving yout data? (Y/N)"
              << std::endl;
          std::cin >> choiceForExit;
          if (choiceForExit == 'Y') {
            isTimeToExit = true;
          }
        } else {
          isTimeToExit = true;
        }
        break;
      default:
        std::cout << "Invalid choice" << std::endl;
        break;
    }
  }

  return 0;
}