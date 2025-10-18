#ifndef ITER_HPP
#define ITER_HPP

template<typename T, typename F>
void iter(T* array, const int length, F function) {
	if (length < 0)
		return ;
	for (int i = 0; i < length; i++) {
		function(array[i]);
	}
}

#endif
