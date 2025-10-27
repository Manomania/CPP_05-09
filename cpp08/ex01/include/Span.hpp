#ifndef SPAN_HPP
#define SPAN_HPP

class Span {
private:
	unsigned int	_maxInt;
public:
	Span();
	Span(const unsigned int& _maxInt);
	Span(const Span& copy);
	Span& operator=(const Span& other);
	~Span();
	void addNumber();
	void shortestSpan();
	void longestSpan();
};

#endif
