/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:11:05 by fhamel            #+#    #+#             */
/*   Updated: 2021/11/26 11:39:24 by fhamel           ###   ########.fr       */
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

struct yo {
	int	&getInt(void) const {
		return *this->myInt_;
	}

	private:
		int	*myInt_;
};

int main(void) {
	int* const	test = new int(42);
	std::cout << test << ": " << *test << std::endl;
	*test = 21;
	std::cout << test << ": " << *test << std::endl;
	return 0;
}
