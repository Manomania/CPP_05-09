#include "ScalarConverter.hpp"

bool isChar(const std::string& string) {
	if (string[0] == '\'' && string[2] == '\'' && string.length() == 3)
		return (true);
	return (false);
}

bool isFloat(const std::string& string) {
	if (string.find('.') != std::string::npos && string[string.length() - 1] == 'f' )
		return (true);
	return (false);
}

bool isDouble(const std::string& string) {
	if (string.find('.') != std::string::npos)
		return (true);
	return (false);
}

bool isInt(const std::string& string) {
	return (!isFloat(string) && !isChar(string) && !isDouble(string));
}

bool isFloatSpecial(const std::string& string) {
	if (string == "-inff" || string == "+inff" || string == "nanf")
		return (true);
	return (false);
}

bool isDoubleSpecial(const std::string& string) {
	if (string == "-inf" || string == "+inf" || string == "nan")
		return (true);
	return (false);
}

char extractChar(const std::string& string) {
	return (string[1]);
}

int extractInt(const std::string& string) {
	return (std::atoi(string.c_str()));
}

float extractFloat(const std::string& string) {
	return (static_cast<float>(std::atof(string.c_str())));
}

double extractDouble(const std::string& string) {
	return (std::atof(string.c_str()));
}


void ScalarConverter::convert(const std::string& string) {

	if (isChar(string))
		std::cout << "isChar" << std::endl;
	else if (isFloat(string))
		std::cout << "isFloat" << std::endl;
	else if (isDouble(string))
		std::cout << "isDouble" << std::endl;
	else if (isFloatSpecial(string))
		std::cout << "isFloatSpecial" << std::endl;
	else if (isDoubleSpecial(string))
		std::cout << "isDoubleSpecial" << std::endl;
	else if (isInt(string))
		std::cout << "isInt" << std::endl;
};

