#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>

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
	void				swapPairs(std::vector<int>& vec, size_t leftStart, size_t rightStart, size_t size);
	std::vector<int>&	createPairVec(std::vector<int>& vec, size_t& pairSize, size_t& vecSize);
	std::vector<size_t> generateJacobsthal(size_t n);
	size_t				getJacobsthalNumber(size_t index);
	void				insertWithJacobsthal(std::vector<int>& vec, std::vector<int>& pend, size_t& pairSize, size_t& incompletePair);
	void				dichotomicSearch(std::vector<int>& vec, std::vector<int>& stragglers);
	void				insertPendingElements(std::vector<int>& vec, size_t pairSize, size_t vecSize);
};
#endif
