#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
	if (argc == 2) {
		ScalarConverter::convert(argv[1]); 
	} else {
		std::cout << "\x1B[31mUsage: " << argv[0] << " <parameter1>\033[0m\t\t"<< std::endl;
		return (1);
	}
	return (0);
}
