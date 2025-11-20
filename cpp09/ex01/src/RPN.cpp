#include "RPN.hpp"

#include <sstream>

RPN::RPN() {}

RPN::RPN(const RPN& copy): _expression(copy._expression) {}

RPN& RPN::operator=(const RPN& other) {
	if (this != &other) {
		_expression = other._expression;
	}
	return (*this);
}

RPN::~RPN() {

}

const char* RPN::ExceptionError::what() const throw() {
	return ("Error");
}

bool	RPN::isOperand(const std::string& expression) {
	return (expression == "*" || expression == "/" ||expression == "+" ||expression == "-");
}

int	RPN::calculOperand(const std::string& operand) {
	int result = 0;
	int value2 = _expression.top();
	_expression.pop();
	int value1 = _expression.top();
	_expression.pop();
	if (operand == "*")
		result = value1 * value2;
	else if (operand == "+")
		result = value1 + value2;
	else if (operand == "-")
		result = value1 - value2;
	else if (operand == "/")
		result = value1 / value2;
	return (result);
}

void RPN::stackRPN(const std::string& line) {
	std::stringstream ss(line);
	std::string expression;
	while (ss >> expression) {
		if (expression.length() != 1 || (!isOperand(expression) && !isdigit(expression[0])))
			throw ExceptionError();
		if (isdigit(expression[0])) {
			int digit = expression[0] - '0';
			_expression.push(digit);
		}
		if (isOperand(expression)) {
			if (_expression.size() < 2)
				throw ExceptionError();
			_expression.push(calculOperand(expression));
		}
	}
	if (_expression.size() != 1)
		throw ExceptionError();
	std::cout << _expression.top() << std::endl;
	_expression.pop();
}

