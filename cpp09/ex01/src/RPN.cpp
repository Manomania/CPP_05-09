#include "RPN.hpp"

#include <sstream>

RPN::RPN(): _expression(0) {}

RPN::RPN(const std::string& expression) {
	std::stringstream ss(expression);
	std::string line;
	while (ss << line)
}

RPN::RPN(const RPN& copy): _expression(copy._expression) {}

RPN& RPN::operator=(const RPN& other) {
	if (this != &other) {
		_expression = other._expression;
	}
	return (*this);
}

RPN::~RPN() {

}