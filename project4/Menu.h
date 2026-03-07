#ifndef MENU_H
#define MENU_H

#include <string>

using namespace std;

class Menu {
private:
  void clearInputState();

public:
  void showMenu(string currentFile);
  int getMenuChoice();
};

#endif
