#ifndef FUNC_H
#define FUNC_H

#include <cctype>
#include <iostream>

class String {
 private:
  char* data;
  size_t length;

 public:
  String(const String& other);
  String();
  String(const char* newString);

  String& operator++();
  String& operator--();
  String& operator=(const String& other);

  ~String();

  friend void printString(const String& str, std::ostream& outputStream);
  friend void inputString(String& str, std::istream& inputStream);
};

#endif
