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

void MyString::inputStr() {
	string buffer;
	cout << "Enter the string" << endl;
	getline(cin, buffer);

	delete[] str;
	length = buffer.length();
	str = new char[length + 1];
	copy(buffer.begin(), buffer.end(), str);
	str[length] = '\0';
}

MyString MyString::intersection(const MyString& other) {
	char result[256];
	int resultIndex = 0;

	for (int i = 0; i < length; i++) {
		char currentSymbol = str[i];
		bool foungInOther = false;

		for (int j = 0; j < other.length; j++) {
			if (currentSymbol == other.str[j]) {
				foungInOther = true;
				break;
			}
		}

		bool alreadyInResult = false;
		for (int k = 0; k < resultIndex; k++) {
			if (currentSymbol == result[k]) {
				alreadyInResult = true;
				break;
			}
		}

		if (foungInOther && !alreadyInResult) {
			result[resultIndex++] = currentSymbol;
		}
	}

	result[resultIndex] = '\0';
	return MyString(result);
}