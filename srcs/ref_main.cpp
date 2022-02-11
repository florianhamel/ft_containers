/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ref_main.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:50:38 by fhamel            #+#    #+#             */
/*   Updated: 2022/02/11 03:49:53 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <iostream>
#include <typeinfo>
#include <vector>
#include <stack>
#include <list>
#include <deque>
#include <string>
#include <map>

#include <time.h>
#include <sys/time.h>
#include <stdlib.h>

#include "vector.hpp"
#include "stack.hpp"
#include "map.hpp"

template < class T >
void	printVal(T const &val) {
	std::cout << val << " ";
}

template <class T>
struct foo {
	
	foo(void) : var1(), var2(), var3() {}
	
	T	var1;
	T	var2;
	T	var3;

};

/*----------- VECTOR -----------*/

/********************************/
/***         ITERATORS        ***/
/********************************/

void	ft_iterator()
{
	std::cout << "\n----- ft_iterator() -----\n" << std::endl;
	std::vector<int>	vec;

	for (int i = 0; i < 10; ++i) {
		vec.push_back(i);
	}
	std::vector<int>::iterator	it = vec.begin();
	std::vector<int>::iterator	ite = vec.end();
	std::cout << (it == ite) << std::endl;
	std::cout << (it != ite) << std::endl;
	std::cout << *it << std::endl;
	it.operator->();
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
	std::cout << "\n----- ft_const_iterator() -----\n" << std::endl;
	std::vector<int>	vec;

	for (int i = 0; i < 10; ++i) {
		vec.push_back(i);
	}
	std::vector<int>::const_iterator	it = vec.begin();
	std::vector<int>::const_iterator	ite = vec.end();
	std::cout << (it == ite) << std::endl;
	std::cout << (it != ite) << std::endl;
	std::cout << *it << std::endl;
	it.operator->();
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
	std::cout << "\n----- ft_reverse_iterator() -----\n" << std::endl;
	std::vector<int>	vec;

	for (int i = 0; i < 10; ++i) {
		vec.push_back(i);
	}
	std::vector<int>::reverse_iterator	it = vec.rbegin();
	std::vector<int>::reverse_iterator	ite = vec.rend();
	std::cout << (it == ite) << std::endl;
	std::cout << (it != ite) << std::endl;
	std::cout << *it << std::endl;
	it.operator->();
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
	std::cout << "\n----- ft_const_reverse_iterator() -----\n" << std::endl;
	std::vector<int>	vec;

	for (int i = 0; i < 10; ++i) {
		vec.push_back(i);
	}
	std::vector<int>::const_reverse_iterator	it = vec.rbegin();
	std::vector<int>::const_reverse_iterator	ite = vec.rend();
	std::cout << (it == ite) << std::endl;
	std::cout << (it != ite) << std::endl;
	std::cout << *it << std::endl;
	it.operator->();
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
	std::for_each(it, ite, printVal<int>); std::cout << std::endl;
}

/********************************/
/***         CAPACITY         ***/
/********************************/

void	ft_size()
{
	std::cout << "\n----- ft_size() -----\n" << std::endl;
	std::vector<int>	vec1;
	std::vector<int>	vec2(20, 42);
	std::vector<int>	vec3;

	for (int i = 0; i < 10; ++i) {
		vec3.push_back(i * i);
	}
	std::cout << "size: " << vec1.size() << std::endl;
	std::cout << "size: " << vec2.size() << std::endl;
	std::cout << "size: " << vec3.size() << std::endl;
}

void	ft_max_size()
{
	std::cout << "\n----- ft_max_size() -----\n" << std::endl;
	std::vector<float>	vec;
	std::cout << vec.max_size() << std::endl;
}

void	ft_resize()
{
	std::cout << "\n----- ft_resize() -----\n" << std::endl;
	std::vector<int>	vec(10, 42);
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
	std::cout << "\n----- ft_capacity() -----\n" << std::endl;
	std::vector<int>	vec1;
	std::vector<int>	vec2(20, 42);
	std::vector<int>	vec3;

	for (int i = 0; i < 10; ++i) {
		vec3.push_back(i * i);
	}
	std::cout << "capacity: " << vec1.size() << std::endl;
	std::cout << "capacity: " << vec2.size() << std::endl;
	std::cout << "capacity: " << vec3.size() << std::endl;
}

