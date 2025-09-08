#include "func.h"

using namespace std;

MyString::MyString() : length(0), str(new char[1]) { str[0] = '\0'; }

MyString::~MyString() { delete[] str; }

MyString::MyString(const char *newString) {
  if (newString == nullptr) {
    str = new char[1];
    str[0] = '\0';
    length = 0;

  } else {
    length = strlen(newString);
    str = new char[length + 1];
    strcpy_s(str, length + 1, newString);
  }
}

MyString::MyString(const MyString &other) : length(other.length) {
  str = new char[length + 1];
  strcpy_s(str, length + 1, other.str);
}

void MyString::printStr() const { cout << str << endl; }

void MyString::inputStr() {
  cout << "Enter the string:" << endl;

  delete[] str;

  size_t capacity = 1;
  length = 0;
  str = new char[1];
  str[length] = '\0';

  char symbol;
  while (cin.get(symbol) && symbol != '\n') {
    if (length <= capacity - 1) {
      capacity = length + 2;
      auto *newStr = new char[capacity];
      for (size_t i = 0; i < length; i++) {
        newStr[i] = str[i];
      }

      delete[] str;
      str = newStr;
    }

    str[length++] = symbol;
  }
  str[length] = '\0';
}

MyString MyString::intersection(const MyString &other) const {
  string result;

  for (int i = 0; i < length; i++) {
    char currentSymbol = str[i];

    bool foungInOther = false;
    for (int j = 0; j < other.length; j++) {
      if (currentSymbol == other.str[j]) {
        foungInOther = true;
        break;
      }
    }

    bool alreadyInResult = false;
    for (char c : result) {
      if (currentSymbol == c) {
        alreadyInResult = true;
        break;
      }
    }

    if (foungInOther && !alreadyInResult) {
      result += currentSymbol;
    }
  }

  return MyString(result.c_str());
}
