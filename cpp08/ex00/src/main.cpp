#include "easyfind.hpp"
#include <vector>
#include <list>

#define BLACK		"\033[1;30m"
#define RED			"\033[0;31m"
#define GREEN		"\033[1;32m"
#define YELLOW		"\033[1;33m"
#define BLUE		"\033[1;34m"
#define MAGENTA		"\033[1;35m"
#define CYAN		"\033[0;36m"
#define WHITE		"\033[0;37m"
#define RESET		"\033[0m"
#define BOLD		"\033[1m"
#define ULINE		"\033[4m"
#define REVERSE		"\033[7m"

template<typename T>
void	pushEvenNumber(T& container, const int n) {
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0)
			container.push_back(i);
	}
}

int main() {
	std::cout << RED ULINE"\nTEST VECTOR FOUND ELEMENT"RESET << std::endl;
	try {
		std::vector<int> vector;
		pushEvenNumber(vector, 10);
		std::cout << YELLOW;
		easyfind(vector, 2);
		std::cout << RESET;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << RED ULINE"\nTEST VECTOR NOT FOUND ELEMENT"RESET << std::endl;
	try {
		std::vector<int> vector;
		pushEvenNumber(vector, 10);
		std::cout << BLUE;
		easyfind(vector, 1);
		std::cout << RESET;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << RED ULINE"\nTEST LIST FOUND ELEMENT"RESET << std::endl;
	try {
		std::list<int> list;
		pushEvenNumber(list, 10);
		std::cout << YELLOW;
		easyfind(list, 8);
		std::cout << RESET;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << RED ULINE"\nTEST LIST NOT FOUND ELEMENT"RESET << std::endl;
	try {
		std::list<int> list;
		pushEvenNumber(list, 10);
		std::cout << BLUE;
		easyfind(list, 1);
		std::cout << RESET;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}