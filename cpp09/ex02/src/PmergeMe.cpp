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

void PmergeMe::swapPairs(std::vector<int>& vec, size_t leftStart, size_t rightStart, size_t size) {
	for (size_t i = 0; i < size; i++) {
		std::swap(vec[leftStart + i], vec[rightStart + i]);
	}
}

std::vector<size_t> PmergeMe::generateJacobsthalSequence(size_t size) {
	std::vector<size_t> index;
	index.push_back(0);
	index.push_back(1);
	for (size_t i = 2; i < size; i++)
		index.push_back(index[i - 1] + 2 * index[i - 2]);
	return (index);
}

std::vector<int>&	PmergeMe::createPairVec(std::vector<int>& vec, size_t& pairSize, size_t& countPair) {
	pairSize *= 2;
	if (pairSize > countPair) {
		pairSize /= 2;
		return (vec);
	}
	for (size_t i = pairSize - 1; i < vec.size(); i += pairSize) {
		size_t leftPairMax = i - pairSize / 2;
		size_t rightPairMax = i;
		if (vec[leftPairMax] > vec[rightPairMax])
			swapPairs(vec, (i - pairSize + 1), (i - pairSize / 2 + 1), (pairSize / 2));
	}
	createPairVec(vec, pairSize, countPair);
	if (pairSize > countPair / 2) {
		size_t pendIndex = pairSize;
		//TODO implemente the insertion from jacobstal suit.
		std::vector<int> pend;
		for (size_t i = pendIndex; i < vec.size(); i += pairSize) {
			pend.push_back(vec[i]);
		}
		std::vector<size_t> jacobsthalIndexes = generateJacobsthalSequence(pend.size());
		for (size_t i = 0; i < jacobsthalIndexes.size(); i++) {
			std::cout << jacobsthalIndexes[i] << std::endl;
		}
		pairSize /= 2;
	}
	return (vec);
}
