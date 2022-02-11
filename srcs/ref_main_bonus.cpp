/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ref_main_bonus.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:43:18 by fhamel            #+#    #+#             */
/*   Updated: 2022/02/11 03:30:25 by fhamel           ###   ########.fr       */
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
#include <set>

#include <time.h>
#include <sys/time.h>
#include <stdlib.h>

#include "set.hpp"

typedef std::set<int>::iterator					iterator;
typedef std::set<int>::const_iterator			const_iterator;
typedef std::set<int>::reverse_iterator			reverse_iterator;
typedef std::set<int>::const_reverse_iterator	const_reverse_iterator;

template <class T>
struct foo {
	
	foo(void) : var1(), var2(), var3() {}
	
	T	var1;
	T	var2;
	T	var3;

};

std::vector<int>	vec;

void	ft_fill_vec()
{
	for (int i = 0; i < 10; ++i) {
		vec.push_back((i + 1) * 3);
	}
}

void	ft_set_iterator()
{
	std::cout << "*----- ft_set_iterator() -----*" << std::endl;
	std::set<int>	st(vec.begin(), vec.end());
	iterator	it = st.begin(), ite = st.end();
	std::cout << (it == ite) << std::endl;
	std::cout << (it != ite) << std::endl;
	std::cout << *it << std::endl;
	std::cout << *(++it) << std::endl;
	std::cout << *(it++) << std::endl;
	std::cout << *(--it) << std::endl;
	std::cout << *(it--) << std::endl;
	std::cout << *it << std::endl;
	iterator	it_ = --(--(st.end()));
	it = it_;
	std::cout << *it << std::endl;
	std::cout << std::endl;
}

void	ft_set_const_iterator()
{
	std::cout << "*----- ft_set_const_iterator() -----*" << std::endl;
	std::set<int>	st(vec.begin(), vec.end());
	const_iterator	it = st.begin(), ite = st.end();
	std::cout << (it == ite) << std::endl;
	std::cout << (it != ite) << std::endl;
	std::cout << *it << std::endl;
	std::cout << *(++it) << std::endl;
	std::cout << *(it++) << std::endl;
	std::cout << *(--it) << std::endl;
	std::cout << *(it--) << std::endl;
	std::cout << *it << std::endl;
	const_iterator	it_ = --(--(st.end()));
	it = it_;
	std::cout << *it << std::endl;
	std::cout << std::endl;
}

void	ft_set_reverse_iterator()
{
	std::cout << "*----- ft_set_reverse_iterator() -----*" << std::endl;
	std::set<int>	st(vec.begin(), vec.end());
	reverse_iterator	it = st.rbegin(), ite = st.rend();
	std::cout << (it == ite) << std::endl;
	std::cout << (it != ite) << std::endl;
	std::cout << *it << std::endl;
	std::cout << *(++it) << std::endl;
	std::cout << *(it++) << std::endl;
	std::cout << *(--it) << std::endl;
	std::cout << *(it--) << std::endl;
	std::cout << *it << std::endl;
	reverse_iterator	it_ = --(--(st.rend()));
	it = it_;
	std::cout << *it << std::endl;
	std::cout << std::endl;
}

void	ft_set_const_reverse_iterator()
{
	std::cout << "*----- ft_set_const_reverse_iterator() -----*" << std::endl;
	std::set<int>	st(vec.begin(), vec.end());
	const_reverse_iterator	it = st.rbegin(), ite = st.rend();
	std::cout << (it == ite) << std::endl;
	std::cout << (it != ite) << std::endl;
	std::cout << *it << std::endl;
	std::cout << *(++it) << std::endl;
	std::cout << *(it++) << std::endl;
	std::cout << *(--it) << std::endl;
	std::cout << *(it--) << std::endl;
	std::cout << *it << std::endl;
	const_reverse_iterator	it_ = --(--(st.rend()));
	it = it_;
	std::cout << *it << std::endl;
	std::cout << std::endl;
}

void	ft_set_empty_size()
{
	std::cout << "*----- ft_set_empty_size() -----*" << std::endl;
	std::set<int>	st;
	std::set<int>	st_range(vec.begin(), vec.end());
	
	std::cout << st.empty() << std::endl;
	std::cout << st_range.empty() << std::endl;
	st.insert(42);
	std::cout << st.empty() << std::endl;
	std::cout << st_range.size() << std::endl;
	st_range.insert(42);
	std::cout << st_range.size() << std::endl;
	st_range.erase(9);
	std::cout << st_range.size() << std::endl;
	st_range.clear();
	std::cout << st_range.empty() << std::endl;
	std::cout << st_range.size() << std::endl;
}

void	ft_set_max_size()
{
	std::cout << "*----- ft_set_max_size() -----*" << std::endl;
	std::set<float>				st1;
	std::set<foo<std::string> >	st2;
	std::set<int>				st3;
	std::set<std::string>		st4;
	std::set<std::vector<int> >	st5;
	
	std::cout << st1.max_size() << std::endl;
	std::cout << st2.max_size() << std::endl;
	std::cout << st3.max_size() << std::endl;
	std::cout << st4.max_size() << std::endl;
	std::cout << st5.max_size() << std::endl;
}

void	ft_set_insert()
{
	std::cout << "*----- ft_set_insert() -----*" << std::endl;
	std::set<int>	st;
	iterator		it, ite;
	for (int i = 0; i < 5; ++i) {
		st.insert(st.begin(), (i + 1) * 2);
	}
	it = st.begin(); ite = st.end();
	for (; it != ite; ++it) {
		std::cout << *it << std::endl;
	}
	for (int i = 0; i < 5; ++i) {
		st.insert(st.begin(), (i + 1) * 100);
	}
	it = st.begin(); ite = st.end();
	for (; it != ite; ++it) {
		std::cout << *it << std::endl;
	}
	st.insert(vec.begin(), vec.end());
	it = st.begin(); ite = st.end();
	for (; it != ite; ++it) {
		std::cout << *it << std::endl;
	}
}

