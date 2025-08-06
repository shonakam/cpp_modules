/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 22:20:24 by shonakam          #+#    #+#             */
/*   Updated: 2025/08/06 23:33:13 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

#define ERRMSG_00 "Error: could not open file."
#define ERRMSG_01 "Error: not a positive number."
#define ERRMSG_02 "Error: bad input => "
#define ERRMSG_03 "Error: too large a number."
#define ERRMSG_04 "Error: invalid input file header."

class BitcoinExchange {
 private:
  // -- OCCF
  BitcoinExchange(void);
  BitcoinExchange(const BitcoinExchange& other);
  ~BitcoinExchange(void);
  BitcoinExchange& operator=(const BitcoinExchange& other);

  static std::map<std::string, float> _rateDB;

  static bool _isValidFileHeader(const std::string& line,
                                 const std::string& expect);
  static bool _isValidDate(const std::string&);
  static bool _isValidNumber(const std::string&);
  static bool _getClosestRate(const std::string& date, float& rate);

  static void _loadData(const std::string& filename);
  static void _processInput(const std::string& input);
  static void _printResult(const std::string& date, float value);

 public:
  static void run(const std::string& value, const std::string& rate);
};
