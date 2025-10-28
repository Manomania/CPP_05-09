#include "Span.hpp"

Span::Span(): _maxInt(0) {}

Span::Span(const unsigned int& maxInt): _maxInt(maxInt) {}

Span::Span(const Span& copy): _maxInt(copy._maxInt), _elements(copy._elements) {}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		this->_maxInt = other._maxInt;
		this->_elements = other._elements;
	}
	return (*this);
}

unsigned int Span::operator[](unsigned int index) const {
	return (this->_elements[index]);
}

Span::~Span() {}

const char* Span::CantCompareException::what() const throw() {
	return ("Container need at least 2 elements");
}

const char* Span::OutOfRangeException::what() const throw() {
	return ("Can't add number out of range");
}

unsigned int Span::getSize() const {
	return (_elements.size());
}

void Span::addNumber(const int& n) {
	if (this->_elements.size() >= this->_maxInt)
		throw OutOfRangeException();
	else
		this->_elements.push_back(n);
}

void Span::addRandomNumbers(const unsigned int& size) {
	if (this->_elements.size() + size > this->_maxInt)
		throw OutOfRangeException();
	srand(time(0));
	for (unsigned int i = 0; i < size; i++)
		addNumber(rand() % size);
}

unsigned int Span::shortestSpan() const {
	if (this->_elements.size() < 2)
		throw CantCompareException();
	std::vector<int> copy = this->_elements;
	std::sort(copy.begin(), copy.end());
	unsigned int min = UINT_MAX;
	unsigned int temp = 0;
	for (unsigned int i = 0; i < copy.size() - 1; i++) {
		temp = copy[i+1] - copy[i];
		if (min > temp)
			min = temp;
	}
	return (min);
}

unsigned int Span::longestSpan() const {
	if (this->_elements.size() < 2)
		throw CantCompareException();
	std::vector<int> copy = this->_elements;
	std::sort(copy.begin(), copy.end());
	unsigned int max = copy[copy.size()-1] - copy[0];
	return (max);
}