#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template<typename T>
class MutantStack: public std::stack<T> {
public:
	MutantStack(): std::stack<T>() {};
	MutantStack(const MutantStack& copy): std::stack<T>(copy) {};
	MutantStack& operator=(const MutantStack& other) {
		if (this != &other) {
			std::stack<T>::operator=(other);
		}
		return (*this);
	};
	~MutantStack() {};
	// typedef pour T, typename pour dire que T va etre un type plutot qu'une variable
	// std::stack<T> car on veut recuperer protected C qui provient d'un container
	// ::container_type::iterator pour recuperer le member type
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

	iterator begin() {return (std::stack<T>::c.begin());};
	iterator end() {return (std::stack<T>::c.end());};

	const_iterator begin() const {return (std::stack<T>::c.begin());};
	const_iterator end() const {return (std::stack<T>::c.end());};

	reverse_iterator rbegin() {return (std::stack<T>::c.rbegin());};
	reverse_iterator rend() {return (std::stack<T>::c.rend());};

	const_reverse_iterator rbegin() const {return (std::stack<T>::c.rbegin());};
	const_reverse_iterator rend() const {return (std::stack<T>::c.rend());};
};

#endif
