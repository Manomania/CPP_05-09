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
	std::vector<int>&	getVector();
	std::deque<int>&	getDeque();
	static std::vector<size_t>	generateJacobsthal(size_t n);
	static size_t				getJacobsthalNumber(size_t index);

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

#endif
