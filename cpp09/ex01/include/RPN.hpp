#ifndef RPN_HPP
#define RPN_HPP

#include <vector>
#include <string>
class RPN {
private:
	std::vector<std::string> _expression;
public:
	RPN();
	RPN(const std::string& expression);
	RPN(const RPN& copy);
	RPN& operator=(const RPN& other);
	~RPN();
};

#endif
