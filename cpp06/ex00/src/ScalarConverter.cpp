#include "ScalarConverter.hpp"

bool ScalarConverter::isCharLiteral(const std::string& string){
	return (string.length() == 3 && string[0] == '\'' && string[2] == '\'');
}

bool ScalarConverter::isIntLiteral(const std::string& string){
	if (string.empty())
		return (false);
	size_t start = 0;
	if (string[0] == '+' || string[0] == '-') {
		start = 1;
		if (string.length() == 1)
			return false;
	}
	for (size_t i = start; i < string.length(); i++) {
		if (!std::isdigit(static_cast<unsigned char>(string[i])))
			return false;
	}
	if (string.find('.') != std::string::npos)
		return false;
	return (true);
}

bool ScalarConverter::isFloatLiteral(const std::string& string){
	if (string.empty() || string[string.length() - 1] != 'f')
		return (false);
	return (string.find('.') != std::string::npos);
}

bool ScalarConverter::isSpecialLiteral(const std::string& string){
	return (string == "-inff" || string == "-inf" || string == "+inff" || string == "+inf" || string == "nanf" || string == "nan");
}

ScalarConverter::LiteralType ScalarConverter::detectType(const std::string& string) {
	if (isCharLiteral(string))
		return (CHAR);
	if (isSpecialLiteral(string))
		return (SPECIAL);
	if (isFloatLiteral(string))
		return (FLOAT);
	if (string.find('.') != std::string::npos)
		return (DOUBLE);
	if (isIntLiteral(string))
		return (INT);
	return (INVALID);
}

void ScalarConverter::printChar(double value, bool impossible) {
	std::cout << "char: ";
	if (impossible || value < 0 || value > 127) {
		std::cout << "impossible" << std::endl;
		return;
	}
	int charValue = static_cast<int>(value);
	if (charValue < 32 || charValue == 127) {
		std::cout << "Non displayable" << std::endl;
		return;
	}
	std::cout << "'" << static_cast<char>(charValue) << "'" << std::endl;
}

void ScalarConverter::printInt(double value, bool impossible) {
	std::cout << "int: ";
	if (impossible || value < INT_MIN || value > INT_MAX) {
		std::cout << "impossible" << std::endl;
		return;
	}
	std::cout << static_cast<int>(value) << std::endl;
}

void ScalarConverter::printFloat(double value, bool isPseudo) {
	std::cout << "float: ";
	if (isPseudo) {
		std::cout << static_cast<float>(value) << "f" << std::endl;
		return;
	}
	std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
}

void ScalarConverter::printDouble(double value, bool isPseudo) {
	std::cout << "double: ";
	if (isPseudo) {
		std::cout << value << std::endl;
		return;
	}
	std::cout << std::fixed << std::setprecision(1) << value << std::endl;
}

void ScalarConverter::convert(const std::string& literal) {
	LiteralType type = detectType(literal);
	double value = 0.0;
	bool isSpecial = false;
	switch (type) {
		case CHAR:
			value = static_cast<double>(literal[1]);
			break;
		case INT:
			value = static_cast<double>(std::atoi(literal.c_str()));
			break;
		case FLOAT:
			value = std::atof(literal.c_str());
			isSpecial = isSpecialLiteral(literal);
			break;
		case DOUBLE:
			value = std::atof(literal.c_str());
			isSpecial = isSpecialLiteral(literal);
			break;
		case SPECIAL:
			value = std::atof(literal.c_str());
			isSpecial = true;
			break;
		case INVALID:
			break;
	}
	printChar(value, isSpecial);
	printInt(value, isSpecial);
	printFloat(value, isSpecial);
	printDouble(value, isSpecial);
}