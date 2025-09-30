#pragma once

#include <iostream>

class Bureaucrat {
private:
	const std::string	_name;
	size_t				_grade;
public:
	class GradeTooHighException: public std::exception {
	public:
		virtual const char* what() const throw() {
			return ("Grade too high, 1 max\n");
		}
	};
	class GradeTooLowException: public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("Grade too low, 150 min\n");
		}
	};
	Bureaucrat();
	Bureaucrat(const std::string& name, size_t grade);
	Bureaucrat(const Bureaucrat& copy);
	Bureaucrat& operator=(const Bureaucrat& pther);
	~Bureaucrat();
	const std::string& getName() const;
	size_t getGrade() const;
	void incrementGrade();
	void decrementGrade();
};

std::ostream& operator<<(std::ostream& os, Bureaucrat& bc);