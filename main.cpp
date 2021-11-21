/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:50:38 by fhamel            #+#    #+#             */
/*   Updated: 2021/11/22 00:54:56 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <typeinfo>
#include <vector>
#include <string>

#include "vector.hpp"

template < class T >
void	printVal(T const &val) {
	std::cout << val << " ";
}

int main(void) {
	ft::vector<int>		vec1;
	std::vector<int>	vec2;

	for (int i = 0; i < 10; i++) {
		vec1.push_back(i);
		vec2.push_back(i);
	}

	ft::vector<int>::iterator	it1 = vec1.begin();
	std::vector<int>::iterator	it2 = vec2.begin();

	std::cout << it1.operator->() << std::endl;
	std::cout << it2.operator->() << std::endl;

	std::for_each(vec1.begin(), vec1.end(), printVal<int>);
	std::cout << std::endl;;
	std::for_each(vec2.begin(), vec2.end(), printVal<int>);
	std::cout << std::endl;;

	std::cout << vec1.capacity() << std::endl;
	std::cout << vec2.capacity() << std::endl;

	std::cout << vec1.max_size() << std::endl;
	std::cout << vec2.max_size() << std::endl;

	return 0;
}
