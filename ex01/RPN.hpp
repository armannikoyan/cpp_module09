/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:11:28 by anikoyan          #+#    #+#             */
/*   Updated: 2025/10/16 01:33:32 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <cctype>
#include <string>
#include <sstream>

class RPN
{
	private:
		std::stack<long> _stack;

		void _executeCalculation(long (RPN::*f)(long, long));

		long _add(long a, long b);
		long _sub(long a, long b);
		long _mul(long a, long b);
		long _div(long a, long b);

	public:
		RPN();
		~RPN();
		RPN(const RPN& other);
		const RPN& operator=(const RPN& other);

		long calculateExpression(const std::string& exp);
};
