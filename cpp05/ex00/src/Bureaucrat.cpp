#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("default"), _grade(150) {
}

Bureaucrat::Bureaucrat(const std::string& name, size_t grade): _name(name), _grade(grade) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy): _name(copy._name), _grade(copy._grade) {
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy) {
	if (this != &copy)
		this->_grade = copy._grade;
	return (*this);
}
Bureaucrat::~Bureaucrat() {
}

const std::string& Bureaucrat::getName() const {
	return (this->_name);
}

size_t Bureaucrat::getGrade() const {
	return (this->_grade);
}

void Bureaucrat::incrementGrade() {
	if (this->_grade == 1)
		throw GradeTooHighException();
	else
		this->_grade--;

}

void Bureaucrat::decrementGrade() {
	if (this->_grade == 150)
		throw GradeTooLowException();
	else
		this->_grade++;
}

std::ostream& operator<<(std::ostream& os, Bureaucrat& bc) {
	os << bc.getName() << ", bureaucrat grade " << bc.getGrade() << std::endl;
	return (os);
}
