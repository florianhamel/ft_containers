/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:11:05 by fhamel            #+#    #+#             */
/*   Updated: 2021/11/21 18:12:47 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstddef>
#include <memory>

template <class T>
void	printVec(const T &val) {
	std::cout << val << std::endl;
}

template < class T >
struct Abc {
	T	&foo(void) const {
		T	bar;
		return bar;
	}
};

int main(void) {
	std::vector<int>	test;

	test.push_back(42);
	std::cout << *(test.end() - 1) << std::endl;
	return 0;
}