void	ft_empty()
{
	std::cout << "\n----- ft_empty() -----\n" << std::endl;
	std::vector<int>	vec;
	std::cout << vec.empty() << std::endl;
	vec.push_back(42);
	std::cout << vec.empty() << std::endl;
}

void	ft_reserve()
{
	std::cout << "\n----- ft_reserve() -----\n" << std::endl;
	std::vector<int>	vec(10, 42);
	try {
		vec.reserve(-1);
	}
	catch (std::length_error &e) {
		std::cout << e.what() << std::endl;
	}
	int	*ptr = vec.begin().base();
	std::cout << "capacity: " << vec.size() << std::endl;
	std::cout << (ptr == vec.begin().base()) << std::endl;
	vec.reserve(7);
	std::cout << "capacity: " << vec.size() << std::endl;
	std::cout << (ptr == vec.begin().base()) << std::endl;
	vec.reserve(20);
	std::cout << "capacity: " << vec.size() << std::endl;
	std::cout << (ptr == vec.begin().base()) << std::endl;
}

/********************************/
/***   RELATIONAL OPERATORS   ***/
/********************************/

void	ft_relational_operators()
{
	std::cout << "\n----- ft_relational_operators() -----\n" << std::endl;
	{
		std::vector<int>	vec1(10, 42);
		std::vector<int>	vec2(10, 42);
		vec2[7] = 41;
		std::cout << (vec1 == vec2) << std::endl;
		std::cout << (vec1 != vec2) << std::endl;
		std::cout << (vec1 < vec2) << std::endl;
		std::cout << (vec1 <= vec2) << std::endl;
		std::cout << (vec1 > vec2) << std::endl;
		std::cout << (vec1 >= vec2) << std::endl;
	}
	{
		std::vector<int>	vec1(10, 42);
		std::vector<int>	vec2(11, 42);
		std::cout << (vec1 == vec2) << std::endl;
		std::cout << (vec1 != vec2) << std::endl;
		std::cout << (vec1 < vec2) << std::endl;
		std::cout << (vec1 <= vec2) << std::endl;
		std::cout << (vec1 > vec2) << std::endl;
		std::cout << (vec1 >= vec2) << std::endl;
	}
	{
		std::vector<int>	vec1(10, 42);
		std::vector<int>	vec2(10, 42);
		std::cout << (vec1 == vec2) << std::endl;
		std::cout << (vec1 != vec2) << std::endl;
		std::cout << (vec1 < vec2) << std::endl;
		std::cout << (vec1 <= vec2) << std::endl;
		std::cout << (vec1 > vec2) << std::endl;
		std::cout << (vec1 >= vec2) << std::endl;
	}
}

/********************************/
/***      ELEMENT ACCESS      ***/
/********************************/

void	ft_operator_at()
{
	std::cout << "\n----- ft_operator_at() -----\n" << std::endl;
	std::vector<int>	vec(10, 42);
	std::cout << vec[0] << " | " << vec[vec.size() - 1] << std::endl;
	vec[4] = 21;
	std::for_each(vec.begin(), vec.end(), printVal<int>); std::cout << std::endl;
}

void	ft_operator_at_const()
{
	std::cout << "\n----- ft_operator_at_const() -----\n" << std::endl;
	const std::vector<int>	vec(10, 42);
	std::cout << vec[0] << " | " << vec[vec.size() - 1] << std::endl;
	std::for_each(vec.begin(), vec.end(), printVal<int>); std::cout << std::endl;
}

void	ft_at()
{
	std::cout << "\n----- ft_at() -----\n" << std::endl;
	std::vector<int>	vec(10, 42);
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
	std::cout << "\n----- ft_at_const() -----\n" << std::endl;
	const std::vector<int>	vec(10, 42);
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
	std::for_each(vec.begin(), vec.end(), printVal<int>); std::cout << std::endl;
}

void	ft_front()
{
	std::cout << "\n----- ft_front() -----\n" << std::endl;
	std::vector<int>	vec;
	vec.push_back(42);
	vec.push_back(21);
	std::cout << vec.front() << std::endl;
}

void	ft_front_const()
{
	std::cout << "\n----- ft_front_const() -----\n" << std::endl;
	const std::vector<int>	vec(10, 42);
	std::cout << vec.front() << std::endl;
}

void	ft_back()
{
	std::cout << "\n----- ft_back() -----\n" << std::endl;
	std::vector<int>	vec;
	vec.push_back(42);
	vec.push_back(21);
	std::cout << vec.back() << std::endl;
}

