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

double extractFLoatSpecial(const std::string& string) {
	return (std::atof(string.c_str()));
}

double extractDouble(const std::string& string) {
	return (std::atof(string.c_str()));
}

double extractDoubleSpecial(const std::string& string) {
	return (std::atof(string.c_str()));
}

void ScalarConverter::convert(const std::string& string) {
	bool	charValid = false;
	bool	intValid = false;
	bool	floatValid = false;
	bool	doubleValid = false;
	bool	floatSpValid = false;
	bool	doubleSpValid = false;

	if (isChar(string))
		charValid = true;
	else if (isFloat(string))
		floatValid = true;
	else if (isDouble(string))
		doubleValid = true;
	else if (isFloatSpecial(string))
		floatSpValid = true;
	else if (isDoubleSpecial(string))
		doubleSpValid = true;
	else if (isInt(string))
		intValid = true;
}