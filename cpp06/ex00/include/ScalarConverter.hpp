#pragma once

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <climits>

class ScalarConverter {
private:
	enum LiteralType {
		CHAR,
		INT,
		FLOAT,
		DOUBLE,
		SPECIAL,
		INVALID
	};
	static LiteralType detectType(const std::string& string);
	static bool isCharLiteral(const std::string& string);
	static bool isIntLiteral(const std::string& string);
	static bool isFloatLiteral(const std::string& string);
	static bool isSpecialLiteral(const std::string& string);
	static void printInt(double value, bool impossible);
	static void printChar(double value, bool impossible);
	static void printFloat(double value, bool impossible);
	static void printDouble(double value, bool impossible);
public:
	static void convert(const std::string& string);
};