void	ft_back_const()
{
	std::cout << "\n----- ft_back_const() -----\n" << std::endl;
	const std::vector<int>	vec(10, 42);
	std::cout << vec.back() << std::endl;
}

/********************************/
/***         MODIFIERS        ***/
/********************************/

void	ft_assign_range()
{
	std::cout << "\n----- ft_assign_range() -----\n" << std::endl;
	
	std::vector<int>	vec;

	vec.assign(10, 42);
	std::for_each(vec.begin(), vec.end(), printVal<int>); std::cout << std::endl;

	vec.assign(5, 21);
	std::for_each(vec.begin(), vec.end(), printVal<int>); std::cout << std::endl;
}

void	ft_assign_fill()
{
	std::cout << "\n----- ft_assign_fill() -----\n" << std::endl;

	std::vector<int>		vec;

	std::list<int>		lst(3, 42);
	std::deque<int>		dq(5, 21);
	std::vector<int>	vec_(2, 12);
	std::list<int>		lst_(4, 24);

	vec.assign(lst.begin(), lst.end());
	std::for_each(vec.begin(), vec.end(), printVal<int>); std::cout << std::endl;
	vec.assign(dq.begin(), dq.end());
	std::for_each(vec.begin(), vec.end(), printVal<int>); std::cout << std::endl;
	vec.assign(vec_.begin(), vec_.end());
	std::for_each(vec.begin(), vec.end(), printVal<int>); std::cout << std::endl;
	vec.assign(lst_.begin(), lst_.end());
	std::for_each(vec.begin(), vec.end(), printVal<int>); std::cout << std::endl;
}

void	ft_insert_single_elem()
{
	std::cout << "\n----- ft_insert_single_elem() -----\n" << std::endl;
	std::vector<int> vec;

	std::vector<int>::iterator it0 = vec.insert(vec.begin(), 42);
	std::cout << "ret it0 insert: " << *it0 << std::endl;
	std::for_each(vec.begin(), vec.end(), printVal<int>); std::cout << std::endl;
	std::cout << "size: " << vec.size() << std::endl;
	std::cout << "capacity: " << vec.capacity() << std::endl;

	std::vector<int>::iterator it1 = vec.insert(vec.begin() + 1, 21);
	std::cout << "ret it1 insert: " << *it1 << std::endl;
	std::for_each(vec.begin(), vec.end(), printVal<int>); std::cout << std::endl;
	std::cout << "size: " << vec.size() << std::endl;
	std::cout << "capacity: " << vec.capacity() << std::endl;

	std::vector<int>::iterator it3 = vec.insert(vec.begin() + 2, 24);
	std::cout << "ret it3 insert: " << *it3 << std::endl;
	std::for_each(vec.begin(), vec.end(), printVal<int>);
	std::cout << std::endl;
	std::cout << "size: " << vec.size() << std::endl;
	std::cout << "capacity: " << vec.capacity() << std::endl;
}

void	ft_insert_fill()
{
	std::cout << "\n----- ft_insert_fill() -----\n" << std::endl;
	std::vector<int> vec;

	vec.insert(vec.begin(), 3, 42);
	std::cout << "print vec: ";
	std::for_each(vec.begin(), vec.end(), printVal<int>); std::cout << std::endl;
	std::cout << "size: " << vec.size() << std::endl;
	std::cout << "capacity: " << vec.capacity() << std::endl;

	vec.insert(vec.begin() + 1, 5, 21);
	vec.insert(vec.begin() + 1, 2, 12);
	std::for_each(vec.begin(), vec.end(), printVal<int>); std::cout << std::endl;
	std::cout << "size: " << vec.size() << std::endl;
	std::cout << "capacity: " << vec.capacity() << std::endl;

	vec.insert(vec.begin() + 2, 4, 24);
	std::for_each(vec.begin(), vec.end(), printVal<int>); std::cout << std::endl;
	std::cout << "size: " << vec.size() << std::endl;
	std::cout << "capacity: " << vec.capacity() << std::endl;
}

