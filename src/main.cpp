#include <Windows.h>

#include <iostream>

#include "Deanery.h"

void printMenu() {
  std::cout << std::endl << std::endl;
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
  Deanery deanery;

  bool isTimeToExit = false;
  bool isDataSaved = false;
  bool isDataLoaded = false;
  int choice = -1;
  char answer = ' ';
  std::string identificatorOfStudent, titleOfOtherGroup;
  int numberOfMarks = 0;


  while (!isTimeToExit) {
    printMenu();
    std::cin >> choice;
    switch (choice) {
      case 1:
        if (!isDataLoaded) {
          std::cout << "Data loading..." << std::endl;
          deanery.loadData();
          std::cout << "Data loaded successfully!" << std::endl;
          isDataLoaded = true;
        } else {
          std::cout << "Data is already loaded!" << std::endl;
        }
        break;
      case 2:
        if (!isDataSaved) {
          if (isDataLoaded) {
            std::cout << "Data saving..." << std::endl;
            deanery.saveData();
            std::cout << "Data saved successfully!" << std::endl;
            isDataSaved = true;
          } else {
            answer = ' ';
            std::cout << "There is no loaded data. Are you sure you want to "
                         "save empty data? (Y/N)"
                      << std::endl;
            std::cin >> answer;
            if (answer == 'Y') {
              std::cout << "Data saving..." << std::endl;
              deanery.saveData();
              std::cout << "Data saved successfully!" << std::endl;
              isDataSaved = true;
            }
          }

        } else {
          std::cout << "Data is already saved!" << std::endl;
        }

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
        if (isDataLoaded) {
          numberOfMarks = 0;
          std::cout << "Number of marks: ";
          std::cin >> numberOfMarks;
          deanery.addRandomMarksForStudents(numberOfMarks);
          isDataSaved = false;
        } else {
          std::cout << "There are no groups. Try to load the data" << std::endl;
        }

        break;
      case 6:
        if (isDataLoaded) {
          numberOfMarks = 0;
          std::cout << "Number of marks: ";
          std::cin >> numberOfMarks;
          deanery.replaceAllMarksWithRandom(numberOfMarks);
          isDataSaved = false;
        } else {
          std::cout << "There are no groups. Try to load the data" << std::endl;
        }
        break;
      case 7:
        if (isDataLoaded) {
          identificatorOfStudent = "";
          titleOfOtherGroup = "";

          std::cout << "Enter fio or ID of student: ";
          std::cin.clear();
          std::cin.ignore(INT_MAX, '\n');
          std::getline(std::cin, identificatorOfStudent);
          std::cout << "Enter title of the new group: ";
          std::getline(std::cin, titleOfOtherGroup);

          if (std::isdigit(identificatorOfStudent[0])) {
            deanery.transferStudentToOtherGroup(
                std::stoi(identificatorOfStudent), titleOfOtherGroup);
          } else {
            deanery.transferStudentToOtherGroup(identificatorOfStudent,
                                                titleOfOtherGroup);
          }
          isDataSaved = false;
        } else {
          std::cout << "There are no groups. Try to load the data" << std::endl;
        }
        break;
      case 8:
        if (isDataLoaded) {
          deanery.fireStudents();
        } else {
          std::cout << "There are no groups. Try to load the data" << std::endl;
        }
        break;
      case 9:
        if (!isDataSaved) {
          std::cout
              << "Are you sure you want to exit without saving your data? (Y/N)"
              << std::endl;
          std::cin >> answer;
          if (answer == 'Y') {
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