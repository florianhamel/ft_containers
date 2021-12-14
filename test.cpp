/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:11:05 by fhamel            #+#    #+#             */
/*   Updated: 2021/12/14 01:57:43 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstddef>
#include <memory>
#include <type_traits>

#include "vector.hpp"

template <class T>
void	printVec(const T &val) {
	std::cout << val << " ";
}

template <class T>
class InputIter : public ft::base_iterator<std::input_iterator_tag, T> {
	public:

		typedef	typename ft::vector<T>::iterator	iterator;

		InputIter() : ptr_(0), next_(0) {};

		InputIter(T *ptr) : ptr_(ptr), next_(ptr + 1) {};

		InputIter(iterator const &it) : ptr_(it.base()), next_(it.base() + 1) {}

		~InputIter() {};

		T	*base()
			{ return ptr_; };

		InputIter	&operator=(InputIter const &it)
			{ ptr_ = it.ptr_; return *this; }

		bool		operator==(InputIter const &it) const
			{ return (ptr_ == it.ptr_); }

		bool		operator!=(InputIter const &it) const
			{ return (ptr_ != it.ptr_); }

		T			&operator*(void) const
			{ return *ptr_; }

		T			*operator->(void) const
			{ return ptr_; }

		InputIter	&operator++(void)
			{ ptr_ = next_; return *this; }

		InputIter	operator++(int)
			{ T *retPtr = ptr_; ptr_ = next_; return retPtr; }
		
		void	setNext(T *next)
			{ next_ = next; }

		private:

			T	*ptr_;
			T	*next_;
		
};

// template <class T>
// class myIter2 : public ft::base_iterator<std::forward_iterator_tag, T> {
// 	public:
// 		myIter2() : ptr_(0) {};
// 		~myIter2() {};
// 		T	*base() { return ptr_; };
// 	private:
// 		T	*ptr_;
// };

int main(void)
{
	ft::vector<int>	vec;
	ft::vector<int>	vec_(10, 21);
	
	vec.insert(vec.begin(), vec_.begin() + 3, vec_.begin());
	
	std::for_each(vec.begin(), vec.end(), printVec<int>); std::cout << std::endl;
	std::cout << "size: " << vec.size() << std::endl;
	std::cout << "capacity: " << vec.capacity() << std::endl;

	return 0;
}