void	ft_insert_range()
{
	std::cout << "\n----- ft_insert_range() -----\n" << std::endl;
	std::vector<int> 	vec;

	std::list<int>		lst(3, 42);
	std::deque<int>		dq(5, 21);
	std::vector<int>	vec_(2, 12);
	std::list<int>		lst_(4, 24);

	vec.insert(vec.begin(), lst.begin(), lst.end());
	std::for_each(vec.begin(), vec.end(), printVal<int>); std::cout << std::endl;
	std::cout << "size: " << vec.size() << std::endl;
	std::cout << "capacity: " << vec.capacity() << std::endl;

	vec.insert(vec.begin() + 1, dq.begin(), dq.end());
	vec.insert(vec.begin() + 1, vec_.begin(), vec_.end());
	std::for_each(vec.begin(), vec.end(), printVal<int>); std::cout << std::endl;
	std::cout << "size: " << vec.size() << std::endl;
	std::cout << "capacity: " << vec.capacity() << std::endl;

	vec.insert(vec.begin() + 2, lst_.begin(), lst_.end());
	std::for_each(vec.begin(), vec.end(), printVal<int>); std::cout << std::endl;
	std::cout << "size: " << vec.size() << std::endl;
	std::cout << "capacity: " << vec.capacity() << std::endl;	
}

void	ft_erase_single_elem()
{
	std::cout << "\n----- ft_erase_single_elem() -----\n" << std::endl;
	std::vector<int>	vec;

	for (int i = 0; i < 10; ++i) {
		vec.push_back(i * i);
	}
	std::for_each(vec.begin(), vec.end(), printVal<int>);

	std::vector<int>::iterator	it = vec.erase(vec.begin() + 3);

	std::for_each(vec.begin(), vec.end(), printVal<int>); std::cout << std::endl;
	std::cout << "ret value: " << *it << std::endl;
	std::cout << "ret index: " << it - vec.begin() << std::endl;
}

void	ft_erase_range()
{
	std::cout << "\n----- ft_erase_range() -----\n" << std::endl;
	std::vector<int>	vec;

	for (int i = 0; i < 10; ++i) {
		vec.push_back(i * i);
	}
	std::for_each(vec.begin(), vec.end(), printVal<int>);

	std::vector<int>::iterator	it = vec.erase(vec.begin() + 2, vec.begin() + 5);

	std::for_each(vec.begin(), vec.end(), printVal<int>); std::cout << std::endl;
	std::cout << "ret value: " << *it << std::endl;
	std::cout << "ret index: " << it - vec.begin() << std::endl;
}

void	ft_swap()
{
	std::cout << "\n----- ft_swap() -----\n" << std::endl;
	std::vector<int>	vec1(8, 42);
	std::vector<int>	vec2(12, 21);

	int	*ptr1 = vec1.begin().base();
	int	*ptr2 = vec2.begin().base();

	std::for_each(vec1.begin(), vec1.end(), printVal<int>); std::cout << std::endl;
	std::for_each(vec2.begin(), vec2.end(), printVal<int>); std::cout << std::endl;
	
	vec1.swap(vec2);

	std::cout << (ptr1 == vec2.begin().base()) << std::endl;
	std::cout << (ptr2 == vec1.begin().base()) << std::endl;
	std::for_each(vec1.begin(), vec1.end(), printVal<int>); std::cout << std::endl;
	std::for_each(vec2.begin(), vec2.end(), printVal<int>); std::cout << std::endl;
}

void	ft_speed_test()
{
	std::cout << "\n----- ft_speed_test() -----\n" << std::endl;
	std::vector<int>	vec(10);

	for (int i = 0; i < 10000; ++i) {
		vec.insert(vec.end() - 10, i);
	}
	for (int i = 0; i < 10000; ++i) {
		vec.erase(vec.end() - 10);
	}
}

void	ft_vector()
{
	/********************************/
	/***         ITERATORS        ***/
	/********************************/
	ft_iterator();
	ft_const_iterator();
	ft_reverse_iterator();
	ft_const_reverse_iterator();

	/********************************/
	/***          CAPACITY        ***/
	/********************************/
	ft_size();
	ft_max_size();
	ft_resize();
	ft_capacity();
	ft_empty();
	ft_reserve();


	/********************************/
	/***     ELEMENT ACCESS       ***/
	/********************************/
	ft_operator_at();
	ft_operator_at_const();
	ft_at();
	ft_at_const();
	ft_front();
	ft_front_const();
	ft_back();
	ft_back_const();

	/********************************/
	/***         MODIFIERS        ***/
	/********************************/
	ft_assign_range();
	ft_assign_fill();
	ft_insert_single_elem();
	ft_insert_fill();
	ft_insert_range();
	ft_erase_single_elem();
	ft_erase_range();

	ft_swap();
	ft_relational_operators();
	ft_speed_test();
}

