#include "func.h"

int main() {
  MyString emptyStr;
  emptyStr.printStr();

  MyString original("Test constructor");
  MyString copy = original;
  copy.printStr();

  MyString str3("hello");
  MyString str4("hello");
  str3.intersection(str4).printStr();

  MyString str1("abc");
  MyString str2("xyz");
  str1.intersection(str2).printStr();

  MyString empty1, empty2;
  empty1.intersection(empty2).printStr();

  MyString newStr("Hello World");

  newStr.printStr();

  newStr.inputStr();

  newStr.printStr();

  MyString toIntersection("Apple and worms");
  MyString intersectionResult = newStr.intersection(toIntersection);

  intersectionResult.printStr();

  return 0;
}
