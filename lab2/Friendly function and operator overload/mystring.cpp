#include "mystring.h"

using namespace std;

String::String() : length(0), data(new char[1]), isEncoded(false) {
  data[0] = '\0';
}

String::String(const char* newString) : isEncoded(false) {
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

String::String(const String& other) : length(other.length), isEncoded(other.isEncoded) {
  data = new char[length + 1];
  for (size_t i = 0; i <= length; i++) {
    data[i] = other.data[i];
  }
}

String::~String() { delete[] data; }

String& String::operator=(const String& other) {
  if (this != &other) {
    length = other.length;
    isEncoded = other.isEncoded;
    delete[] data;
    data = new char[length + 1];
    for (size_t i = 0; i <= length; i++) {
      data[i] = other.data[i];
    }
  }
  return *this;
}

String& String::operator++() {
  if (!isEncoded) {
    for (size_t i = 0; i < length; i++) {
      if (isalpha(data[i])) {
        char base = islower(data[i]) ? 'a' : 'A';
        data[i] = (data[i] - base + SHIFT) % ALPHABET_SIZE + base;
      }
    }
    isEncoded = true;
  }
  return *this;
}

String& String::operator--() {
  if (isEncoded) {
    for (size_t i = 0; i < length; i++) {
      if (isalpha(data[i])) {
        char base = islower(data[i]) ? 'a' : 'A';
        data[i] =
            (data[i] - base - SHIFT + ALPHABET_SIZE) % ALPHABET_SIZE + base;
      }
    }
    isEncoded = false;
  }
  return *this;
}

void testInput(String& myString) {
  cout << "Enter the string:";
  cin >> myString;
}

void testCoding(String& myString) {
  ++myString;
  cout << myString << endl;
}

void testDecoding(String& myString) {
  --myString;
  cout << myString << endl;
}
