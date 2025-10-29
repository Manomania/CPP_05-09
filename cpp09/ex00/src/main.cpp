#include "BitcoinExchange.hpp"

int main() {
	BitcoinExchange database;
	database.loadDatabase("data.csv");
	database.displayDatabase(50000);
	return (0);
}