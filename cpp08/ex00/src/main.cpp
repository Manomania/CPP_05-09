#include "easyfind.hpp"

#include <vector>
#include <list>

template<typename T>
void	testContainer(T& container, const int n) {
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0)
			container.push_back(i);
	}
}

int main(int argc, char **argv) {
	if (argc != 2)
		return (1);
	else {
		try {
			std::vector<int> vector;
			testContainer(vector, 10);
			easyfind(vector, std::atoi(argv[1]));
		} catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		try {
			std::list<int> list;
			testContainer(list, 10);
			easyfind(list, std::atoi(argv[1]));
		} catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}