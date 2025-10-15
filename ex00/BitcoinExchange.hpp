/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 02:38:44 by anikoyan          #+#    #+#             */
/*   Updated: 2025/10/15 04:16:49 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <fstream>
#include <stdexcept>
#include <string>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <algorithm>

#ifndef DATA_FILE
# define DATA_FILE "./data.csv"
#endif

class BitcoinExchange
{
	private:
		std::map<std::string, float> m_data;

	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		const BitcoinExchange& operator=(const BitcoinExchange& other);

		void calculateAssets(const std::string& file_path) const;
};
