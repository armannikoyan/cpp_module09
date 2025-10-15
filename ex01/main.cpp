/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:26:49 by anikoyan          #+#    #+#             */
/*   Updated: 2025/10/16 01:33:47 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: wrong usage. [./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 +\"]"
			<< std::endl;

		return -1;
	}

	try
	{
		RPN rpn;
		std::cout << rpn.calculateExpression(argv[1]) << std::endl;
	} catch (const std::exception& ex) {
		std::cerr << "Unexpected error: " << ex.what() << std::endl;
	}
}
