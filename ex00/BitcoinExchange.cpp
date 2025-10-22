/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 02:45:10 by anikoyan          #+#    #+#             */
/*   Updated: 2025/10/22 18:40:15 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <iterator>

static std::string trim(const std::string& source)
{
    std::string s(source);

    s.erase(0,s.find_first_not_of(" \n\r\t"));
    s.erase(s.find_last_not_of(" \n\r\t") + 1);

    return s;
}

BitcoinExchange::BitcoinExchange()
{
	std::ifstream file(DATA_FILE);
	if (!file.is_open())
		throw std::runtime_error("Cannot open ./data.csv file.\n");

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		size_t pos = 0;
		if ((pos = line.find(",", 0)) != std::string::npos)
		{
			std::string date = trim(line.substr(0, pos));
			float amount = atof(line.substr(++pos, std::string::npos).c_str());

			m_data.insert(std::pair<std::string, float>(date, amount));
		}
		else
			throw std::runtime_error("Cannot parse ./data.csv file.\n");
	}

	file.close();
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	m_data = other.m_data;
}

const BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		m_data = other.m_data;

	return *this;
}

void BitcoinExchange::calculateAssets(const std::string& file_path) const
{
	std::ifstream file(file_path.c_str());
	if (!file.is_open())
		throw std::runtime_error(std::string("Cannot open ") + file_path
				+ std::string(" file.\n"));

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		size_t pos = 0;
		if ((pos = line.find("|", 0)) != std::string::npos)
		{
			std::string date = trim(line.substr(0, pos));

			size_t dash1 = date.find('-');
			size_t dash2 = date.find('-', dash1 + 1);

			if (dash1 == std::string::npos || dash2 == std::string::npos) {
				std::cerr << "Error: bad input => " << date << std::endl;
				continue;
			}

			int year  = atoi(date.substr(0, dash1).c_str());
			int month = atoi(date.substr(dash1 + 1, dash2 - dash1 - 1).c_str());
			int day   = atoi(date.substr(dash2 + 1).c_str());

			if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31) {
				std::cerr << "Error: bad input => " << date << std::endl;
				continue;
			}

			float amount = atof(line.substr(++pos, std::string::npos).c_str());
			if (amount < 0)
			{
				std::cerr << "Error: not a positive number." << std::endl;
				continue;
			}
			else if (amount > 1000)
			{
				std::cerr << "Error: too large a number." << std::endl;
				continue;
			}

			std::map<std::string, float>::const_iterator it = m_data.upper_bound(date);
			if (it == m_data.begin() && (*it).first != date)
				std::cerr << "Error: No data for that period of time => " << date
					<< std::endl;
			else if (it == m_data.end() && (*it).first == date)
				std::cout << date << " => " << amount << " = " << amount * (*it).second
					<< std::endl;
			else if (it != m_data.end())
			{
				--it;
				std::cout << date << " => " << amount << " = " << amount * (*it).second
					<< std::endl;
			}
		}
		else
			std::cerr << "Error: bad input => " << line << std::endl;
	}

	file.close();
}
