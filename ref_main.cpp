/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ref_main.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 22:55:32 by fhamel            #+#    #+#             */
/*   Updated: 2021/12/13 12:01:21 by fhamel           ###   ########.fr       */
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
	std::cout << "//----------//" << std::endl;
	return 0;
}
