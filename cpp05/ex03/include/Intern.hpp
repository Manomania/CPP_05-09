#pragma once

#include "AForm.hpp"

class Intern {
private:
public:
	class FormNotFoundException: public std::exception {
	public:
		virtual const char* what() const throw() {
			return ("Form do not exist\n");
		}
	};
	Intern();
	Intern(const Intern &copy);
	~Intern();
	AForm* makeForm(const std::string& form, const std::string& target);
};
