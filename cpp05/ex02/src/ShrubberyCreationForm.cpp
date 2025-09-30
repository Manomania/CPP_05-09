#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target): AForm("ShrubberyCreationForm", 145, 137, target) {
	std::cout << this->getName() << " created for target: " << target << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
	AForm::execute(executor);
	std::ofstream myFile;
	myFile.open((this->getTarget() + "_shrubbery").c_str());
	myFile << "     *     \n";
	myFile << "    ***    \n";
	myFile << "   *****   \n";
	myFile << "  *******  \n";
	myFile << " ********* \n";
	myFile << "***********\n";
	myFile << "    |||    \n";
	myFile << "    |||    \n";
	myFile << "    ‾‾‾    " << std::endl;
	myFile.close();
}