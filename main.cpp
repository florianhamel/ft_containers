/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:50:38 by fhamel            #+#    #+#             */
/*   Updated: 2021/12/07 20:16:41 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <typeinfo>
#include <vector>
#include <string>

#include "vector.hpp"

template < class T >
void	printVal(T const &val) {
	std::cout << val << std::endl;
}

int main(void) {
	{
		ft::vector<int>	vec;

		for (int i = 0; i < 8; i++) {
			vec.push_back(i * i);
		}

		vec.insert(vec.begin() + 2, 3, 42);
		std::for_each(vec.begin(), vec.end(), printVal<int>);
		std::cout << "capacity: " << vec.capacity() << std::endl;
		std::cout << "size: " << vec.size() << std::endl;
	}

	std::cout << "----------" << std::endl;

	{
		std::vector<int>	vec;

		for (int i = 0; i < 8; i++) {
			vec.push_back(i * i);
		}

		vec.insert(vec.begin() + 2, 3, 42);
		std::for_each(vec.begin(), vec.end(), printVal<int>);
		std::cout << "capacity: " << vec.capacity() << std::endl;
		std::cout << "size: " << vec.size() << std::endl;
	}
	
	return 0;
}
