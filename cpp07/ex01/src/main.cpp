#include <iostream>
#include "iter.hpp"

void incrementChar(char &index) {
	++index;
}

void readChar(const char &c) {
	std::cout << c;
}

int main() {
	char nonConstChar[] = "AbCdEfGhIjKlMn";
	const char* constChar = "OpQrStUvWxYz";
	::iter(nonConstChar, 15, readChar);
	::iter(nonConstChar, 15, incrementChar);
	std::cout << std::endl;
	::iter(nonConstChar, 15, readChar);
	std::cout << std::endl;
	::iter(constChar, 15, readChar);
	return 0;
}