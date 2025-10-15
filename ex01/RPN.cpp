/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:30:32 by anikoyan          #+#    #+#             */
/*   Updated: 2025/10/16 01:37:31 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() : _stack() {}

RPN::~RPN() {}

RPN::RPN(const RPN& other)
{
	_stack = other._stack;
}

const RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
		_stack = other._stack;

	return *this;
}

long RPN::calculateExpression(const std::string& exp)
{
	std::stringstream ss(exp);
	std::string token;
	int num;

	while (std::getline(ss, token, ' '))
	{
		if ((token.length() == 1 && isdigit(token[0]))
				|| (token.length() == 2 && token[0] == '-' && isdigit(token[1])))
		{
			std::stringstream(token) >> num;
			_stack.push(num);
		}
		else if (token == "+")
			RPN::_executeCalculation(&RPN::_add);
		else if (token == "-")
			RPN::_executeCalculation(&RPN::_sub);
		else if (token == "*")
			RPN::_executeCalculation(&RPN::_mul);
		else if (token == "/")
			RPN::_executeCalculation(&RPN::_div);
		else
			throw std::runtime_error("Error");
	}

	return _stack.top();
}

void RPN::_executeCalculation(long (RPN::*f)(long, long))
{
	if (_stack.size() < 2)
		throw std::runtime_error("Error: check the input.");

	long a = _stack.top();
	_stack.pop();
	long b = _stack.top();
	_stack.pop();
	_stack.push((this->*f)(a, b));
}

long RPN::_add(long a, long b) { return b + a; }
long RPN::_sub(long a, long b) { return b - a; }
long RPN::_mul(long a, long b) { return b * a; }
long RPN::_div(long a, long b) { return a != 0 ? b / a : 0; }
