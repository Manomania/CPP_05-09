#include <iostream>
#include "whatever.hpp"

#define BLACK		"\033[1;30m"
#define RED			"\033[0;31m"
#define GREEN		"\033[1;32m"
#define YELLOW		"\033[1;33m"
#define BLUE		"\033[1;34m"
#define MAGENTA		"\033[1;35m"
#define CYAN		"\033[0;36m"
#define WHITE		"\033[0;37m"
#define RESET		"\033[0m"
#define BOLD		"\033[1m"
#define ULINE		"\033[4m"
#define REVERSE		"\033[7m"

int main( ) {
	std::cout << RED ULINE BOLD"\nINT TEST"RESET << std::endl;
	int a = 2;
	int b = 3;
	std::cout << "a = "BLUE << a << RESET", b = "MAGENTA << b << RESET << std::endl;
	std::cout << YELLOW"SWAP"RESET << std::endl;
	::swap( a, b );
	std::cout << "a = "MAGENTA << a << RESET", b = "BLUE << b << RESET << std::endl;
	std::cout << YELLOW"SWAP"RESET << std::endl;
	::swap( a, b );
	std::cout << "a = "BLUE << a << RESET", b = "MAGENTA << b << RESET << std::endl;
	std::cout << YELLOW"SWAP"RESET << std::endl;
	::swap( a, b );
	std::cout << "a = "MAGENTA << a << RESET", b = "BLUE << b << RESET << std::endl;
	std::cout << "min( a, b ) = "BLUE << ::min( a, b ) << RESET << std::endl;
	std::cout << "max( a, b ) = "MAGENTA << ::max( a, b ) << RESET << std::endl;
	std::cout << RED ULINE BOLD"\nSTRING TEST"RESET << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << "c = "BLUE << c << RESET", d = "MAGENTA << d << RESET << std::endl;
	std::cout << YELLOW"SWAP"RESET << std::endl;
	::swap(c, d);
	std::cout << "c = "MAGENTA << c << RESET", d = "BLUE << d << RESET << std::endl;
	std::cout << YELLOW"SWAP"RESET << std::endl;
	::swap(c, d);
	std::cout << "c = "BLUE << c << RESET", d = "MAGENTA << d << RESET << std::endl;
	std::cout << YELLOW"SWAP"RESET << std::endl;
	::swap(c, d);
	std::cout << "c = "MAGENTA << c << RESET", d = "BLUE << d << RESET << std::endl;
	std::cout << "min( c, d ) = "BLUE << ::min( c, d ) << RESET << std::endl;
	std::cout << "max( c, d ) = "MAGENTA << ::max( c, d ) << RESET << std::endl;
	return 0;
}