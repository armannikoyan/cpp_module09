/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:44:39 by anikoyan          #+#    #+#             */
/*   Updated: 2025/10/22 18:10:26 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>

int main(int argc, char** argv)
{
	std::vector<int> vec;
	std::list<int> ls;

	if (argc < 2)
	{
		std::cout << "Error" << std::endl;
		return -1;
	}
	for (size_t i = 1; argv[i]; ++i)
	{
		size_t len = strlen(argv[i]);
		for (size_t j = 0; j < len; ++j)
		{
			if (!isdigit(argv[i][j]))
			{
				std::cerr << "Error" << std::endl;
				return -1;
			}
		}
		int num = atoi(argv[i]);
		vec.push_back(num);
		ls.push_back(num);
	}

	std::cout << "Before: ";
	std::vector<int>::iterator ibegin = vec.begin();
	std::vector<int>::iterator iend = vec.end();
	while (ibegin != iend)
		std::cout << *ibegin++ << " ";
	std::cout << std::endl;

	clock_t start = clock();
	fordJohnsonSort(vec);
	clock_t vec_duration = clock() - start;

	start = clock();
	fordJohnsonSort(ls);
	clock_t ls_duration = clock() - start;

	std::cout << "After: ";
	ibegin = vec.begin();
	iend = vec.end();
	while (ibegin != iend)
		std::cout << *ibegin++ << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << argc - 1
		<< " elements with std::vector : " << std::fixed << std::setprecision(5)
		<< (float)vec_duration / CLOCKS_PER_SEC << std::endl;

	std::cout << "Time to process a range of " << argc - 1
		<< " elements with std::list : " << std::fixed << std::setprecision(5)
		<< (float)ls_duration / CLOCKS_PER_SEC << std::endl;

	return 0;
}