void	ft_set_erase()
{
	std::cout << "*----- ft_set_erase() -----*" << std::endl;
	std::set<int>	st(vec.begin(), vec.end());
	std::set<int>	st_copy(st);

	iterator		it, ite;
	
	it = st_copy.begin(); ite = st_copy.end();
	for (; it != ite; ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	st_copy.erase(++(++(st_copy.begin())));
	st_copy.erase(--(--(st_copy.end())));
	it = st_copy.begin(); ite = st_copy.end();
	for (; it != ite; ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << st_copy.size() << std::endl;
	
	st_copy = st;
	it = st_copy.begin(); ite = st_copy.end();
	for (; it != ite; ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	st_copy.erase(++(++(st_copy.begin())));
	st_copy.erase(--(--(st_copy.end())));
	it = st_copy.begin(); ite = st_copy.end();
	for (; it != ite; ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << st_copy.size() << std::endl;

	st_copy = st;
	it = st_copy.begin(); ite = st_copy.end();
	for (; it != ite; ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	it = st_copy.begin(); ite = st_copy.end();
	st_copy.erase(st_copy.begin(), --(st_copy.end()));
	it = st_copy.begin(); ite = st_copy.end();
	for (; it != ite; ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void	ft_set_swap_clear()
{
	std::cout << "*----- ft_set_swap_clear() -----*" << std::endl;
	std::set<int>	st(vec.begin(), vec.end());
	std::set<int>	st_;
	st_.insert(5); st_.insert(10);
	iterator	it = st.begin(), ite = st.end();
	for (; it != ite; ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	it = st_.begin(); ite = st_.end();
	for (; it != ite; ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	st.swap(st_);
	it = st.begin(); ite = st.end();
	for (; it != ite; ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	it = st_.begin(); ite = st_.end();
	for (; it != ite; ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	st.clear();
	std::cout << st.empty() << std::endl;
	st.insert(42);
	it = st.begin(); ite = st.end();
	for (; it != ite; ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	st_.clear();
	std::cout << st_.size() << std::endl;
}

void	ft_set_bounds()
{
	std::cout << "*----- ft_set_bounds() -----*" << std::endl;
	std::set<int>	st(vec.begin(), vec.end());
	iterator	it;
	std::pair<iterator, iterator>	eq_range;
	
	it = st.find(2);
	if (it == st.end()) {
		std::cout << "END" << std::endl;
	}
	else {
		std::cout << *it << std::endl;
	}
	it = st.find(9);
	if (it == st.end()) {
		std::cout << "END" << std::endl;
	}
	else {
		std::cout << *it << std::endl;
	}
	
	it = st.lower_bound(21);
	if (it == st.end()) {
		std::cout << "END" << std::endl;
	}
	else {
		std::cout << *it << std::endl;
	}
	it = st.upper_bound(21);
	if (it == st.end()) {
		std::cout << "END" << std::endl;
	}
	else {
		std::cout << *it << std::endl;
	}
	eq_range = st.equal_range(21);
	std::cout << *(eq_range.first) << " | " << *(eq_range.second) << std::endl;

	it = st.lower_bound(10);
	if (it == st.end()) {
		std::cout << "END" << std::endl;
	}
	else {
		std::cout << *it << std::endl;
	}
	it = st.upper_bound(10);
	if (it == st.end()) {
		std::cout << "END" << std::endl;
	}
	else {
		std::cout << *it << std::endl;
	}
	eq_range = st.equal_range(10);
	std::cout << *(eq_range.first) << " | " << *(eq_range.second) << std::endl;
}

void	ft_set_relational_operators()
{
	std::cout << "*----- ft_set_relational_operators() -----*" << std::endl;
	std::set<int>	st1(vec.begin(), vec.end());
	std::set<int>	st2;

	st2.insert(25); st2.insert(42);
	std::cout << (st1 == st2) << std::endl;
	std::cout << (st1 != st2) << std::endl;
	std::cout << (st1 < st2) << std::endl;
	std::cout << (st1 > st2) << std::endl;
	std::cout << (st1 <= st2) << std::endl;
	std::cout << (st1 >= st2) << std::endl;
}

void	ft_set_speed_test()
{
	std::cout << "*----- ft_set_speed_test() -----*" << std::endl;

	std::vector<int>	vec;
	for (int i = 0; i < 10000; ++i) {
		vec.push_back(i);
	}
	std::set<int>	st;
	for (int i = 0; i < 3500; ++i) {
		st.insert(vec[i]);
	}
	for (int i = 7500; i < 10000; ++i) {
		st.insert(vec[i]);
	}
	for (int i = 3500; i < 7500; ++i) {
		st.insert(vec[i]);
	}
	for (int i = 0; i < 10000; ++i) {
		st.erase(i);
	}
}

int main(void)
{
	struct timeval start;
	struct timeval end;

	gettimeofday(&start, NULL);

	ft_fill_vec();
	ft_set_iterator();
	ft_set_const_iterator();
	ft_set_reverse_iterator();
	ft_set_const_reverse_iterator();

	ft_set_empty_size();
	ft_set_max_size();
	
	ft_set_insert();
	ft_set_erase();
	ft_set_swap_clear();

	ft_set_bounds();
	ft_set_speed_test();

	gettimeofday(&end, NULL);
	std::cout << "SET time in namespace std:: is ";
	std::cout << (end.tv_sec - start.tv_sec) + 1e-6*(end.tv_usec - start.tv_usec);
	std::cout << std::endl;
	while (1) {}

	return 0;
}