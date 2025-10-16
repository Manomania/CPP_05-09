#ifndef ITER_HPP
#define ITER_HPP

template<typename T>
void iter(T *array, const int length, void (*f)(T&)) {
	if (length < 0)
		return ;
	for (int i = 0; i < length; i++) {
		f(array[i]);
	}
}

#endif
