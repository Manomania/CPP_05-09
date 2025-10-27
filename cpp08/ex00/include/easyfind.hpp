#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <stdexcept>

class NotFoundException: public std::exception {
public :
	virtual const char* what() const throw() {
		return ("Element not found in container");
	}
};

template<typename T>
void	easyfind(const T& container, int n) {
	typename T::const_iterator it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw NotFoundException();
	std::cout << "Value found: " << *it << std::endl;
}

#endif