/*----------- STACK -----------*/

void	ft_stack()
{
	std::stack<int>	s1;
	std::stack<int>	s2;

	for (int i = 0; i < 10; ++i) {
		s2.push(i);
	}
	std::cout << s1.empty() << std::endl;
	s1 = s2;
	std::cout << s1.empty() << std::endl;
	std::cout << "size: " << s1.size() << std::endl;
	std::cout << (&s1 == &s2) << std::endl;
	std::cout << s1.top() << std::endl;
	s1.push(42);
	std::cout << s1.top() << std::endl;
	s1.pop();
	std::cout << s1.top() << std::endl;
	s1.push(21);
	std::cout << (s1 == s2) << std::endl;
	std::cout << (s1 != s1) << std::endl;
	std::cout << (s1 < s2) << std::endl;
	std::cout << (s1 <= s2) << std::endl;
	std::cout << (s1 > s2) << std::endl;
	std::cout << (s1 >= s2) << std::endl;
	std::stack<int>	s3(s2);
	std::cout << (&s2 == &s3) << std::endl;
}

/*----------- MAP -----------*/

std::vector<std::pair<const int, int> >	vec;

typedef	std::map<int, int>::iterator					iterator;
typedef	std::map<int, int>::const_iterator			const_iterator;
typedef	std::map<int, int>::reverse_iterator			reverse_iterator;
typedef	std::map<int, int>::const_reverse_iterator	const_reverse_iterator;

void	ft_fill_vec() {
	for (int i = 0; i < 10; ++i) {
		vec.push_back(std::make_pair<const int, int>(i, 10 - i));
	}
}

/********************************/
/***        ITERATORS         ***/
/********************************/
void	ft_map_iterator()
{
	std::cout << "*----- ft_map_iterator() -----*" << std::endl;
	std::map<int, int>	mp(vec.begin(), vec.end());
	iterator	it = mp.begin(), ite = mp.end();

	std::cout << it->first << " | " << it->second << std::endl;
	std::cout << (*it).first << " | " << (*it).second << std::endl;
	std::cout << "-----" << std::endl;
	std::cout << (++it)->first << " | " << it->second << std::endl;
	std::cout << (it++)->first << " | " << it->second << std::endl;
	std::cout << it->first << " | " << it->second << std::endl;
	std::cout << "-----" << std::endl;
	std::cout << (--ite)->first << " | " << ite->second << std::endl;
	std::cout << (ite--)->first << " | " << ite->second << std::endl;
	std::cout << ite->first << " | " << ite->second << std::endl;
	std::cout << "-----" << std::endl;
	std::cout << (it == it) << std::endl;
	std::cout << (it != it) << std::endl;

	it = mp.begin();
	for (; it != ite; ++it) {
		std::cout << it->second << " ";
	}
	std::cout << std::endl;
}

void	ft_map_const_iterator()
{
	std::cout << "*----- ft_map_const_iterator() -----*" << std::endl;
	std::map<int, int>	mp(vec.begin(), vec.end());
	const_iterator	it = mp.begin(), ite = mp.end();

	std::cout << it->first << " | " << it->second << std::endl;
	std::cout << (*it).first << " | " << (*it).second << std::endl;
	std::cout << "-----" << std::endl;
	std::cout << (++it)->first << " | " << it->second << std::endl;
	std::cout << (it++)->first << " | " << it->second << std::endl;
	std::cout << it->first << " | " << it->second << std::endl;
	std::cout << "-----" << std::endl;
	std::cout << (--ite)->first << " | " << ite->second << std::endl;
	std::cout << (ite--)->first << " | " << ite->second << std::endl;
	std::cout << ite->first << " | " << ite->second << std::endl;
	std::cout << "-----" << std::endl;
	std::cout << (it == it) << std::endl;
	std::cout << (it != it) << std::endl;

	it = mp.begin();
	for (; it != ite; ++it) {
		std::cout << it->second << " ";
	}
	std::cout << std::endl;
}

