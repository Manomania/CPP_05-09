#include "Serializer.hpp"
#include <iomanip>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLDBLACK   "\033[1m\033[30m"
#define BOLDRED     "\033[1m\033[31m"
#define BOLDGREEN   "\033[1m\033[32m"
#define BOLDYELLOW  "\033[1m\033[33m"
#define BOLDBLUE    "\033[1m\033[34m"
#define BOLDMAGENTA "\033[1m\033[35m"
#define BOLDCYAN    "\033[1m\033[36m"
#define BOLDWHITE   "\033[1m\033[37m"

int main() {
	int value = 42;
	Serializer::Data dataOriginal;
	dataOriginal.ptr = &value;
	uintptr_t uint1 = Serializer::serialize(&dataOriginal);
	Serializer::Data* data1 = Serializer::deserialize(uint1);
	uintptr_t uint2 = Serializer::serialize(data1);
	Serializer::Data* data2 = Serializer::deserialize(uint2);
	uintptr_t uint3 = Serializer::serialize(data2);
	Serializer::Data* data3 = Serializer::deserialize(uint3);
	std::cout << GREEN << "original data: " << std::setw(19) << &dataOriginal << RESET << std::endl;
	std::cout << YELLOW << "serialize data: " << std::setw(19) << uint1 << RESET << std::endl;
	std::cout << GREEN << "deserialize uint1: " << std::setw(15) << data1 << RESET << std::endl;
	std::cout << YELLOW << "serialize data1: " << std::setw(18) << uint2 << RESET << std::endl;
	std::cout << GREEN << "deserialize uint2: " << std::setw(15) << data2 << RESET<< std::endl;
	std::cout << YELLOW << "serialize data2: " << std::setw(18) << uint3 << RESET << std::endl;
	std::cout << GREEN << "deserialize uint3: " << std::setw(15) << data3 << RESET<< std::endl;
	if (&dataOriginal == data1 && &dataOriginal == data2 && &dataOriginal == data3)
		std::cout << GREEN << "\nOK" << RESET << std::endl;
	else
		std::cout << RED << "KO" << RESET << std::endl;
	return 0;
}