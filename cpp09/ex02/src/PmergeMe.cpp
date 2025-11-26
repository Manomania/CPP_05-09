#include "PmergeMe.hpp"

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
	return *this;
}

PmergeMe::~PmergeMe() {}

size_t PmergeMe::getJacobsthalNumber(size_t index) {
	if (index == 0)
		return 0;
	if (index == 1)
		return 1;
	size_t prev = 0;
	size_t curr = 1;
	for (size_t i = 2; i <= index; i++) {
		size_t next = curr + 2 * prev;
		prev = curr;
		curr = next;
	}
	return curr;
}

std::vector<size_t> PmergeMe::generateJacobsthal(size_t n) {
	std::vector<size_t> sequence;
	if (n == 0)
		return sequence;
	sequence.push_back(1);
	if (n == 1)
		return sequence;
	size_t jacobPrev = 1;
	size_t jacobIndex = 3;
	while (jacobPrev < n) {
		size_t jacobCurr = getJacobsthalNumber(jacobIndex);
		if (jacobCurr > n)
			jacobCurr = n;
		for (size_t i = jacobCurr; i > jacobPrev; i--) {
			sequence.push_back(i);
		}
		jacobPrev = jacobCurr;
		jacobIndex++;
	}
	return sequence;
}
