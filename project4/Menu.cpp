#include "Menu.h"

#include <iostream>
#include <limits>

using namespace std;

void Menu::clearInputState() {
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Menu::showMenu(string currentFile) {
  cout << endl << "===== Basic Text Editor =====" << endl;
  if (currentFile == "") {
    cout << "Current file: (none)" << endl;
  } else {
    cout << "Current file: " << currentFile << endl;
  }
  cout << "1. Open a text file" << endl;
  cout << "2. Save a text file" << endl;
  cout << "3. Edit text" << endl;
  cout << "4. Search for text" << endl;
  cout << "5. Replace text" << endl;
  cout << "6. Show current text" << endl;
  cout << "7. Quit" << endl;
}

int Menu::getMenuChoice() {
  int value;
  while (true) {
    cout << "Choose an option: ";
    if (cin >> value) {
      clearInputState();
      return value;
    }
    cout << "Invalid input. Please enter a number." << endl;
    clearInputState();
  }
}