void	ft_map_reverse_iterator()
{
	std::cout << "*----- ft_map_reverse_iterator() -----*" << std::endl;
	std::map<int, int>	mp(vec.begin(), vec.end());
	reverse_iterator	it = mp.rbegin(), ite = mp.rend();

	std::cout << it->first << " | " << it->second << std::endl;
	std::cout << (*it).first << " | " << (*it).second << std::endl;
	std::cout << "-----" << std::endl;
	std::cout << (++it)->first << " | " << it->second << std::endl;
	std::cout << (it++)->first << " | " << it->second << std::endl;
	std::cout << it->first << " | " << it->second << std::endl;
	std::cout << "-----" << std::endl;
	std::cout << (--ite)->first << " | " << ite->second << std::endl;
	std::cout << (ite--)->first << " | " << ite->second << std::endl;
	std::cout << ite->first << " | " << ite->second << std::endl;
	std::cout << "-----" << std::endl;
	std::cout << (it == it) << std::endl;
	std::cout << (it != it) << std::endl;

	it = mp.rbegin();
	for (; it != ite; ++it) {
		std::cout << it->second << " ";
	}
	std::cout << std::endl;
}

void	ft_map_const_reverse_iterator()
{
	std::cout << "*----- ft_map_const_reverse_iterator() -----*" << std::endl;
	std::map<int, int>	mp(vec.begin(), vec.end());
	const_reverse_iterator	it = mp.rbegin(), ite = mp.rend();

	std::cout << it->first << " | " << it->second << std::endl;
	std::cout << (*it).first << " | " << (*it).second << std::endl;
	std::cout << "-----" << std::endl;
	std::cout << (++it)->first << " | " << it->second << std::endl;
	std::cout << (it++)->first << " | " << it->second << std::endl;
	std::cout << it->first << " | " << it->second << std::endl;
	std::cout << "-----" << std::endl;
	std::cout << (--ite)->first << " | " << ite->second << std::endl;
	std::cout << (ite--)->first << " | " << ite->second << std::endl;
	std::cout << ite->first << " | " << ite->second << std::endl;
	std::cout << "-----" << std::endl;
	std::cout << (it == it) << std::endl;
	std::cout << (it != it) << std::endl;

	it = mp.rbegin();
	for (; it != ite; ++it) {
		std::cout << it->second << " ";
	}
	std::cout << std::endl;
}

/********************************/
/***        CAPACITY          ***/
/********************************/

void	ft_map_size_empty()
{
	std::cout << "*----- ft_map_size_empty() -----*" << std::endl;
	std::map<int, int>	mp;
	std::map<int, int>	mp_range(vec.begin(), vec.end());
	std::cout << "default | size: " << mp.size() << " | " << "empty: " << mp.empty() << std::endl;
	std::cout << "range | size: " << mp_range.size() << " | " << "empty: " << mp_range.empty() << std::endl;
	mp_range.erase(7); mp_range.erase(5); mp_range.erase(2);
	std::cout << "range | size: " << mp_range.size() << " | " << "empty: " << mp_range.empty() << std::endl;
	mp_range.clear();
	std::cout << "range | size: " << mp_range.size() << " | " << "empty: " << mp_range.empty() << std::endl;
	mp_range.insert(std::make_pair(42, 42));
	std::cout << "range | size: " << mp_range.size() << " | " << "empty: " << mp_range.empty() << std::endl;
	
	std::cout << std::endl;
}

void	ft_map_max_size()
{
	std::cout << "*----- ft_map_max_size() -----*" << std::endl;
	std::map<int, int>						mp1;
	std::map<std::string, float>				mp2;
	std::map<char, int>						mp3;
	std::map<std::vector<foo<char> >, char>	mp4;
	std::map<foo<std::string>, foo<float> >	mp5;

	std::cout << mp1.max_size() << std::endl;
	std::cout << mp2.max_size() << std::endl;
	std::cout << mp3.max_size() << std::endl;
	std::cout << mp4.max_size() << std::endl;
	std::cout << mp5.max_size() << std::endl;
	
	std::cout << std::endl;
}

/********************************/
/***   	  ELEMENT ACCESS      ***/
/********************************/
void	ft_map_at_operator()
{
	std::cout << "*----- ft_map_at_operator() -----*" << std::endl;
	std::map<float, float>	mp(vec.begin(), vec.end());
	std::cout << mp[7] << std::endl;
	mp[42] = 42;
	mp[3.2] = 3.5;
	std::map<float, float>::const_iterator	it = mp.begin(), ite = mp.end();
	for (; it != ite; ++it) {
		std::cout << it->first << " | " << it->second << std::endl;;
	}
	mp[1] = 2021;
	mp[2] = 2022;
	mp[50];
	it = mp.begin(); ite = mp.end();
	for (; it != ite; ++it) {
		std::cout << it->first << " | " << it->second << std::endl;;
	}
	std::cout << std::endl;
}

