#include"func.h"

MyString::MyString() :length(0), str(nullptr) {
	str = new char[1];
	str[0] = '\0';
}

MyString::~MyString() {
	delete[] str;
}

MyString::MyString(const char* newString) {
	if (newString == nullptr) {
		str = new char[1];
		str[0] = '\0';
		length = 0;
	}
	else {
		length = strlen(newString);
		str = new char[length + 1];
		strcpy_s(str,length + 1, newString);
	}
}

MyString::MyString(const MyString& other):length(other.length) {
	str = new char[length + 1];
	strcpy_s(str,length + 1, other.str);
}

void MyString::printStr() {
	cout << str << endl;
}