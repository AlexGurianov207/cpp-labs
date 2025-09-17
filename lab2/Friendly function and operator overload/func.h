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

  friend void printString(const String& str);
  friend void inputString(String& str);
};

#endif
