/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 01:17:10 by shonakam          #+#    #+#             */
/*   Updated: 2025/08/09 14:16:00 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void) {}
RPN::~RPN(void) {}
RPN& RPN::operator=(const RPN& other) {
  (void)other;
  return (*this);
}
RPN::RPN(const RPN& other) { (void)other; }

double RPN::run(const std::string& input) {
  std::stack<double> operands;
  std::istringstream iss(input);
  std::string token;

  while (iss >> token) {
    // std::cout << "Token: " << "'" << token << "'" << std::endl;
    if (_isOperator(token)) {
      if (operands.size() < 2)
        throw std::runtime_error("insufficient operands.");
      double v = operands.top();
      operands.pop();
      double u = operands.top();
      operands.pop();
      double result = _evaluateExpression(u, v, token[0]);
      operands.push(result);
    } else {
      if (!_isValidInput(token))
        throw std::runtime_error("invalid input.");
      double value = std::strtod(token.c_str(), NULL);
      operands.push(value);
    }
  }
  if (operands.size() != 1)
    throw std::runtime_error("too many operands.");
  return operands.top();
}

double RPN::_evaluateExpression(double u, double v, const char op) {
  double result = 0.0;

  switch (op) {
    case '+':
      result = u + v;
      break;
    case '-':
      result = u - v;
      break;
    case '*':
      result = u * v;
      break;
    case '/': {
      if (v == 0.0)
        throw std::overflow_error("division by zero.");
      result = u / v;
      break;
    }
    default:
      // Unreachable code: this point should never be reached
      throw std::overflow_error(std::string("unknown operator: ") + op);
  };

  if (std::isnan(result) || std::isinf(result)) {
    throw std::overflow_error("out of range.");
  }
  return result;
}

bool RPN::_isOperator(const std::string& token) {
  return token == "+" || token == "-" || token == "*" || token == "/";
}

bool RPN::_isValidInput(const std::string& token) {
  return token.length() == 1 && std::isdigit(static_cast<unsigned char>(token[0]));
}
