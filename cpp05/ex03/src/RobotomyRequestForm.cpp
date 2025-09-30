#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target): AForm("RobotomyRequestForm", 72, 45, target) {
	std::cout << this->getName() << " created for target: " << target << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
	AForm::execute(executor);
	std::cout << "* BZZZZZZZZZZT * BBBZZZZZZTTTT * FIUOOOOOOOOOOOOOOOOO * BZZZZZTTTT * DRDRDRDRDRDRDRDRDR *" << std::endl;
	srand(time(0));
	int	randomNum = rand() % 2;
	if (randomNum == 1)
		std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
	else
		std::cout << "Robotomy failed for " << this->getTarget() << "..." << std::endl;
}