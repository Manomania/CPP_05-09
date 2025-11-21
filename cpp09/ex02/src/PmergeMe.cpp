#include "PmergeMe.hpp"
#include <sstream>


void	PmergeMe::setVector(const std::vector<int>& vector) {
	_vector = vector;
}
void	PmergeMe::setDeque(const std::deque<int>& deque) {
	_deque = deque;
}

PmergeMe::PmergeMe(): _vector(), _deque() {}


PmergeMe::PmergeMe(const PmergeMe& copy): _vector(copy._vector), _deque(copy._deque) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		this->_vector = other._vector;
		this->_deque = other._deque;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}

std::vector<int>&	PmergeMe::createPairVec(std::vector<int>& vec) {
	size_t pairSize = vec.size() / 2;
	if (pairSize % 2 == 1)
		pairSize -= 1;
	//TODO implement pair algo recursive
}
