#include "func.h"

using namespace std;

String::String() : length(0), data(new char[1]) { data[0] = '\0'; }

String::String(const char* newString) {
  if (newString == nullptr) {
    data = new char[1];
    data[0] = '\0';
    length = 0;

  } else {
    length = 0;
    while (newString[length] != '\0') {
      length++;
    }
    data = new char[length + 1];
    for (size_t i = 0; i <= length; i++) {
      data[i] = newString[i];
    }
  }
}

String::String(const String& other) : length(other.length) {
  data = new char[length + 1];
  for (size_t i = 0; i <= length; i++) {
    data[i] = other.data[i];
  }
}

String::~String() { delete[] data; }

String& String::operator=(const String& other) {
  if (this != &other) {
    length = other.length;
    delete[] data;
    data = new char[length + 1];
    for (int i = 0; i <= length; i++) {
      data[i] = other.data[i];
    }
  }
  return *this;
}

String& String::operator++() {
  if (data != nullptr) {
    for (int i = 0; i < length; i++) {
      if (isalpha(data[i])) {
        char base = islower(data[i]) ? 'a' : 'A';
        data[i] = (data[i] - base + 1) % 26 + base;
      }
    }
  }
  return *this;
}

String& String::operator--() {
  if (data != nullptr) {
    for (int i = 0; i < length; i++) {
      if (isalpha(data[i])) {
        char base = islower(data[i]) ? 'a' : 'A';
        data[i] = (data[i] - base - 1 + 26) % 26 + base;
      }
    }
  }
  return *this;
}

void printString(const String& str, ostream& outputStream) {
    outputStream << str.data << endl;
}

void inputString(String& str, istream& inputStream) {
  char buffer[1024];

  cout << "Enter the string:";

  inputStream.getline(buffer, 1024);

  delete[] str.data;

  str.length = 0;
  while (buffer[str.length] != '\0') {
    str.length++;
  }

  str.data = new char[str.length + 1];

  for (int i = 0; i < str.length; i++) {
    str.data[i] = buffer[i];
  }
  str.data[str.length] = '\0';
}
