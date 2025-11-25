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
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::swapPairs(std::vector<int>& vec, size_t leftStart, size_t rightStart, size_t size) {
	for (size_t i = 0; i < size; i++) {
		std::swap(vec[leftStart + i], vec[rightStart + i]);
	}
}

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

void PmergeMe::insertWithJacobsthal(std::vector<int>& vec, std::vector<int>& pend, size_t& pairSize, size_t& incompletePair) {
	std::vector<size_t> jacobSeq = generateJacobsthal(incompletePair);
	for (size_t i = 0; i < jacobSeq.size(); i++) {
		size_t groupIndex = jacobSeq[i] - 1;
		std::vector<int> insertInVec(pend.begin() + groupIndex * pairSize, pend.begin() + (groupIndex + 1) * pairSize);
		for (size_t j = 0; j < insertInVec.size(); j++) {
			size_t left = 0;
			size_t right = vec.size();
			while (left < right) {
				size_t mid = left + (right - left) / 2;
				if (vec[mid] > insertInVec[j])
					right = mid;
				else
					left = mid + 1;
			}
			vec.insert(vec.begin() + left, insertInVec[j]);
		}
	}
}

void PmergeMe::dichotomicSearch(std::vector<int>& vec, std::vector<int>& stragglers) {
	for (size_t i = 0; i < stragglers.size(); i++) {
		size_t left = 0;
		size_t right = vec.size();
		while (left < right) {
			size_t mid = left + (right - left) / 2;
			if (vec[mid] > stragglers[i])
				right = mid;
			else
				left = mid + 1;
		}
		vec.insert(vec.begin() + left, stragglers[i]);
	}
}

void PmergeMe::insertPendingElements(std::vector<int>& vec, size_t pairSize, size_t vecSize) {
	size_t completPair = vecSize / (pairSize * 2);
	size_t mainSize = completPair * pairSize * 2;
	size_t waiting = vecSize - mainSize;
	size_t incompletePair = waiting / pairSize;
	size_t pendSize = incompletePair * pairSize;
	size_t garbage = waiting % pairSize;
	std::vector<int> pend;
	std::vector<int> stragglers;
	if (pendSize > 0)
		pend.assign(vec.begin() + mainSize, vec.begin() + mainSize + pendSize);
	if (garbage > 0)
		stragglers.assign(vec.begin() + mainSize + pendSize, vec.begin() + vecSize);
	vec.erase(vec.begin() + mainSize, vec.end());
	if (incompletePair > 0)
		insertWithJacobsthal(vec, pend, pairSize, incompletePair);
	dichotomicSearch(vec, stragglers);
}

std::vector<int>&	PmergeMe::createPairVec(std::vector<int>& vec, size_t& pairSize, size_t& vecSize) {
	pairSize *= 2;
	if (pairSize > vecSize)
		return vec;
	for (size_t i = pairSize - 1; i < vec.size(); i += pairSize) {
		size_t leftPairMax = i - pairSize / 2;
		size_t rightPairMax = i;
		if (vec[leftPairMax] > vec[rightPairMax])
			swapPairs(vec, (i - pairSize + 1), (i - pairSize / 2 + 1), (pairSize / 2));
	}
	createPairVec(vec, pairSize, vecSize);
	pairSize /= 2;
	insertPendingElements(vec, pairSize, vecSize);
	return vec;
}
