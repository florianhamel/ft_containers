/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:50:38 by fhamel            #+#    #+#             */
/*   Updated: 2021/12/22 18:35:30 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <typeinfo>
#include <vector>
#include <list>
#include <deque>
#include <string>

#include "vector.hpp"

template < class T >
void	printVal(T const &val) {
	std::cout << val << " ";
}

template <class T>
class my_input_iter : public ft::base_iterator<std::input_iterator_tag, T> {};

template <class T>
class my_forward_iter: public ft::base_iterator<std::forward_iterator_tag, T> {};

/********************************/
/***         ITERATORS        ***/
/********************************/

void	ft_iterator()
{
	ft::vector<int>	vec;

	for (int i = 0; i < 10; ++i) {
		vec.push_back(i);
	}
	ft::vector<int>::iterator	it = vec.begin();
	ft::vector<int>::iterator	ite = vec.end();
	std::cout << (it == ite) << std::endl;
	std::cout << (it != ite) << std::endl;
	std::cout << *it << std::endl;
	std::cout << it.operator->() << std::endl;
	std::cout << *(it++) << std::endl;
	std::cout << *(++it) << std::endl;
	std::cout << *(it--) << std::endl;
	std::cout << *(--it) << std::endl;
	std::cout << *(ite - 5) << std::endl;
	std::cout << *(it + 2) << std::endl;
	std::cout << *(2 + it) << std::endl;
	std::cout << ite - it << std::endl;
	std::cout << (it < ite) << std::endl;
	std::cout << (it > ite) << std::endl;
	std::cout << (it <= ite) << std::endl;
	std::cout << (it >= ite) << std::endl;
	std::cout << *(it += 3) << std::endl;
	std::cout << *(it -= 3) << std::endl;
	it[3] = 42;
	std::cout << it[3] << std::endl;
	std::for_each(it, ite, printVal<int>);
}

void	ft_const_iterator()
{
	ft::vector<int>	vec;

	for (int i = 0; i < 10; ++i) {
		vec.push_back(i);
	}
	ft::vector<int>::const_iterator	it = vec.begin();
	ft::vector<int>::const_iterator	ite = vec.end();
	std::cout << (it == ite) << std::endl;
	std::cout << (it != ite) << std::endl;
	std::cout << *it << std::endl;
	std::cout << it.operator->() << std::endl;
	std::cout << *(it++) << std::endl;
	std::cout << *(++it) << std::endl;
	std::cout << *(it--) << std::endl;
	std::cout << *(--it) << std::endl;
	std::cout << *(ite - 5) << std::endl;
	std::cout << *(it + 2) << std::endl;
	std::cout << *(2 + it) << std::endl;
	std::cout << ite - it << std::endl;
	std::cout << (it < ite) << std::endl;
	std::cout << (it > ite) << std::endl;
	std::cout << (it <= ite) << std::endl;
	std::cout << (it >= ite) << std::endl;
	std::cout << *(it += 3) << std::endl;
	std::cout << *(it -= 3) << std::endl;
	// it[3] = 42;
	std::cout << it[3] << std::endl;
	std::for_each(it, ite, printVal<int>);
}

void	ft_reverse_iterator()
{
	ft::vector<int>	vec;

	for (int i = 0; i < 10; ++i) {
		vec.push_back(i);
	}
	ft::vector<int>::reverse_iterator	it = vec.rbegin();
	ft::vector<int>::reverse_iterator	ite = vec.rend();
	std::cout << (it == ite) << std::endl;
	std::cout << (it != ite) << std::endl;
	std::cout << *it << std::endl;
	std::cout << it.operator->() << std::endl;
	std::cout << *(it++) << std::endl;
	std::cout << *(++it) << std::endl;
	std::cout << *(it--) << std::endl;
	std::cout << *(--it) << std::endl;
	std::cout << *(ite - 5) << std::endl;
	std::cout << *(it + 2) << std::endl;
	std::cout << *(2 + it) << std::endl;
	std::cout << ite - it << std::endl;
	std::cout << (it < ite) << std::endl;
	std::cout << (it > ite) << std::endl;
	std::cout << (it <= ite) << std::endl;
	std::cout << (it >= ite) << std::endl;
	std::cout << *(it += 3) << std::endl;
	std::cout << *(it -= 3) << std::endl;
	it[3] = 42;
	std::cout << it[3] << std::endl;
	std::for_each(it, ite, printVal<int>);
}

