/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:50:38 by fhamel            #+#    #+#             */
/*   Updated: 2022/01/25 16:11:51 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <typeinfo>
#include <vector>
#include <stack>
#include <list>
#include <deque>
#include <string>
#include <map>
#include <chrono>

/** time **/
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
/**********/

#include "vector.hpp"
#include "stack.hpp"

/* ft::vector */
/* ft::stack */
/* ft::map */

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

// template <class T>
// class my_input_iter : public ft::base_iterator<std::input_iterator_tag, T> {};

// template <class T>
// class my_forward_iter: public ft::base_iterator<std::forward_iterator_tag, T> {};

/*----------- VECTOR -----------*/

/********************************/
/***         ITERATORS        ***/
/********************************/

void	ft_iterator()
{
	std::cout << "\n----- ft_iterator() -----\n" << std::endl;
	ft::vector<int>	vec;

	for (int i = 0; i < 10; ++i) {
		vec.push_back(i);
	}
	ft::vector<int>::iterator	it = vec.begin();
	ft::vector<int>::iterator	ite = vec.end();
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
	ft::vector<int>	vec;

	for (int i = 0; i < 10; ++i) {
		vec.push_back(i);
	}
	ft::vector<int>::const_iterator	it = vec.begin();
	ft::vector<int>::const_iterator	ite = vec.end();
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
	ft::vector<int>	vec;

	for (int i = 0; i < 10; ++i) {
		vec.push_back(i);
	}
	ft::vector<int>::reverse_iterator	it = vec.rbegin();
	ft::vector<int>::reverse_iterator	ite = vec.rend();
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
	ft::vector<int>	vec;

	for (int i = 0; i < 10; ++i) {
		vec.push_back(i);
	}
	ft::vector<int>::const_reverse_iterator	it = vec.rbegin();
	ft::vector<int>::const_reverse_iterator	ite = vec.rend();
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
	std::cout << "\n----- ft_max_size() -----\n" << std::endl;
	ft::vector<float>	vec;
	std::cout << vec.max_size() << std::endl;
}

void	ft_resize()
{
	std::cout << "\n----- ft_resize() -----\n" << std::endl;
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
	std::cout << "\n----- ft_capacity() -----\n" << std::endl;
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
	std::cout << "\n----- ft_empty() -----\n" << std::endl;
	ft::vector<int>	vec;
	std::cout << vec.empty() << std::endl;
	vec.push_back(42);
	std::cout << vec.empty() << std::endl;
}

void	ft_reserve()
{
	std::cout << "\n----- ft_reserve() -----\n" << std::endl;
	ft::vector<int>	vec(10, 42);
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
		ft::vector<int>	vec1(10, 42);
		ft::vector<int>	vec2(10, 42);
		vec2[7] = 41;
		std::cout << (vec1 == vec2) << std::endl;
		std::cout << (vec1 != vec2) << std::endl;
		std::cout << (vec1 < vec2) << std::endl;
		std::cout << (vec1 <= vec2) << std::endl;
		std::cout << (vec1 > vec2) << std::endl;
		std::cout << (vec1 >= vec2) << std::endl;
	}
	{
		ft::vector<int>	vec1(10, 42);
		ft::vector<int>	vec2(11, 42);
		std::cout << (vec1 == vec2) << std::endl;
		std::cout << (vec1 != vec2) << std::endl;
		std::cout << (vec1 < vec2) << std::endl;
		std::cout << (vec1 <= vec2) << std::endl;
		std::cout << (vec1 > vec2) << std::endl;
		std::cout << (vec1 >= vec2) << std::endl;
	}
	{
		ft::vector<int>	vec1(10, 42);
		ft::vector<int>	vec2(10, 42);
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
	ft::vector<int>	vec(10, 42);
	std::cout << vec[0] << " | " << vec[vec.size() - 1] << std::endl;
	vec[4] = 21;
	std::for_each(vec.begin(), vec.end(), printVal<int>); std::cout << std::endl;
}

void	ft_operator_at_const()
{
	std::cout << "\n----- ft_operator_at_const() -----\n" << std::endl;
	const ft::vector<int>	vec(10, 42);
	std::cout << vec[0] << " | " << vec[vec.size() - 1] << std::endl;
	std::for_each(vec.begin(), vec.end(), printVal<int>); std::cout << std::endl;
}

