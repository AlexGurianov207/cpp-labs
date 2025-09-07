#ifndef FUNC
#define FUNC

#include <cstring>
#include <iostream>
#include <string>

class MyString {
 private:
  size_t length;
  char* str;

 public:
  MyString();
  explicit MyString(const char* newString);
  MyString(const MyString& other);

  void printStr()const;
  void inputStr();
  MyString intersection(const MyString& other)const;

  ~MyString();
};

#endif
