#ifndef FUNC_H
#define FUNC_H

#include <cctype>
#include <iostream>

class String {
 private:
  size_t length;
  char* data;

 public:
  String(const String& other);
  String();
  explicit String(const char* newString);

  String& operator++();
  String& operator--();
  String& operator=(const String& other);

  ~String();

  friend std::ostream& operator<<(std::ostream& os, const String& str) {
    os << str.data << std::endl;
    return os;
  }

  friend std::istream& operator>>(std::istream& is, String& str) {
    std::cout << "Enter the string:" << std::endl;

    delete[] str.data;

    size_t capacity = 1;
    str.length = 0;
    str.data = new char[1];
    str.data[str.length] = '\0';

    char symbol;
    while (is.get(symbol) && symbol != '\n') {
      if (str.length <= capacity - 1) {
        capacity = str.length + 2;
        auto* newStr = new char[capacity];
        for (size_t i = 0; i < str.length; i++) {
          newStr[i] = str.data[i];
        }

        delete[] str.data;
        str.data = newStr;
      }

      str.data[str.length++] = symbol;
    }
    str.data[str.length] = '\0';

    return is;
  }
};

#endif
