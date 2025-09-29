#pragma once

#include "AForm.hpp"

class Intern {
private:
public:
	Intern();
	Intern(const Intern &copy);
	~Intern();
	AForm* makeForm(const std::string& form, const std::string& target);
};
