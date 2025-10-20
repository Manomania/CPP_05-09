#include <iostream>
#include "Array.hpp"

class Test {
public:
	std::string data;
	Test() {};
	Test(const std::string& str): data(str){};
	~Test() {};
};
std::ostream& operator<<(std::ostream& os, const Test& c) {
	os << c.data;
	return (os);
};

int main() {
	try {
		Array<int> testInt;
		std::cout << testInt[0] << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Array<int> testInt1(3);
		testInt1[0] = 1;
		testInt1[1] = 2;
		testInt1[2] = 3;
		for (unsigned int i = 0; i < testInt1.size(); i++)
			std::cout << "testInt1["<< i << "]: " << testInt1[i] << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Array<int> testInt1(3);
		testInt1[0] = 3;
		testInt1[1] = 2;
		testInt1[2] = 1;
		Array<int> testInt2(3);
		testInt2[0] = 1;
		testInt2[1] = 2;
		testInt2[2] = 3;
		for (unsigned int i = 0; i < testInt2.size(); i++)
			std::cout << "testInt2["<< i << "]: " << testInt2[i] << std::endl;
		testInt2 = testInt1;
		std::cout << "testInt2 == testInt1" << std::endl;
		for (unsigned int i = 0; i < testInt2.size(); i++)
			std::cout << "testInt2["<< i << "]: " << testInt2[i] << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Array<char> testChar(2);
		testChar[0] = 'H';
		testChar[1] = 'I';
		for (unsigned int i = 0; i < testChar.size(); i++)
			std::cout << "testChar["<< i << "]: " << testChar[i] << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Array<std::string> testString(2);
		testString[0] = "Hello";
		testString[1] = "Bonjour";
		for (unsigned int i = 0; i < testString.size(); i++)
			std::cout << "testString["<< i << "]: " << testString[i] << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Array<Test> testClass(2);
		testClass[0] = Test("Hello");
		testClass[1] = Test("Bonjour");
		for (unsigned int i = 0; i < testClass.size(); i++)
			std::cout << "testClass["<< i << "]: " << testClass[i] << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}