void	ft_at()
{
	std::cout << "\n----- ft_at() -----\n" << std::endl;
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
	std::cout << "\n----- ft_at_const() -----\n" << std::endl;
	const ft::vector<int>	vec(10, 42);
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
	ft::vector<int>	vec;
	vec.push_back(42);
	vec.push_back(21);
	std::cout << vec.front() << std::endl;
}

void	ft_front_const()
{
	std::cout << "\n----- ft_front_const() -----\n" << std::endl;
	const ft::vector<int>	vec(10, 42);
	std::cout << vec.front() << std::endl;
}

void	ft_back()
{
	std::cout << "\n----- ft_back() -----\n" << std::endl;
	ft::vector<int>	vec;
	vec.push_back(42);
	vec.push_back(21);
	std::cout << vec.back() << std::endl;
}

void	ft_back_const()
{
	std::cout << "\n----- ft_back_const() -----\n" << std::endl;
	const ft::vector<int>	vec(10, 42);
	std::cout << vec.back() << std::endl;
}

/********************************/
/***         MODIFIERS        ***/
/********************************/

void	ft_assign_range()
{
	std::cout << "\n----- ft_assign_range() -----\n" << std::endl;
	
	ft::vector<int>	vec;

	vec.assign(10, 42);
	std::for_each(vec.begin(), vec.end(), printVal<int>); std::cout << std::endl;

	vec.assign(5, 21);
	std::for_each(vec.begin(), vec.end(), printVal<int>); std::cout << std::endl;
}

void	ft_assign_fill()
{
	std::cout << "\n----- ft_assign_fill() -----\n" << std::endl;

	ft::vector<int>		vec;

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
	ft::vector<int> vec;

	ft::vector<int>::iterator it0 = vec.insert(vec.begin(), 42);
	std::cout << "ret it0 insert: " << *it0 << std::endl;
	std::for_each(vec.begin(), vec.end(), printVal<int>); std::cout << std::endl;
	std::cout << "size: " << vec.size() << std::endl;
	std::cout << "capacity: " << vec.capacity() << std::endl;

	ft::vector<int>::iterator it1 = vec.insert(vec.begin() + 1, 21);
	ft::vector<int>::iterator it2 = vec.insert(vec.begin() + 1, 12);
	std::cout << "ret it1 insert: " << *it1 << std::endl;
	std::cout << "ret it2 insert: " << *it2 << std::endl;
	std::for_each(vec.begin(), vec.end(), printVal<int>); std::cout << std::endl;
	std::cout << "size: " << vec.size() << std::endl;
	std::cout << "capacity: " << vec.capacity() << std::endl;

	ft::vector<int>::iterator it3 = vec.insert(vec.begin() + 2, 24);
	std::cout << "ret it3 insert: " << *it3 << std::endl;
	std::for_each(vec.begin(), vec.end(), printVal<int>);
	std::cout << std::endl;
	std::cout << "size: " << vec.size() << std::endl;
	std::cout << "capacity: " << vec.capacity() << std::endl;
}

void	ft_insert_fill()
{
	std::cout << "\n----- ft_insert_fill() -----\n" << std::endl;
	ft::vector<int> vec;

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
	ft::vector<int> 	vec;

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
	ft::vector<int>	vec;

	for (int i = 0; i < 10; ++i) {
		vec.push_back(i * i);
	}
	std::for_each(vec.begin(), vec.end(), printVal<int>);

	ft::vector<int>::iterator	it = vec.erase(vec.begin() + 3);

	std::for_each(vec.begin(), vec.end(), printVal<int>); std::cout << std::endl;
	std::cout << "ret value: " << *it << std::endl;
	std::cout << "ret index: " << it - vec.begin() << std::endl;
}

