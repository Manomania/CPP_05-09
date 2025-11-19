#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

class BitcoinExchange {
private:
	std::map<std::string, float> _exchange;
public:
	BitcoinExchange();
	BitcoinExchange(const std::string& filename);
	BitcoinExchange(const BitcoinExchange& copy);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();
	void calculDataWithInput(const std::string& input);
};

#endif
