#ifndef MYSTRING_H
#define MYSTRING_H

#include <cctype>
#include <iostream>
#include <string>

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

  friend std::ostream& operator<<(std::ostream& os, const String& str);

  friend std::istream& operator>>(std::istream& is, String& str);
};

#endif
