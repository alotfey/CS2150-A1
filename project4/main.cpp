/**
 * @file main.cpp
 * @brief Entry point for a menu-driven text editor program.
 *
 * @details
 * This program creates a simple console-based text editor using `TextEditor`
 * and `Menu` classes. It displays a menu in a loop and allows the user to open,
 * save, edit, search, replace, and display text content from a file. The program
 * continues running until the user selects the exit option. This program
 * demonstrates class interaction, menu-driven control flow, user input handling,
 * and basic file/text operations in C++.
 *
 * @author Ahmed Lotfey
 * @class CS2150-A1 C++ Programming
 * @professor Dr. Richard Lesh
 * @department Computer Science, Baker College
 * @date 03/08/2026
 * @version 1.0
 *
 * @input
 * - User menu selections (integer values)
 * - File names and text content entered through menu operations
 *
 * @output
 * - Menu display and prompts
 * - Operation status messages and text display output
 *
 * @note
 * This program assumes valid numeric input for menu choices and does not include
 * advanced validation for non-numeric input values.
 */

#include "Menu.h"
#include "TextEditor.h"
#include <iostream>

using namespace std;

int main() {
  TextEditor editor;
  Menu menu;
  bool running = true;

  while (running) {
    menu.showMenu(editor.getCurrentFile());
    int choice = menu.getMenuChoice();

    switch (choice) {
    case 1:
      editor.openFile();
      break;
    case 2:
      editor.saveFile();
      break;
    case 3:
      editor.editText();
      break;
    case 4:
      editor.searchText();
      break;
    case 5:
      editor.replaceText();
      break;
    case 6:
      editor.showText();
      break;
    case 7:
      cout << "Goodbye." << endl;
      running = false;
      break;
    default:
      cout << "Invalid option. Please select correct option." << endl;
      break;
    }
  }

  return 0;
}