void	ft_const_reverse_iterator()
{
	ft::vector<int>	vec;

	for (int i = 0; i < 10; ++i) {
		vec.push_back(i);
	}
	ft::vector<int>::const_reverse_iterator	it = vec.rbegin();
	ft::vector<int>::const_reverse_iterator	ite = vec.rend();
	std::cout << (it == ite) << std::endl;
	std::cout << (it != ite) << std::endl;
	std::cout << *it << std::endl;
	std::cout << it.operator->() << std::endl;
	std::cout << *(it++) << std::endl;
	std::cout << *(++it) << std::endl;
	std::cout << *(it--) << std::endl;
	std::cout << *(--it) << std::endl;
	std::cout << *(ite - 5) << std::endl;
	std::cout << *(it + 2) << std::endl;
	std::cout << *(2 + it) << std::endl;
	std::cout << ite - it << std::endl;
	std::cout << (it < ite) << std::endl;
	std::cout << (it > ite) << std::endl;
	std::cout << (it <= ite) << std::endl;
	std::cout << (it >= ite) << std::endl;
	std::cout << *(it += 3) << std::endl;
	std::cout << *(it -= 3) << std::endl;
	// it[3] = 42;
	std::cout << it[3] << std::endl;
	std::for_each(it, ite, printVal<int>);
}

/********************************/
/***         CAPACITY         ***/
/********************************/

void	ft_size()
{
	ft::vector<int>	vec1;
	ft::vector<int>	vec2(20, 42);
	ft::vector<int>	vec3;

	for (int i = 0; i < 10; ++i) {
		vec3.push_back(i * i);
	}
	std::cout << "size: " << vec1.size() << std::endl;
	std::cout << "size: " << vec2.size() << std::endl;
	std::cout << "size: " << vec3.size() << std::endl;
}

void	ft_max_size()
{
	ft::vector<float>	vec;
	std::cout << vec.max_size() << std::endl;
}

void	ft_resize()
{
	ft::vector<int>	vec(10, 42);
	try {
		vec.resize(-1);
	}
	catch (std::length_error &e) {
		std::cout << e.what() << std::endl;
		std::for_each(vec.begin(), vec.end(), printVal<int>); std::cout << std::endl;
	}
	vec.resize(3);
	std::for_each(vec.begin(), vec.end(), printVal<int>); std::cout << std::endl;
}

void	ft_capacity()
{
	ft::vector<int>	vec1;
	ft::vector<int>	vec2(20, 42);
	ft::vector<int>	vec3;

	for (int i = 0; i < 10; ++i) {
		vec3.push_back(i * i);
	}
	std::cout << "capacity: " << vec1.size() << std::endl;
	std::cout << "capacity: " << vec2.size() << std::endl;
	std::cout << "capacity: " << vec3.size() << std::endl;
}

void	ft_empty()
{
	ft::vector<int>	vec;
	std::cout << vec.empty() << std::endl;
	vec.push_back(42);
	std::cout << vec.empty() << std::endl;
}