/********************************/
/***         MODIFIERS        ***/
/********************************/
void	ft_map_insert()
{
	std::cout << "*----- ft_map_insert() -----*" << std::endl;
	std::map<int, int>	mp;
	std::map<int, int>	mp_range(vec.begin(), vec.end());
	iterator	it = mp.begin(), ite = mp.end();
	for (; it != ite; ++it) {
		std::cout << it->first << std::endl;
	}
	std::cout << "default | size: " << mp.size() << " | " << "empty: " << mp.empty() << std::endl;
	std::pair<iterator, bool>	retPair = mp.insert(std::make_pair(42, 84));
	std::cout << retPair.first->first << " | " << retPair.first->second << " | " << retPair.second << std::endl;
	std::cout << "default | size: " << mp.size() << " | " << "empty: " << mp.empty() << std::endl;
	it = mp.begin();
	std::cout << it->first << " | " << it->second << std::endl;
	retPair = mp.insert(std::make_pair(42, 21));
	std::cout << retPair.first->first << " | " << retPair.first->second << " | " << retPair.second << std::endl;
	std::cout << "default | size: " << mp.size() << " | " << "empty: " << mp.empty() << std::endl;
	it = mp.begin();
	std::cout << it->first << " | " << it->second << std::endl;
	mp.insert(std::make_pair(-1, -2));
	std::cout << "default | size: " << mp.size() << " | " << "empty: " << mp.empty() << std::endl;
	it = mp.begin();
	std::cout << it->first << " | " << it->second << std::endl;
	std::cout << mp.insert(--mp.end(), std::make_pair(404, 404))->first << std::endl;;
	it = --mp.end();
	std::cout << it->first << " | " << it->second << std::endl;
	mp.insert(mp_range.begin(), mp_range.end());
	it = mp.begin(); ite = mp.end();
	for (; it != ite; ++it) {
		std::cout << it->first << " | " << it->second << std::endl;
	}
	std::cout << "default | size: " << mp.size() << " | " << "empty: " << mp.empty() << std::endl;
	std::cout << std::endl;
}

void	ft_map_erase()
{
	std::cout << "*----- ft_map_erase() -----*" << std::endl;
	std::map<int, int>	mp(vec.begin(), vec.end());
	iterator	it = mp.begin(), ite = mp.end();
	std::cout << "default | size: " << mp.size() << " | " << "empty: " << mp.empty() << std::endl;
	std::cout << mp.erase(2) << std::endl;
	std::cout << mp.erase(100) << std::endl;
	std::cout << mp.erase(-3) << std::endl;
	std::cout << mp.erase(7) << std::endl;
	for (; it != ite; ++it) {
		std::cout << it->first << " | " << it->second << std::endl;
	}
	std::cout << "default | size: " << mp.size() << " | " << "empty: " << mp.empty() << std::endl;
	it = ++(++mp.begin());
	mp.erase(it);
	it = mp.begin(); ite = mp.end();
	for (; it != ite; ++it) {
		std::cout << it->first << " | " << it->second << std::endl;
	}
	std::cout << "default | size: " << mp.size() << " | " << "empty: " << mp.empty() << std::endl;
	mp.erase(mp.begin(), mp.end());
	it = mp.begin(); ite = mp.end();
	for (; it != ite; ++it) {
		std::cout << it->first << " | " << it->second << std::endl;
	}
	std::cout << "default | size: " << mp.size() << " | " << "empty: " << mp.empty() << std::endl;
	std::cout << std::endl;
}

void	ft_map_swap_clear()
{
	std::cout << "*----- ft_map_swap_clear() -----*" << std::endl;
	std::map<int, int>	mp(vec.begin(), vec.end());
	std::map<int, int>	mp_;

	mp_[42]; mp_[12]; mp_[34]; mp_[-3];

	iterator	it = mp.begin(), ite = mp.end();
	iterator	it_ = mp_.begin(), ite_ = mp_.end();
	for (; it != ite; ++it) {
		std::cout << it->first << " " << std::endl;
	}
	for(; it_ != ite_; ++it_) {
		std::cout << it_->first << " " << std::endl;
	}
	mp.swap(mp_);
	it = mp.begin(); ite = mp.end();
	it_ = mp_.begin(); ite_ = mp_.end();
	for (; it != ite; ++it) {
		std::cout << it->first << " " << std::endl;
	}
	for(; it_ != ite_; ++it_) {
		std::cout << it_->first << " " << std::endl;
	}
	mp.clear();
	mp_.clear();
	std::cout << mp.size() << std::endl;
	std::cout << mp_.size() << std::endl;
	mp[42] = 42;
	it = mp.begin(); ite = mp.end();
	for (; it != ite; ++it) {
		std::cout << it->first << std::endl;
	}
}

