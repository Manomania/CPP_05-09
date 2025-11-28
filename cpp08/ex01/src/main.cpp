#include "Span.hpp"

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
void displayVector(const T& container) {
	for (unsigned int  i = 0; i < container.getSize(); i++) {
		std::cout << container[i];
		if (i != container.getSize() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}

int main() {
	Span sp = Span(100);
	std::cout << RED ULINE"\nTEST WITH 3"RESET << std::endl;
	try {
		sp.addRandomNumbers(3);
		std::cout << "Inside Span: "YELLOW;
		displayVector(sp);
		std::cout << RESET;
		std::cout << "Shortest length: "BLUE<< sp.shortestSpan() << RESET << std::endl;
		std::cout << "Longest length: "MAGENTA << sp.longestSpan() << RESET << std::endl;
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << RESET << std::endl;
	}
	std::cout << RED ULINE"\nTEST WITH 10 MORE"RESET << std::endl;
	try {
		sp.addRandomNumbers(10);
		std::cout << "Inside Span: "YELLOW;
		displayVector(sp);
		std::cout << RESET;
		std::cout << "Shortest length: "BLUE<< sp.shortestSpan() << RESET << std::endl;
		std::cout << "Longest length: "MAGENTA << sp.longestSpan() << RESET << std::endl;
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << RESET << std::endl;
	}
	Span s2 = Span(10);
	std::cout << RED ULINE"\nTEST WITH 20 BUT MAXIMUM IS 10"RESET << std::endl;
	try {
		s2.addRandomNumbers(20);
		std::cout << "Inside Span: "YELLOW;
		displayVector(s2);
		std::cout << RESET;
		std::cout << "Shortest length: "BLUE<< s2.shortestSpan() << RESET << std::endl;
		std::cout << "Longest length: "MAGENTA << s2.longestSpan() << RESET << std::endl;
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << RESET << std::endl;
	}
	Span s3 = Span(5);
	std::cout << RED ULINE"\nTEST WITH 1 BUT MAXIMUM IS 5"RESET << std::endl;
	try {
		s3.addRandomNumbers(1);
		std::cout << "Inside Span: "YELLOW;
		displayVector(s3);
		std::cout << RESET;
		std::cout << s3.shortestSpan() << RESET << std::endl;
		std::cout << s3.longestSpan() << RESET << std::endl;
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << RESET << std::endl;
	}
	std::cout << RED ULINE"\nTEST WITH 4 MORE BUT MAXIMUM IS 5"RESET << std::endl;
	try {
		s3.addRandomNumbers(4);
		std::cout << "Inside Span: "YELLOW;
		displayVector(s3);
		std::cout << RESET;
		std::cout << "Shortest length: "BLUE<< s3.shortestSpan() << RESET << std::endl;
		std::cout << "Longest length: "MAGENTA << s3.longestSpan() << RESET << std::endl;
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << RESET << std::endl;
	}
	return 0;
}