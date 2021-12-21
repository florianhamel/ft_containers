/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ref_main.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 22:55:32 by fhamel            #+#    #+#             */
/*   Updated: 2021/12/19 19:58:39 by fhamel           ###   ########.fr       */
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
class my_input_iter : public ft::base_iterator<std::input_iterator_tag, T> {
	public:
		my_input_iter() : ptr_(0) {};
		~my_input_iter() {};
		T	*base() { return ptr_; };
	private:
		T	*ptr_;
};

template <class T>
class my_forward_iter: public ft::base_iterator<std::forward_iterator_tag, T> {
	public:
		my_forward_iter() : ptr_(0) {};
		~my_forward_iter() {};
		T	*base() { return ptr_; };
	private:
		T	*ptr_;
};

int main(void) {
		
	std::cout << "//----- INSERT -----//" << std::endl;
	{
		std::cout << "/--- Single Element ---/" << std::endl;

		std::vector<int> vec;

		std::vector<int>::iterator it0 = vec.insert(vec.begin(), 42);
		std::cout << "ret it0 insert: " << *it0 << std::endl;
		std::cout << "print vec: ";
		std::for_each(vec.begin(), vec.end(), printVal<int>);
		std::cout << std::endl;
		std::cout << "size: " << vec.size() << std::endl;
		std::cout << "capacity: " << vec.capacity() << std::endl;

		std::vector<int>::iterator it1 = vec.insert(vec.begin() + 1, 21);
		std::vector<int>::iterator it2 = vec.insert(vec.begin() + 1, 12);
		std::cout << "ret it1 insert: " << *it1 << std::endl;
		std::cout << "ret it2 insert: " << *it2 << std::endl;
		std::cout << "print vec: " << std::endl;
		std::for_each(vec.begin(), vec.end(), printVal<int>);
		std::cout << std::endl;
		std::cout << "size: " << vec.size() << std::endl;
		std::cout << "capacity: " << vec.capacity() << std::endl;
	
		std::vector<int>::iterator it3 = vec.insert(vec.begin() + 2, 24);
		std::cout << "ret it3 insert: " << *it3 << std::endl;
		std::cout << "print vec: " << std::endl;
 		std::for_each(vec.begin(), vec.end(), printVal<int>);
		std::cout << std::endl;
		std::cout << "size: " << vec.size() << std::endl;
		std::cout << "capacity: " << vec.capacity() << std::endl;
	}
	{
		std::cout << "/--- Fill ---/" << std::endl;
		
		std::vector<int> vec;

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
	{
		std::cout << "/--- Range ---/" << std::endl;
		
		std::vector<int> 	vec;

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
	std::cout << "//----- ERASE -----//" << std::endl;
	{
		std::cout << "/--- Single Element ---/" << std::endl;
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
	{
		std::cout << "/--- Range ---/" << std::endl;
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
	std::cout << "//----- RESIZE -----//" << std::endl;
	{
	}
	std::cout << "//----- SWAP -----//" << std::endl;
	{
		std::vector<int>	vec1(7134, 42);
		std::vector<int>	vec2(42345, 21);

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
	return 0;
}
