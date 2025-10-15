/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 03:03:40 by anikoyan          #+#    #+#             */
/*   Updated: 2025/10/15 04:21:24 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
	if (argc < 2)
		std::cerr << "Error: could not open file." << std::endl;
	else if (argc > 2)
		std::cerr << "Error\nUsage: ./btc file_name" << std::endl;
	else
	{
		try
		{
			BitcoinExchange btc;
			btc.calculateAssets(argv[1]);
		} catch (const std::exception& ex) {
			std::cerr << "Unexpected error: " << ex.what() << std::endl;
		}
	}
}
