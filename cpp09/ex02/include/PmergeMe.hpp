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
	std::vector<int>&	createPairVec(std::vector<int>& vec, size_t& pairSize, size_t& countPair);
	void				swapPairs(std::vector<int>& vec, size_t leftStart, size_t rightStart, size_t size);
	std::vector<size_t> generateJacobsthalSequence(size_t size);
};

#endif