void	ft_erase_range()
{
	std::cout << "\n----- ft_erase_range() -----\n" << std::endl;
	ft::vector<int>	vec;

	for (int i = 0; i < 10; ++i) {
		vec.push_back(i * i);
	}
	std::for_each(vec.begin(), vec.end(), printVal<int>);

	ft::vector<int>::iterator	it = vec.erase(vec.begin() + 2, vec.begin() + 5);

	std::for_each(vec.begin(), vec.end(), printVal<int>); std::cout << std::endl;
	std::cout << "ret value: " << *it << std::endl;
	std::cout << "ret index: " << it - vec.begin() << std::endl;
}

void	ft_swap()
{
	std::cout << "\n----- ft_swap() -----\n" << std::endl;
	ft::vector<int>	vec1(8, 42);
	ft::vector<int>	vec2(12, 21);

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

void	ft_vector()
{
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
	/***   RELATIONAL OPERATORS   ***/
	/********************************/

	ft_relational_operators();

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

	/* assign */
	ft_assign_range();
	ft_assign_fill();

	/* insert */
	ft_insert_single_elem();
	ft_insert_fill();
	ft_insert_range();

	/* erase */
	ft_erase_single_elem();
	ft_erase_range();

	/* swap */
	ft_swap();
}

/*----------- STACK -----------*/

void	ft_stack()
{
	ft::stack<int>	s1;
	ft::stack<int>	s2;

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
	ft::stack<int>	s3(s2);
	std::cout << (&s2 == &s3) << std::endl;
}

/*----------- MAP -----------*/

#include "utility.hpp"
#include "map.hpp"

std::vector<ft::pair<const int, int> >	vec;

typedef	ft::map<int, int>::iterator					iterator;
typedef	ft::map<int, int>::const_iterator			const_iterator;
typedef	ft::map<int, int>::reverse_iterator			reverse_iterator;
typedef	ft::map<int, int>::const_reverse_iterator	const_reverse_iterator;

// template <class Key, class T>
// void	printTree(ft::Node<Key, T> *current)
// {
// 	if (current->parent() == NULL) {
// 		std::cout << current->key() << std::endl;
// 	}
// 	if (current->leftChild() == NULL) {
// 		std::cout << "NIL" << " ";
// 	} else {
// 		std::cout << current->leftChild()->key() << " ";
// 	}

// 	if (current->rightChild() == NULL) {
// 		std::cout << "NIL" << " ";
// 	} else {
// 		std::cout << current->rightChild()->key() << " ";
// 	}

// 	std::cout << "\n-----\n";
// 	if (current->leftChild() != NULL) {
// 		printTree(current->leftChild());
// 	}
// 	if (current->rightChild() != NULL) {
// 		printTree(current->rightChild());
// 	}
// 	return;
// }

void	ft_fill_vec() {
	for (int i = 0; i < 10; ++i) {
		vec.push_back(ft::make_pair<const int, int>(i, 10 - i));
	}
}

/********************************/
/***        ITERATORS         ***/
/********************************/
void	ft_map_iterator()
{
	std::cout << "*----- ft_map_iterator() -----*" << std::endl;
	ft::map<int, int>	mp(vec.begin(), vec.end());
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
	ft::map<int, int>	mp(vec.begin(), vec.end());
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
	ft::map<int, int>	mp(vec.begin(), vec.end());
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
	ft::map<int, int>	mp(vec.begin(), vec.end());
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
	ft::map<int, int>	mp;
	ft::map<int, int>	mp_range(vec.begin(), vec.end());
	std::cout << "default | size: " << mp.size() << " | " << "empty: " << mp.empty() << std::endl;
	std::cout << "range | size: " << mp_range.size() << " | " << "empty: " << mp_range.empty() << std::endl;
	mp_range.erase(7); mp_range.erase(5); mp_range.erase(2);
	std::cout << "range | size: " << mp_range.size() << " | " << "empty: " << mp_range.empty() << std::endl;
	mp_range.clear();
	std::cout << "range | size: " << mp_range.size() << " | " << "empty: " << mp_range.empty() << std::endl;
	mp_range.insert(ft::make_pair(42, 42));
	std::cout << "range | size: " << mp_range.size() << " | " << "empty: " << mp_range.empty() << std::endl;
	
	std::cout << std::endl;
}

void	ft_map_max_size()
{
	std::cout << "*----- ft_map_max_size() -----*" << std::endl;
	ft::map<int, int>						mp1;
	ft::map<std::string, float>				mp2;
	ft::map<char, int>						mp3;
	ft::map<std::vector<foo<char> >, char>	mp4;
	ft::map<foo<std::string>, foo<float> >	mp5;

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
	ft::map<float, float>	mp(vec.begin(), vec.end());
	std::cout << mp[7] << std::endl;
	mp[42] = 42;
	mp[3.2] = 3.5;
	ft::map<float, float>::const_iterator	it = mp.begin(), ite = mp.end();
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
	ft::map<int, int>	mp;
	ft::map<int, int>	mp_range(vec.begin(), vec.end());
	iterator	it = mp.begin(), ite = mp.end();
	for (; it != ite; ++it) {
		std::cout << it->first << std::endl;
	}
	std::cout << "default | size: " << mp.size() << " | " << "empty: " << mp.empty() << std::endl;
	ft::pair<iterator, bool>	retPair = mp.insert(ft::make_pair(42, 84));
	std::cout << retPair.first->first << " | " << retPair.first->second << " | " << retPair.second << std::endl;
	std::cout << "default | size: " << mp.size() << " | " << "empty: " << mp.empty() << std::endl;
	it = mp.begin();
	std::cout << it->first << " | " << it->second << std::endl;
	retPair = mp.insert(ft::make_pair(42, 21));
	std::cout << retPair.first->first << " | " << retPair.first->second << " | " << retPair.second << std::endl;
	std::cout << "default | size: " << mp.size() << " | " << "empty: " << mp.empty() << std::endl;
	it = mp.begin();
	std::cout << it->first << " | " << it->second << std::endl;
	mp.insert(ft::make_pair(-1, -2));
	std::cout << "default | size: " << mp.size() << " | " << "empty: " << mp.empty() << std::endl;
	it = mp.begin();
	std::cout << it->first << " | " << it->second << std::endl;
	std::cout << mp.insert(--mp.end(), ft::make_pair(404, 404))->first << std::endl;;
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
	ft::map<int, int>	mp(vec.begin(), vec.end());
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

void	ft_map_speed()
{
	std::vector<ft::pair<int, float> >	vec_;
	for (int i = 0; i < 10000; ++i) {
		vec_.push_back(ft::make_pair<int, float>(i, 10000 - i));
	}
	ft::map<int, float>	mp(vec_.begin(), vec_.end());
	for (int i = 5000; i < 10000; ++i) {
		mp.erase(i);
	}
	for (int i = 0; i < 500; ++i) {
		mp.erase(i);
	}
}

void	ft_map_swap_clear()
{
	std::cout << "*----- ft_map_swap_clear() -----*" << std::endl;
	ft::map<int, int>	mp(vec.begin(), vec.end());
	ft::map<int, int>	mp_;

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
}

void	ft_map_bounds()
{
	std::cout << "*----- ft_map_bounds() -----*" << std::endl;
	ft::map<int, int>	mp(vec.begin(), vec.end());

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
	ft::pair<iterator, iterator>	pr = mp.equal_range(9);
	std::cout << (pr.first == mp.end()) << std::endl;
	std::cout << (pr.second == mp.end()) << std::endl;
}

void	ft_map_relational_operators()
{
	ft::map<int, int>	mp;
	ft::map<int, int>	mp_;

	mp[21]; mp[42]; mp[36];
	mp_[21]; mp_[41];

	std::cout << (mp == mp_) << std::endl;
	std::cout << (mp != mp_) << std::endl;
	std::cout << (mp < mp_) << std::endl;
	std::cout << (mp > mp_) << std::endl;
	std::cout << (mp <= mp_) << std::endl;
	std::cout << (mp >= mp_) << std::endl;
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
}


int main(void) {
	struct timeval start;
	struct timeval end;

	gettimeofday(&start, NULL);
	
	ft_vector();
	ft_stack();
	ft_map();
	
	gettimeofday(&end, NULL);
	std::cout << "time for ft:: is ";
	std::cout << (end.tv_sec - start.tv_sec) + 1e-6*(end.tv_usec - start.tv_usec);
	std::cout << std::endl;
	// while (1) {}
	return 0;
}
