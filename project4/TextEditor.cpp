#include "TextEditor.h"

#include <fstream>
#include <iostream>
#include <limits>

using namespace std;

TextEditor::TextEditor() {
  text = "";
  currentFile = "";
}

void TextEditor::clearInputState() {
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int TextEditor::readInt(const string &prompt) {
  int value;
  while (true) {
    cout << prompt;
    if (cin >> value) {
      clearInputState();
      return value;
    }
    cout << "Invalid input. Please enter a number." << endl;
    clearInputState();
  }
}

string TextEditor::readLine(const string &prompt) {
  cout << prompt;
  string line;
  getline(cin, line);
  return line;
}

void TextEditor::openFile() {
  const string fileName = readLine("Enter file path to open: ");
  if (fileName.empty()) {
    cout << "File path cannot be empty." << endl;
    return;
  }

  ifstream input(fileName);
  if (!input.is_open()) {
    cout << "Error: file not found or cannot be opened." << endl;
    return;
  }

  string contents = "";
  string line;
  while (getline(input, line)) {
    contents += line;
    if (!input.eof()) {
      contents += '\n';
    }
  }

  text = contents;
  currentFile = fileName;
  cout << "File loaded successfully." << endl;
}

void TextEditor::saveFile() {
  string fileName =
      readLine("Enter file path to save (leave empty to use current file): ");
  if (fileName.empty()) {
    fileName = currentFile;
  }

  if (fileName.empty()) {
    cout << "No file path available. Please enter a file name." << endl;
    return;
  }

  ifstream existing(fileName);
  if (existing.good()) {
    string confirm = readLine("File already exists. Overwrite? (y/n): ");
    if (confirm != "y" && confirm != "Y") {
      cout << "Save canceled." << endl;
      return;
    }
  }

  ofstream output(fileName);
  if (!output.is_open()) {
    cout << "Error: cannot open file for writing." << endl;
    return;
  }

  output << text;
  if (!output.good()) {
    cout << "Error: failed while writing to file." << endl;
    return;
  }

  currentFile = fileName;
  cout << "File saved successfully." << endl;
}

void TextEditor::appendText() {
  cout << "Enter text to append (single line): ";
  string newText;
  getline(cin, newText);
  if (!text.empty()) {
    text += '\n';
  }
  text += newText;
  cout << "Text appended." << endl;
}

void TextEditor::deleteTextRange() {
  if (text.empty()) {
    cout << "Text is empty." << endl;
    return;
  }

  const int start = readInt("Enter start index (0-based): ");
  const int len = readInt("Enter number of characters to delete: ");

  if (start < 0 || len < 0 || start > (int)text.size()) {
    cout << "Invalid range." << endl;
    return;
  }

  text.erase(start, len);
  cout << "Text deleted." << endl;
}

void TextEditor::modifyTextRange() {
  if (text.empty()) {
    cout << "Text is empty." << endl;
    return;
  }

  const int start = readInt("Enter start index (0-based): ");
  const int len = readInt("Enter number of characters to replace: ");
  if (start < 0 || len < 0 || start > (int)text.size()) {
    cout << "Invalid range." << endl;
    return;
  }

  const string replacement = readLine("Enter replacement text: ");
  text.replace(start, len, replacement);
  cout << "Text modified." << endl;
}

void TextEditor::editText() {
  cout << endl << "--- Edit Menu ---" << endl;
  cout << "1. Append text" << endl;
  cout << "2. Delete text range" << endl;
  cout << "3. Modify text range" << endl;
  cout << "4. Replace entire text" << endl;
  cout << "5. Back" << endl;

  const int choice = readInt("Choose edit option: ");
  switch (choice) {
  case 1:
    appendText();
    break;
  case 2:
    deleteTextRange();
    break;
  case 3:
    modifyTextRange();
    break;
  case 4:
    text = readLine("Enter new full text (single line): ");
    cout << "Text replaced." << endl;
    break;
  case 5:
    break;
  default:
    cout << "Invalid option." << endl;
    break;
  }
}

void TextEditor::searchText() {
  const string target = readLine("Enter text to search for: ");
  if (target.empty()) {
    cout << "Search text cannot be empty." << endl;
    return;
  }

  size_t pos = text.find(target);
  if (pos == string::npos) {
    cout << "Text not found." << endl;
    return;
  }

  cout << "Found at indices: ";
  bool first = true;
  while (pos != string::npos) {
    if (!first) {
      cout << ", ";
    }
    cout << pos;
    first = false;
    pos = text.find(target, pos + 1);
  }
  cout << endl;
}

void TextEditor::replaceText() {
  const string from = readLine("Enter text to replace: ");
  if (from.empty()) {
    cout << "Target text cannot be empty." << endl;
    return;
  }

  const string to = readLine("Enter replacement text: ");
  size_t pos = 0;
  int replacements = 0;

  while ((pos = text.find(from, pos)) != string::npos) {
    text.replace(pos, from.length(), to);
    pos += to.length();
    ++replacements;
  }

  cout << "Replaced " << replacements << " occurrence(s)." << endl;
}

void TextEditor::showText() {
  cout << endl << "--- Current Text ---" << endl;
  if (text.empty()) {
    cout << "(empty)" << endl;
  } else {
    cout << text << endl;
  }
}

string TextEditor::getCurrentFile() { return currentFile; }
