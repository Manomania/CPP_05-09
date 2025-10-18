#include <iostream>
#include "iter.hpp"

template<typename T>
void incrementChar(T &index) {
	++index;
}

template<typename T>
void readChar(T &c) {
	std::cout << c;
}

int main() {
	char nonConstChar[] = "AbCdEfGhIjKlMn";
	const char* constChar = "OpQrStUvWxYz";
	::iter(nonConstChar, 10, incrementChar);
	return 0;
}