/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 01:17:07 by shonakam          #+#    #+#             */
/*   Updated: 2025/08/08 02:49:48 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cctype>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>

class RPN {
 private:
  // -- OCCF
  RPN(void);
  RPN(const RPN& other);
  ~RPN(void);
  RPN& operator=(const RPN& other);

  static double _evaluateExpression(double u, double v, const char op);
  static bool _isOperator(const std::string& token);
  static bool _isValidInput(const std::string& input);

 public:
  static double run(const std::string& input);
};
