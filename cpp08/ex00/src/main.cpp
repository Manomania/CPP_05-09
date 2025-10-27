#include "easyfind.hpp"

#include <vector>
#include <list>

int main() {
	std::vector<int> vector;
	std::list<int> list;
	for (int i = 0; i < 10; i++) {
		vector.push_back(i);
		list.push_back(i+3);
	}
	try {
		easyfind(vector, 2000);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}