#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <iterator>
#include <algorithm>

class PmergeMe {
private:
	std::vector<int> _vector;
	std::deque<int> _deque;
public:
	PmergeMe();
	PmergeMe(const PmergeMe& copy);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();
	void	setVector(const std::vector<int>& vector);
	void	setDeque(const std::deque<int>& deque);
	std::vector<size_t> generateJacobsthal(size_t n);
	size_t				getJacobsthalNumber(size_t index);

	template<typename Container>
	void swapPairs(Container& container, typename Container::iterator leftStart, typename Container::iterator rightStart, size_t size);

	template<typename Container>
	void insertWithJacobsthal(Container& container, Container& pend, size_t pairSize, size_t incompletePair);

	template<typename Container>
	void dichotomicSearch(Container& container, Container& stragglers);

	template<typename Container>
	void insertPendingElements(Container& container, size_t pairSize, size_t containerSize);

	template<typename Container>
	Container& createPairCont(Container& container, size_t& pairSize, size_t& containerSize);
};

template<typename Container>
void PmergeMe::swapPairs(Container& container, typename Container::iterator leftStart, typename Container::iterator rightStart, size_t size) {
	(void)container;
	typename Container::iterator left = leftStart;
	typename Container::iterator right = rightStart;
	for (size_t i = 0; i < size; i++) {
		std::iter_swap(left, right);
		++left;
		++right;
	}
}

template<typename Container>
void PmergeMe::insertWithJacobsthal(Container& container, Container& pend, size_t pairSize, size_t incompletePair) {
	std::vector<size_t> jacobSeq = generateJacobsthal(incompletePair);
	for (size_t i = 0; i < jacobSeq.size(); i++) {
		size_t groupIndex = jacobSeq[i] - 1;
		typename Container::iterator pendStart = pend.begin();
		std::advance(pendStart, groupIndex * pairSize);
		typename Container::iterator pendEnd = pendStart;
		std::advance(pendEnd, pairSize);
		Container insertInContainer(pendStart, pendEnd);
		for (typename Container::iterator it = insertInContainer.begin(); it != insertInContainer.end(); ++it) {
			typename Container::iterator left = container.begin();
			typename Container::iterator right = container.end();
			while (std::distance(left, right) > 0) {
				typename Container::iterator mid = left;
				std::advance(mid, std::distance(left, right) / 2);
				if (*mid > *it) {
					right = mid;
				} else {
					left = mid;
					++left;
				}
			}
			container.insert(left, *it);
		}
	}
}

template<typename Container>
void PmergeMe::dichotomicSearch(Container& container, Container& stragglers) {
	for (typename Container::iterator straggler = stragglers.begin(); straggler != stragglers.end(); ++straggler) {
		typename Container::iterator left = container.begin();
		typename Container::iterator right = container.end();
		while (std::distance(left, right) > 0) {
			typename Container::iterator mid = left;
			std::advance(mid, std::distance(left, right) / 2);
			if (*mid > *straggler) {
				right = mid;
			} else {
				left = mid;
				++left;
			}
		}
		container.insert(left, *straggler);
	}
}

template<typename Container>
void PmergeMe::insertPendingElements(Container& container, size_t pairSize, size_t containerSize) {
	size_t completPair = containerSize / (pairSize * 2);
	size_t mainSize = completPair * pairSize * 2;
	size_t waiting = containerSize - mainSize;
	size_t incompletePair = waiting / pairSize;
	size_t pendSize = incompletePair * pairSize;
	size_t garbage = waiting % pairSize;
	Container pend;
	Container stragglers;
	typename Container::iterator mainEnd = container.begin();
	std::advance(mainEnd, mainSize);
	if (pendSize > 0) {
		typename Container::iterator pendEnd = mainEnd;
		std::advance(pendEnd, pendSize);
		pend.assign(mainEnd, pendEnd);
	}
	if (garbage > 0) {
		typename Container::iterator pendEnd = mainEnd;
		std::advance(pendEnd, pendSize);
		stragglers.assign(pendEnd, container.end());
	}
	container.erase(mainEnd, container.end());
	if (incompletePair > 0)
		insertWithJacobsthal(container, pend, pairSize, incompletePair);
	dichotomicSearch(container, stragglers);
}

template<typename Container>
Container& PmergeMe::createPairCont(Container& container, size_t& pairSize, size_t& containerSize) {
	pairSize *= 2;
	if (pairSize > containerSize)
		return container;
	for (size_t i = pairSize - 1; i < container.size(); i += pairSize) {
		typename Container::iterator leftPairMax = container.begin();
		std::advance(leftPairMax, i - pairSize / 2);
		typename Container::iterator rightPairMax = container.begin();
		std::advance(rightPairMax, i);
		if (*leftPairMax > *rightPairMax) {
			typename Container::iterator leftStart = container.begin();
			std::advance(leftStart, i - pairSize + 1);
			typename Container::iterator rightStart = container.begin();
			std::advance(rightStart, i - pairSize / 2 + 1);
			swapPairs(container, leftStart, rightStart, pairSize / 2);
		}
	}
	createPairCont(container, pairSize, containerSize);
	pairSize /= 2;
	insertPendingElements(container, pairSize, containerSize);
	return container;
}

#endif