void	ft_reserve()
{
	ft::vector<int>	vec(10, 42);
	try {
		vec.reserve(-1);
	}
	catch (std::length_error &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "capacity: " << vec.size() << std::endl;
	std::cout << vec.begin().base() << std::endl;
	vec.reserve(7);
	std::cout << "capacity: " << vec.size() << std::endl;
	std::cout << vec.begin().base() << std::endl;
	vec.reserve(20);
	std::cout << "capacity: " << vec.size() << std::endl;
	std::cout << vec.begin().base() << std::endl;
}

/********************************/
/***      ELEMENT ACCESS      ***/
/********************************/

void	ft_operator_at()
{
	ft::vector<int>	vec(10, 42);
	std::cout << vec[0] << " | " << vec[vec.size() - 1] << std::endl;
	vec[4] = 21;
	std::for_each(vec.begin(), vec.end(), printVal<int>); std::cout << std::endl;
}

void	ft_operator_at_const()
{
	ft::vector<const int>	vec(10, 42);
	std::cout << vec[0] << " | " << vec[vec.size() - 1] << std::endl;
}

void	ft_at()
{
	ft::vector<int>	vec(10, 42);
	try {
		std::cout << vec.at(12) << std::endl;
	}
	catch (std::out_of_range &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << vec.at(-1) << std::endl;
	}
	catch (std::out_of_range &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << vec.at(0) << " | " << vec.at(vec.size() - 1) << std::endl;
	vec.at(4) = 21;
	std::for_each(vec.begin(), vec.end(), printVal<int>); std::cout << std::endl;
}

void	ft_at_const()
{
	ft::vector<const int>	vec(10, 42);
	try {
		std::cout << vec.at(12) << std::endl;
	}
	catch (std::out_of_range &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << vec.at(-1) << std::endl;
	}
	catch (std::out_of_range &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << vec.at(0) << " | " << vec.at(vec.size() - 1) << std::endl;
}

void	ft_front()
{
	std::vector<int>	vec;
	std::cout << vec.front() << std::endl;
	vec.push_back(42);
	vec.push_back(21);
	std::cout << vec.front() << std::endl;
}

void	ft_front_const()
{
	std::vector<const int>	vec;
	std::cout << vec.front() << std::endl;
	vec.push_back(42);
	vec.push_back(21);
	std::cout << vec.front() << std::endl;
}

void	ft_back()
{
	std::vector<int>	vec;
	std::cout << vec.back() << std::endl;
	vec.push_back(42);
	vec.push_back(21);
	std::cout << vec.back() << std::endl;
}

void	ft_back_const()
{
	std::vector<const int>	vec;
	std::cout << vec.back() << std::endl;
	vec.push_back(42);
	vec.push_back(21);
	std::cout << vec.back() << std::endl;
}

/********************************/
/***         MODIFIERS        ***/
/********************************/

void	ft_insert_single_elem()
{
	std::cout << "/--- Single Element ---/" << std::endl;

	ft::vector<int> vec;

	ft::vector<int>::iterator it0 = vec.insert(vec.begin(), 42);
	std::cout << "ret it0 insert: " << *it0 << std::endl;
	std::cout << "print vec: ";
	std::for_each(vec.begin(), vec.end(), printVal<int>);
	std::cout << std::endl;
	std::cout << "size: " << vec.size() << std::endl;
	std::cout << "capacity: " << vec.capacity() << std::endl;

	ft::vector<int>::iterator it1 = vec.insert(vec.begin() + 1, 21);
	ft::vector<int>::iterator it2 = vec.insert(vec.begin() + 1, 12);
	std::cout << "ret it1 insert: " << *it1 << std::endl;
	std::cout << "ret it2 insert: " << *it2 << std::endl;
	std::cout << "print vec: " << std::endl;
	std::for_each(vec.begin(), vec.end(), printVal<int>);
	std::cout << std::endl;
	std::cout << "size: " << vec.size() << std::endl;
	std::cout << "capacity: " << vec.capacity() << std::endl;

	ft::vector<int>::iterator it3 = vec.insert(vec.begin() + 2, 24);
	std::cout << "ret it3 insert: " << *it3 << std::endl;
	std::cout << "print vec: " << std::endl;
	std::for_each(vec.begin(), vec.end(), printVal<int>);
	std::cout << std::endl;
	std::cout << "size: " << vec.size() << std::endl;
	std::cout << "capacity: " << vec.capacity() << std::endl;
}

void	ft_insert_fill()
{
	std::cout << "/--- Fill ---/" << std::endl;

	ft::vector<int> vec;

	std::cout << "test1\n";
	vec.insert(vec.begin(), 3, 42);
	std::cout << "test2\n";
	std::cout << "print vec: ";
	std::for_each(vec.begin(), vec.end(), printVal<int>);
	std::cout << std::endl;
	std::cout << "size: " << vec.size() << std::endl;
	std::cout << "capacity: " << vec.capacity() << std::endl;

	vec.insert(vec.begin() + 1, 5, 21);
	vec.insert(vec.begin() + 1, 2, 12);
	std::cout << "print vec: " << std::endl;
	std::for_each(vec.begin(), vec.end(), printVal<int>);
	std::cout << std::endl;
	std::cout << "size: " << vec.size() << std::endl;
	std::cout << "capacity: " << vec.capacity() << std::endl;

	vec.insert(vec.begin() + 2, 4, 24);
	std::cout << "print vec: " << std::endl;
	std::for_each(vec.begin(), vec.end(), printVal<int>);
	std::cout << std::endl;
	std::cout << "size: " << vec.size() << std::endl;
	std::cout << "capacity: " << vec.capacity() << std::endl;
}

void	ft_insert_range()
{
	std::cout << "/--- Range ---/" << std::endl;
	
	ft::vector<int> 	vec;

	std::list<int>		lst(3, 42);
	std::deque<int>		dq(5, 21);
	std::vector<int>	vec_(2, 12);
	std::list<int>		lst_(4, 24);

	std::cout << "test1\n";
	vec.insert(vec.begin(), lst.begin(), lst.end());
	std::cout << "test2\n";
	std::cout << "print vec: ";
	std::for_each(vec.begin(), vec.end(), printVal<int>);
	std::cout << std::endl;
	std::cout << "size: " << vec.size() << std::endl;
	std::cout << "capacity: " << vec.capacity() << std::endl;

	vec.insert(vec.begin() + 1, dq.begin(), dq.end());
	vec.insert(vec.begin() + 1, vec_.begin(), vec_.end());
	std::cout << "print vec: " << std::endl;
	std::for_each(vec.begin(), vec.end(), printVal<int>);
	std::cout << std::endl;
	std::cout << "size: " << vec.size() << std::endl;
	std::cout << "capacity: " << vec.capacity() << std::endl;

	vec.insert(vec.begin() + 2, lst_.begin(), lst_.end());
	std::cout << "print vec: " << std::endl;
	std::for_each(vec.begin(), vec.end(), printVal<int>);
	std::cout << std::endl;
	std::cout << "size: " << vec.size() << std::endl;
	std::cout << "capacity: " << vec.capacity() << std::endl;	
}

void	ft_erase_single_elem()
{
	std::cout << "/--- Single Element ---/" << std::endl;

	ft::vector<int>	vec;

	for (int i = 0; i < 10; ++i) {
		vec.push_back(i * i);
	}
	std::for_each(vec.begin(), vec.end(), printVal<int>);
	std::cout << "\n----------\n";
	ft::vector<int>::iterator	it = vec.erase(vec.begin() + 3);
	std::for_each(vec.begin(), vec.end(), printVal<int>); std::cout << std::endl;
	std::cout << "ret value: " << *it << std::endl;
	std::cout << "ret index: " << it - vec.begin() << std::endl;
}

void	ft_erase_range()
{
	std::cout << "/--- Range ---/" << std::endl;
	ft::vector<int>	vec;

	for (int i = 0; i < 10; ++i) {
		vec.push_back(i * i);
	}
	std::for_each(vec.begin(), vec.end(), printVal<int>);
	std::cout << "\n----------\n";
	ft::vector<int>::iterator	it = vec.erase(vec.begin() + 2, vec.begin() + 5);
	std::for_each(vec.begin(), vec.end(), printVal<int>); std::cout << std::endl;
	std::cout << "ret value: " << *it << std::endl;
	std::cout << "ret index: " << it - vec.begin() << std::endl;
}

void	ft_swap()
{
	ft::vector<int>	vec1(7134, 42);
	ft::vector<int>	vec2(42345, 21);

	std::cout << vec1.begin().base() << std::endl;
	std::cout << vec2.begin().base() << std::endl;
	std::for_each(vec1.begin(), vec1.end(), printVal<int>); std::cout << std::endl;
	std::for_each(vec2.begin(), vec2.end(), printVal<int>); std::cout << std::endl;
	
	vec1.swap(vec2);

	std::cout << vec1.begin().base() << std::endl;
	std::cout << vec2.begin().base() << std::endl;
	std::for_each(vec1.begin(), vec1.end(), printVal<int>); std::cout << std::endl;
	std::for_each(vec2.begin(), vec2.end(), printVal<int>); std::cout << std::endl;
}

int main(void) {

	/********************************/
	/***        ITERATORS         ***/
	/********************************/

	ft_iterator();
	ft_const_iterator();
	ft_reverse_iterator();
	ft_const_reverse_iterator();

	/********************************/
	/***         CAPACITY         ***/
	/********************************/

	/* size */
	ft_size();

	/* max_size */
	ft_max_size();

	/* resize */
	ft_resize();	
	
	/* capacity */
	ft_capacity();

	/* ft_empty */
	ft_empty();

	/* ft_reserve */
	ft_reserve();

	/********************************/
	/***      ELEMENT ACCESS      ***/
	/********************************/

	/* operator[] */
	ft_operator_at();
	ft_operator_at_const();
	
	/* at */
	ft_at();
	ft_at_const();

	/* front */
	ft_front();
	ft_front_const();

	/* back */
	ft_back();
	ft_back_const();

	/********************************/
	/***         MODIFIERS        ***/
	/********************************/

	/* insert */
	ft_insert_single_elem();
	ft_insert_fill();
	ft_insert_range();

	/* erase */
	ft_erase_single_elem();
	ft_erase_range();

	/* swap */
	ft_swap();

	return 0;
}
