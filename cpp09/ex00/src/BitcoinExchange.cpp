#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy): _exchange(copy._exchange) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other)
		this->_exchange = other._exchange;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string& filename) {
	std::ifstream myFile(filename.c_str());
	if (!myFile.is_open()) {
		std::cerr << "Error: could not open file " << filename << std::endl;
		return ;
	}
	std::string line;
	while (std::getline(myFile, line)) {
		if (line == "date,exchange_rate")
			continue;
		std::stringstream ss(line);
		std::string date;
		double rate = 0;
		std::getline(ss, date, ',');
		ss >> rate;
		this->_exchange[date] = rate;
	}
	myFile.close();
}
