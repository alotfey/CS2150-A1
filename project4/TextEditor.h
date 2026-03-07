#ifndef TEXT_EDITOR_H
#define TEXT_EDITOR_H

#include <string>

using namespace std;

class TextEditor {
private:
  string text;
  string currentFile;

  void clearInputState();
  int readInt(const string &prompt);
  string readLine(const string &prompt);
  void appendText();
  void deleteTextRange();
  void modifyTextRange();

public:
  TextEditor();
  string getCurrentFile();
  void openFile();
  void saveFile();
  void editText();
  void searchText();
  void replaceText();
  void showText();
};

#endif
