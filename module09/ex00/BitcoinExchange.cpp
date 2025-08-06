/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:10:43 by shonakam          #+#    #+#             */
/*   Updated: 2025/08/06 23:41:49 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
  (void)other;
}
BitcoinExchange::~BitcoinExchange(void) {
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
  if (this != &other) {
  }
  return *this;
}

std::map<std::string, float> BitcoinExchange::_rateDB;

// == ENTRYPOINT ==
void BitcoinExchange::run(const std::string& value, const std::string& rate) {
  _loadData(rate);
  std::ifstream inputFile(value.c_str());
  if (!inputFile.is_open()) {
    std::cout << ERRMSG_00 << value << std::endl;
    return;
  }

  std::string line;
  std::getline(inputFile, line);

  if (!_isValidFileHeader(line, "date | value")) {
    std::cout << ERRMSG_04 << std::endl;
    inputFile.close();
    return;
  }

  while (std::getline(inputFile, line)) {
    if (line.empty())
      continue;
    _processInput(line);
  }
  inputFile.close();
}

// == PRIVATE METHOD ==

void BitcoinExchange::_loadData(const std::string& file) {
  std::string line;
  std::ifstream f(file.c_str());

  if (!f.is_open()) {
    std::cout << ERRMSG_00 << std::endl;
    return;
  }

  std::getline(f, line);  // skip 1st line;
  if (!_isValidFileHeader(line, "date,exchange_rate")) {
    std::cout << "Error: invalid file header." << std::endl;
    f.close();
    return;
  }

  while (std::getline(f, line)) {
    std::stringstream ss(line);
    std::string date, rateStr;

    if (std::getline(ss, date, ',') && std::getline(ss, rateStr)) {
      float rate = std::atof(rateStr.c_str());
      _rateDB[date] = rate;
    } else {
      std::cout << "Warning: invalid line -> " << line << std::endl;
    }
  }
  f.close();
}

void BitcoinExchange::_processInput(const std::string& input) {
  std::stringstream ss(input);
  std::string date, valueStr;

  if (std::getline(ss, date, '|') && std::getline(ss, valueStr)) {
    date.erase(0, date.find_first_not_of(" \t"));
    date.erase(date.find_last_not_of(" \t\n\r\f\v") + 1);
    valueStr.erase(0, valueStr.find_first_not_of(" \t"));

    if (!_isValidDate(date)) {
      std::cout << ERRMSG_02 << date << std::endl;
      return;
    }

    if (!_isValidNumber(valueStr)) {
      return;
    }

    float value = std::atof(valueStr.c_str());

    _printResult(date, value);
  } else {
    std::cout << ERRMSG_02 << input << std::endl;
  }
}

bool BitcoinExchange::_isValidFileHeader(const std::string& line,
                                         const std::string& expect) {
  return line == expect;
}

bool BitcoinExchange::_isValidDate(const std::string& date) {
  if (date.length() != 10 || date[4] != '-' || date[7] != '-')
    return false;

  int y = std::atoi(date.substr(0, 4).c_str());
  int m = std::atoi(date.substr(5, 2).c_str());
  int d = std::atoi(date.substr(8, 2).c_str());

  if (m < 1 || m > 12 || d < 1)
    return false;

  bool leap = (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
  int days[] = {31, (leap ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  return d <= days[m - 1];
}

bool BitcoinExchange::_isValidNumber(const std::string& number) {
  char* endptr;
  double val = std::strtod(number.c_str(), &endptr);

  if (endptr == number.c_str() || *endptr != '\0')
    return false;
  if (val > 1000) {
    std::cout << ERRMSG_03 << std::endl;
    return false;
  }
  if (val < 0) {
    std::cout << ERRMSG_01 << std::endl;
    return false;
  }
  return true;
}

void BitcoinExchange::_printResult(const std::string& date, float value) {
  float rate;
  if (_getClosestRate(date, rate)) {
    std::cout << date << " => " << value << " = " << (rate * value) << std::endl;
  } else {
    std::cout << "Error: no available rate before " << date << std::endl;
  }
}

bool BitcoinExchange::_getClosestRate(const std::string& date, float& rate) {
  std::map<std::string, float>::const_iterator it = _rateDB.lower_bound(date);

  if (it != _rateDB.end() && it->first == date) {
    rate = it->second;
    return true;
  }
  if (it != _rateDB.begin()) {
    --it;
    rate = it->second;
    return true;
  }
  return false;
}