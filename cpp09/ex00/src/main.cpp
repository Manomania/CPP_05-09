#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
	if (argc != 2)
		return 1;
	BitcoinExchange database("data.csv");
	database.calculDataWithInput(argv[1]);
	return (0);
}