/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:50:38 by fhamel            #+#    #+#             */
/*   Updated: 2021/11/26 00:55:03 by fhamel           ###   ########.fr       */
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
{
	ft::vector<int>	vec;

	for (int i = 0; i < 10; i++) {
		vec.push_back(i * i);
	}
	
	ft::vector<int>::iterator	it = vec.begin();
	std::cout << *it << std::endl;

	it = it + 4;
	std::cout << *it << std::endl;
	it = 4 + it;
	std::cout << *it << std::endl;

	*it = 12;
	std::cout << *it << std::endl;

	// std::vector<int>	vec_;

	// for (int i = 0; i < 10; i++) {
	// 	vec_.push_back(i * i);
	// }
	
	// std::vector<int>::const_iterator	it_ = vec_.begin();
	// std::cout << *it_ << std::endl;

	// it_ = it_ + 4;
	// std::cout << *it_ << std::endl;
	// it_ = 4 + it_;
	// std::cout << *it_ << std::endl;

}

// {	std::vector<int>	vec_(1);
// 	vec_[0] = 42;
// 	std::vector<int>::const_iterator	it1_;
// 	std::vector<int>::const_iterator	it2_ = vec_.begin();

// 	it1_ = it2_;
// 	std::cout << *it1_ << std::endl;

// 	ft::vector<int>		vec(1);
// 	vec[0] = 42;
// 	ft::vector<int>::const_iterator	it1;
// 	ft::vector<int>::const_iterator	it2 = vec.begin();

// 	it1 = it2;
// 	std::cout << *it1 << std::endl;}

	// ft::vector<int>		vec1;
	// std::vector<int>	vec2;

	// for (int i = 0; i < 10; i++) {
	// 	vec1.push_back(i);
	// 	vec2.push_back(i);
	// }

	// ft::vector<int>::iterator	it1 = vec1.begin();
	// std::vector<int>::iterator	it2 = vec2.begin();

	// ft::vector<int>::const_iterator		it3 = vec1.begin();
	// std::vector<int>::const_iterator	it4 = vec2.begin();

	// *it1 = 42;
	// *it2 = 42;

	// std::cout << *it1++ << std::endl;
	// std::cout << *it2++ << std::endl;
 
	// std::cout << *it1 << std::endl;
	// std::cout << *it2 << std::endl;

	// std::cout << (*it1-- == *it2--) << std::endl;
	// std::cout << *it1 << std::endl;
	// std::cout << *it2 << std::endl;	

	// std::cout << it1.operator->() << std::endl;
	// std::cout << it2.operator->() << std::endl;

	// std::for_each(vec1.begin(), vec1.end(), printVal<int>);
	// std::cout << std::endl;;
	// std::for_each(vec2.begin(), vec2.end(), printVal<int>);
	// std::cout << std::endl;;

	// std::cout << vec1.capacity() << std::endl;
	// std::cout << vec2.capacity() << std::endl;

	// std::cout << vec1.max_size() << std::endl;
	// std::cout << vec2.max_size() << std::endl;

	return 0;
}
