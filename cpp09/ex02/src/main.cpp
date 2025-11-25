#include "PmergeMe.hpp"
#include <sstream>

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
	std::cout << "Before: " << src << std::endl;
	PmergeMe data;
	std::vector<int> vec;
	std::deque<int> deq;
	std::stringstream ss(src);
	int value;
	while (ss >> value) {
		vec.push_back(value);
		deq.push_back(value);
	}
	data.setVector(vec);
	data.setDeque(deq);
	size_t vecSize = vec.size();
	size_t pairSize = 1;
	data.createPairVec(vec, pairSize, vecSize);
	std::vector<int>::const_iterator it = vec.begin();
	std::cout << "After:  ";
	for (;it < vec.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
