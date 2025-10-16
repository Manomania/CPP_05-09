#include <iostream>
#include "iter.hpp"

template<typename T>
void incrementChar(T &index) {
	++index;
}

int main() {
	std::string array = "aBcDeF";
	char array2[] = "AbCdEf";
	iter(array2, 1, incrementChar);
	std::cout << array << std::endl;
	std::cout << array2 << std::endl;
	return 0;
}