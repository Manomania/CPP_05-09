#include "ScalarConverter.hpp"

void ScalarConverter::displayChar(const std::string& string) {
	char convert = std::atoi(string.c_str());
	bool isSpecial = false;
	std::cout << "char: ";
	for (unsigned long i = 0; i < string.length() - 1; i++) {
		if (!isdigit(string[i])) {
			isSpecial = true;
			break;
		}
	}
	if (!isSpecial && convert >= 32 && convert <= 126)
		std::cout << "'" << convert << "'" << std::endl;
	else if (!isSpecial && ((convert >= 0 && convert < 32) || (convert > 126 && convert <= 127)))
		std::cout << "non displayable" << std::endl;
	else
		std::cout << "impossible" << std::endl;
}

void ScalarConverter::displayInt(const std::string& string) {
	long convert = std::atol(string.c_str());
	bool isSpecial = false;
	std::cout << "int: ";
	for (unsigned long i = 0; i < string.length() - 1; i++) {
		if (!isdigit(string[i])) {
			isSpecial = true;
			break;
		}
	}
	if (!isSpecial && convert >= INT_MIN && convert <= INT_MAX)
		std::cout << convert << std::endl;
	else
		std::cout << "impossible" << std::endl;
}

void ScalarConverter::displayFloat(const std::string& string) {
	double convert = std::atof(string.c_str());
	bool isSpecial = false;
	std::cout << "float: ";
	for (unsigned long i = 0; i < string.length() - 1; i++) {
		if (!isdigit(string[i])) {
			isSpecial = true;
			break;
		}
	}
	if (!isSpecial && convert >= INT_MIN && convert <= INT_MAX)
		std::cout << std::fixed << std::setprecision(1) << convert << "f" << std::endl;
	else
		std::cout << convert  << "f" << std::endl;
}

void ScalarConverter::displayDouble(const std::string& string) {
	double convert = std::atof(string.c_str());
	bool isSpecial = false;
	std::cout << "double: ";
	for (unsigned long i = 0; i < string.length() - 1; i++) {
		if (!isdigit(string[i])) {
			isSpecial = true;
			break;
		}
	}
	if (!isSpecial && convert >= INT_MIN && convert <= INT_MAX)
		std::cout << std::fixed << std::setprecision(1) << convert << std::endl;
	else
		std::cout << convert << std::endl;
}

void ScalarConverter::convert(const std::string& string) {
	displayChar(string);
	displayInt(string);
	displayFloat(string);
	displayDouble(string);
}