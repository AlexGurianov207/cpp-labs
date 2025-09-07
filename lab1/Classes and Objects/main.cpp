#include"func.h"

int main() {

	MyString newStr("Hello World");

	newStr.printStr();

	newStr.inputStr();

	newStr.printStr();

	MyString toIntersection("Apple and worms");
	MyString intersectionResult = newStr.intersection(toIntersection);

	intersectionResult.printStr();

	return 0;
}