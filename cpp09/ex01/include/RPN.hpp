#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <iostream>

class RPN {
private:
	std::stack<int> _expression;
public:
	RPN();
	RPN(const std::string& expression);
	RPN(const RPN& copy);
	RPN& operator=(const RPN& other);
	~RPN();
	class ExceptionError: public std::exception {
		virtual const char* what() const throw();
	};
	void	stackRPN(const std::string& line);
	bool	isOperand(const std::string& expression);
	int		calculOperand(const std::string& expression);
};

#endif
