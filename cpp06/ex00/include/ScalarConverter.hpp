#pragma once

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <climits>

class ScalarConverter {
private:
	static void displayInt(const std::string& string);
	static void displayChar(const std::string& string);
	static void displayFloat(const std::string& string);
	static void displayDouble(const std::string& string);

public:
	static void convert(const std::string& string);
};
