#include "Span.hpp"

template<typename T>
void displayVector(const T& container) {
	for (unsigned int  i = 0; i < container.getSize(); i++) {
		std::cout << container[i];
		if (i != container.getSize() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}

int main()
{
	Span sp = Span(30000);
	try {
		sp.addRandomNumbers(30000);
		displayVector(sp);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	return 0;
}