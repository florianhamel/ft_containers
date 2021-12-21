/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:11:05 by fhamel            #+#    #+#             */
/*   Updated: 2021/12/19 19:57:31 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cstddef>
#include <memory>
#include <type_traits>

#include "vector.hpp"

template <class T>
void	printVal(const T &val) {
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
	/* assign */
	// {
	// 	std::vector<int>	vec(5, 42);
	// 	std::list<int>	lst(7, 21);

	// 	vec.assign(lst.begin(), lst.end());
	// 	std::for_each(vec.begin(), vec.end(), printVal<int>); std::cout << std::endl;
	// 	vec.assign(10, 25);
	// 	std::for_each(vec.begin(), vec.end(), printVal<int>); std::cout << std::endl;
	// }
	// std::cout << "/----------/" << std::endl;
	// {
	// 	ft::vector<int>	vec(5, 42);
	// 	std::list<int>	lst(7, 21);

	// 	vec.assign(lst.begin(), lst.end());
	// 	std::for_each(vec.begin(), vec.end(), printVal<int>); std::cout << std::endl;
	// 	vec.assign(10, 25);
	// 	std::for_each(vec.begin(), vec.end(), printVal<int>); std::cout << std::endl;
	// }

	/* pop_back */
	// {
	// 	ft::vector<int>	vec(5, 42);
	// 	for (int i = 0; i < 3; ++i) {
	// 		vec.pop_back();
	// 	}
	// 	std::for_each(vec.begin(), vec.end(), printVal<int>);
	// }

	/* swap */
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
	// while(1) {}
	return 0;
}
