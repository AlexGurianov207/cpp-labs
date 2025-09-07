#ifndef FUNC
#define FUNC

#include<iostream>
#include<cstring>

using namespace std;

class MyString {
private:
	size_t length;
	char* str;
public:
	MyString();
	MyString(const char* newString);
	MyString(const MyString& other);

	void printStr();
	void inputStr();
	MyString intersection(const MyString& other);


	~MyString();
};

#endif
