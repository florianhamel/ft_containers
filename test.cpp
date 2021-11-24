/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:11:05 by fhamel            #+#    #+#             */
/*   Updated: 2021/11/24 15:23:31 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstddef>
#include <memory>

#include "base_rai.hpp"

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
	ft::base_rai<int>	test;
	return 0;
}
