#include "BitcoinExchange.hpp"

int main() {
	BitcoinExchange database;
	database.loadDatabase("data.csv");
	return (0);
}