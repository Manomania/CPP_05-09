#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <climits>
#include <cstdlib>
#include <vector>
#include <iostream>

class Span {
private:
	unsigned int		_maxInt;
	std::vector<int>	_elements;
public:
	Span();
	Span(const unsigned int& maxInt);
	Span(const Span& copy);
	Span& operator=(const Span& other);
	unsigned int operator[](unsigned int index) const;
	~Span();
	class CantCompareException: public std::exception {
	public:
		virtual const char* what() const throw();
	};
	class OutOfRangeException: public std::exception {
	public:
		virtual const char* what() const throw();
	};
	unsigned int getSize() const;
	void addNumber(const int& n);
	void addRandomNumbers(const unsigned int& size);
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;
};

inline std::ostream& operator<<(std::ostream& os, const Span& span) {
	for (unsigned int i = 0; i < span.getSize(); i++)
		os << span[i] << std::endl;
	return (os);
}

#endif
