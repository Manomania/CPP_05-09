#include "BitcoinExchange.hpp"

#include <cstdlib>
#include <ctime>
#include <string>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& filename) {
	std::ifstream myFile(filename.c_str());
	if (!myFile.is_open()) {
		std::cerr << "Error: could not open file: " << filename << std::endl;
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

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy): _exchange(copy._exchange) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other)
		this->_exchange = other._exchange;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

static bool checkDate(const std::string& date) {
	std::tm tm{};
	int year = std::atoi(date.substr(0, 4).c_str());
	tm.tm_year = date.substr(0, 4);
	std::stringstream data(date);
	int year;
	data >> year;
	if (year >= 2025)
		return (false);
	return (true);
}

void BitcoinExchange::calculDataWithInput(const std::string& input) {
	std::ifstream myFile(input.c_str());
	if (!myFile.is_open()) {
		std::cerr << "Error: could not open input file: " << input << std::endl;
		return ;
	}
	std::string line;
	while (getline(myFile, line)) {
		std::string date = line.substr(0, 10);
		if (checkDate(date))
			return ;
		std::cout << date << std::endl;
	}
}