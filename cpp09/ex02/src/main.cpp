#include "PmergeMe.hpp"
#include <sstream>
#include <iostream>
#include <ctime>
#include <unistd.h>

int main(int argc, char** argv) {
	if (argc == 1) {
		std::cout << "Error" << std::endl;
		return (1);
	}
	std::string src;
	for (int i = 1; i < argc; i++) {
		src += argv[i];
		if (i != argc - 1)
			src += " ";
	}
	PmergeMe data;
	std::vector<int> vec;
	std::deque<int> deq;
	std::stringstream ss(src);
	int value;
	while (ss >> value) {
		if (value < 0) {
			std::cout << "Error" << std::endl;
			return (1);
		}
		vec.push_back(value);
		deq.push_back(value);
	}
	data.setVector(vec);
	data.setDeque(deq);

	size_t contSize = vec.size();
	size_t pairSize = 1;

	std::clock_t clockS = std::clock();
	data.createPairCont(vec, pairSize, contSize);
	std::clock_t clockE = std::clock();
	double timeV = static_cast<double>((clockE - clockS)) / CLOCKS_PER_SEC * 1000000;

	clockS = std::clock();
	data.createPairCont(deq, pairSize, contSize);
	clockE = std::clock();
	double timeD =  static_cast<double>((clockE - clockS)) / CLOCKS_PER_SEC * 1000000;

	std::vector<int>::const_iterator it = vec.begin();
	std::cout << "Before: " << src << std::endl;
	std::cout << "After:  ";
	for (;it < vec.end(); ++it) {
		std::cout << *it;
		if (it != vec.end() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << timeV << " μs" << std::endl;
	std::cout << "Time to process a range of " << deq.size() << " elements with std::deque:  " << timeD << " μs" << std::endl;
	return (0);
}
