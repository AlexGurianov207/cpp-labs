#include "mystring.h"

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

istream& operator>>(istream& is, String& str) {
    string buffer;
    getline(is, buffer);

    delete[] str.data;
    str.length = buffer.length();
    str.data = new char[str.length + 1];
    memcpy(str.data, buffer.data(), str.length);
    str.data[str.length] = '\0';

    return is;
}

ostream& operator<<(ostream& os, const String& str) {
    os << str.data << endl;
    return os;
}