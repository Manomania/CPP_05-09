#include <iostream>
#include "iter.hpp"

#define BLACK		"\033[1;30m"
#define RED			"\033[0;31m"
#define GREEN		"\033[1;32m"
#define YELLOW		"\033[1;33m"
#define BLUE		"\033[1;34m"
#define MAGENTA		"\033[1;35m"
#define CYAN		"\033[0;36m"
#define WHITE		"\033[0;37m"
#define RESET		"\033[0m"
#define BOLD		"\033[1m"
#define ULINE		"\033[4m"
#define REVERSE		"\033[7m"

void incrementChar(char &c) {
	++c;
}

void printChar(const char &c) {
	std::cout << c;
}

void printInt(const int &n) {
	std::cout << n << " ";
}

void doubleInt(int &n) {
	n *= 2;
}

template<typename T>
void printElement(const T& element) {
	std::cout << element << " ";
}

int main() {
	std::cout << RED BOLD ULINE"CHAR ARRAY"RESET << std::endl;
	char charArray[] = "Hello";
	std::cout << YELLOW"Original: ";
	::iter(charArray, 5, printChar);
	std::cout << std::endl;
	::iter(charArray, 5, incrementChar);
	std::cout << MAGENTA"After increment: ";
	::iter(charArray, 5, printChar);
	std::cout << std::endl;
	std::cout << RED BOLD ULINE"\nINT ARRAY"RESET << std::endl;
	int intArray[] = {1, 2, 3, 4, 5};
	std::cout << YELLOW"Original: ";
	::iter(intArray, 5, printInt);
	std::cout << std::endl;
	::iter(intArray, 5, doubleInt);
	std::cout << MAGENTA"After doubling: ";
	::iter(intArray, 5, printInt);
	std::cout << std::endl;
	std::cout << RED BOLD ULINE"\nCONST CHAR ARRAY"RESET << std::endl;
	const char constArray[] = "World";
	std::cout << YELLOW"Const array: ";
	::iter(constArray, 5, printChar);
	std::cout << std::endl;
	std::cout << RED BOLD ULINE"\nTEMPLATE FUNCTION"RESET << std::endl;
	std::cout << CYAN"String elements: ";
	::iter(charArray, 5, printElement<char>);
	std::cout << std::endl;
	std::cout << CYAN"Int elements: ";
	::iter(intArray, 5, printElement<int>);
	std::cout << std::endl;
	return 0;
}