/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:43:26 by anikoyan          #+#    #+#             */
/*   Updated: 2025/10/22 17:41:16 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <vector>

static void binaryInsert(std::vector<int>& arr, int value)
{
	int left = 0;
	int right = arr.size();

	while (left < right)
	{
		int mid = (left + right) / 2;

		if (value < arr[mid])
			right = mid;
		else
			left = mid + 1;
	}

	arr.insert(arr.begin() + left, value);
}

void binaryInsert(std::list<int> &lst, int value)
{
    std::list<int>::iterator first = lst.begin();
    std::list<int>::iterator last = lst.end();

    while (first != last)
		{
        size_t dist = std::distance(first, last);
        std::list<int>::iterator mid = first;
        std::advance(mid, dist / 2);

        if (value < *mid)
            last = mid;
				else
				{
            first = mid;
            ++first;
        }
    }

    lst.insert(first, value);
}

static void generateOrderRecursive(int m, std::vector<int>& order, int start = 1)
{
	if (m == 0)
		return;

	if (m == 1)
	{
		order.push_back(start);
		return;
	}

	int left = (m + 1) / 2;
	int right = m - left;

	generateOrderRecursive(left - 1, order, start);

	order.push_back(start + left - 1);

	generateOrderRecursive(right, order, start + left);
}

static std::vector<int> generateInsertionOrder(int m)
{
	std::vector<int> order;

	generateOrderRecursive(m, order);
	return order;
}

void fordJohnsonSort(std::vector<int> &arr) {
    size_t n = arr.size();

    if (n <= 1)
        return;

    std::vector<int> larger;
    std::vector<int> smaller;

    for (size_t i = 0; i + 1 < n; i += 2)
		{
        if (arr[i] < arr[i + 1])
				{
            smaller.push_back(arr[i]);
            larger.push_back(arr[i + 1]);
        }
				else
				{
            smaller.push_back(arr[i + 1]);
            larger.push_back(arr[i]);
        }
    }

    bool hasLeftover = (n % 2 != 0);
    int leftover = 0;
    if (hasLeftover)
        leftover = arr.back();

    fordJohnsonSort(larger);

    std::vector<int> order = generateInsertionOrder(smaller.size());
    for (size_t i = 0; i < order.size(); ++i) {
        int idx = order[i] - 1;
        if (idx < (int)smaller.size())
            binaryInsert(larger, smaller[idx]);
    }

    if (hasLeftover)
        binaryInsert(larger, leftover);

    arr = larger;
}

void fordJohnsonSort(std::list<int> &lst) {
    if (lst.size() <= 1)
        return;

    std::list<int> larger;
    std::list<int> smaller;
    std::list<int>::iterator it = lst.begin();

    while (it != lst.end())
		{
        int first = *it;
        ++it;
        if (it != lst.end())
				{
            int second = *it;
            ++it;
            if (first < second)
						{
                smaller.push_back(first);
                larger.push_back(second);
            }
						else
						{
                smaller.push_back(second);
                larger.push_back(first);
            }
        }
				else
            larger.push_back(first);
    }

    fordJohnsonSort(larger);

    std::vector<int> order = generateInsertionOrder(smaller.size());
    for (size_t i = 0; i < order.size(); ++i) {
        int idx = order[i] - 1;
        std::list<int>::iterator sit = smaller.begin();
        std::advance(sit, idx);
        binaryInsert(larger, *sit);
    }

    lst = larger;
}
