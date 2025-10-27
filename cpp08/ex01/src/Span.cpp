#include "Span.hpp"

Span::Span() {

}
Span::Span(const unsigned int& _maxInt) {
	if (_maxInt)
}
Span::Span(const Span& copy): _maxInt(copy._maxInt) {}
Span& Span::operator=(const Span& other) {
	if (this != &other)
		this->_maxInt = other._maxInt;
	return (*this);
}