void	ft_map_bounds()
{
	std::cout << "*----- ft_map_bounds() -----*" << std::endl;
	std::map<int, int>	mp(vec.begin(), vec.end());

	mp[42] = 42;

	std::cout << mp.count(7) << std::endl;
	if (mp.count(7) > 0) {
		std::cout << mp.find(7)->first << std::endl;
	}
	std::cout << mp.count(-24) << std::endl;
	if (mp.count(-24) > 0) {
		std::cout << mp.find(-24)->first << std::endl;
	}
	std::cout << mp.lower_bound(7)->first << std::endl;
	std::cout << mp.lower_bound(11)->first << std::endl;
	std::cout << mp.upper_bound(7)->first << std::endl;
	std::cout << mp.upper_bound(11)->first << std::endl;
	mp.erase(42);
	std::pair<iterator, iterator>	pr = mp.equal_range(9);
	std::cout << (pr.first == mp.end()) << std::endl;
	std::cout << (pr.second == mp.end()) << std::endl;
}

void	ft_map_relational_operators()
{
	std::cout << "*----- ft_map_relational_operators() -----*" << std::endl;
	std::map<int, int>	mp;
	std::map<int, int>	mp_;

	mp[21]; mp[42]; mp[36];
	mp_[21]; mp_[41];

	std::cout << (mp == mp_) << std::endl;
	std::cout << (mp != mp_) << std::endl;
	std::cout << (mp < mp_) << std::endl;
	std::cout << (mp > mp_) << std::endl;
	std::cout << (mp <= mp_) << std::endl;
	std::cout << (mp >= mp_) << std::endl;
}

void	ft_map_speed_test()
{
	std::cout << "*----- ft_map_speed_test() -----*" << std::endl;
	std::vector<std::pair<const int, int> >	vec;
	for (int i = 0; i < 10000; ++i) {
		vec.push_back(std::pair<const int, int>(i, 10000 - i));
	}
	std::map<int, int>	mp;
	for (int i = 0; i < 3500; ++i) {
		mp.insert(vec[i]);
	}
	for (int i = 7500; i < 10000; ++i) {
		mp.insert(vec[i]);
	}
	for (int i = 3500; i < 7500; ++i) {
		mp.insert(vec[i]);
	}
	for (int i = 0; i < 10000; ++i) {
		mp.erase(i);
	}
}


void	ft_map() {
	ft_fill_vec();

	/********************************/
	/***        ITERATORS         ***/
	/********************************/
	ft_map_iterator();
	ft_map_const_iterator();
	ft_map_reverse_iterator();
	ft_map_const_reverse_iterator();

	/********************************/
	/***        CAPACITY          ***/
	/********************************/
	ft_map_size_empty();
	ft_map_max_size();
	ft_map_at_operator();

	/********************************/
	/***         MODIFIERS        ***/
	/********************************/
	ft_map_insert();
	ft_map_erase();
	ft_map_swap_clear();
	ft_map_bounds();

	ft_map_relational_operators();

	ft_map_speed_test();
}


int main(void) {
	struct timeval start;
	struct timeval end;

	gettimeofday(&start, NULL);
	ft_vector();
	gettimeofday(&end, NULL);
	std::cout << "VECTOR time in namespace std:: is ";
	std::cout << (end.tv_sec - start.tv_sec) + 1e-6*(end.tv_usec - start.tv_usec);
	std::cout << std::endl;

	gettimeofday(&start, NULL);
	ft_stack();
	gettimeofday(&end, NULL);
	std::cout << "STACK time in namespace std:: is ";
	std::cout << (end.tv_sec - start.tv_sec) + 1e-6*(end.tv_usec - start.tv_usec);
	std::cout << std::endl;

	gettimeofday(&start, NULL);
	ft_map();
	gettimeofday(&end, NULL);
	std::cout << "MAP time in namespace std:: is ";
	std::cout << (end.tv_sec - start.tv_sec) + 1e-6*(end.tv_usec - start.tv_usec);
	std::cout << std::endl;

	return 0;
}
