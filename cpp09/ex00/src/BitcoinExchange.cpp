#include "BitcoinExchange.hpp"

#include <cstdlib>
#include <ctime>
#include <climits>
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
	std::stringstream ss(date);
	int year, month, day;
	char sep;
	ss >> year >> sep >> month >> sep >> day;
	if (year > 2025 || year <= 1900 || month < 1 || month > 12 || day < 1 || day > 31 )
		return (true);
	return (false);
}

static bool checkNumber(const double number) {
	if (number > INT_MAX) {
		std::cerr << "Error: too large a number." << std::endl;
		return (true);
	}
	if (number < 0) {
		std::cerr << "Error: not a positive number." << std::endl;
		return (true);
	}
	return (false);
}

void BitcoinExchange::calculDataWithInput(const std::string& input) {
	std::ifstream myFile(input.c_str());
	if (!myFile.is_open()) {
		std::cerr << "Error: could not open file " << input << std::endl;
		return ;
	}
	std::string line;
	bool firstline = true;
	while (getline(myFile, line)) {
		if (line == "date | value") {
			firstline = false;
			continue;
		}
		if (firstline) {
			std::cerr << "Error: invalid header in " << input << std::endl;
			break;
		}
		size_t pipePos = line.find(" | ");
		if (pipePos == std::string::npos || pipePos < 10) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string date = line.substr(0, 10);
		if (checkDate(date)) {
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}
		double number = std::atof(line.substr(pipePos + 3).c_str());
		if (checkNumber(number))
			continue;
		std::map<std::string, double>::const_iterator it = _exchange.lower_bound(date);
		if (it == _exchange.begin() || it->first != date) {
			if (it == _exchange.end()) {
				std::cerr << "Error: no exchange rate available for " << date << std::endl;
				continue;
				}
			--it;
		}
		double result = number * it->second;
		std::cout << date << " => " << number << " = " << result << std::endl;
	}
}