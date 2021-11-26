/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:27:54 by fhamel            #+#    #+#             */
/*   Updated: 2021/11/26 00:59:41 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include <iterator>

# include "random_access_iterator.hpp"

namespace ft {

template <class T>
class iterator {
	
	typedef T								value_type;
	typedef	ptrdiff_t						difference_type;
	typedef T*								pointer;
	typedef	T&								reference;
	typedef std::random_access_iterator_tag	iterator_category;

	public:

		iterator(void) {}

		iterator(iterator const &it) { *this = it; }

		iterator(T *valPtr) : valPtr_(valPtr) {}

		~iterator(void) {}

		iterator	&operator=(iterator const &it) {
			valPtr_ = it.valPtr_;
			return *this;
		}

		bool	operator==(iterator const &it) const {
			return (valPtr_ == it.valPtr_);
		}

		bool	operator!=(iterator const &it) const {
			return (valPtr_ != it.valPtr_);
		}

		// question : pourquoi ça compile avec le const ? c'est une lvalue
		// du coup ça se modifie easy : *it = 42; ???
		T	&operator*(void) const {
			return *this->valPtr_;
		}

		T	*operator->(void) const {
			return valPtr_;
		}

		iterator	&operator++(void) {
			valPtr_++;
			return *this;
		}

		iterator	operator++(int) {
			T	*retPtr = valPtr_;
			valPtr_++;
			return retPtr;
		}
		
		iterator	&operator--(void) {
			valPtr_--;
			return *this;
		}

		iterator	operator--(int) {
			T	*retPtr = valPtr_;
			valPtr_--;
			return retPtr;
		}

		iterator	operator+(int const n) {
			T	*retPtr = valPtr_ + n;
			return retPtr;
		}

		friend iterator operator+(const int n, iterator const &it) {
			return iterator(it.valPtr_ + n);
		}

	private:

		T	*valPtr_;

};

template <class T>
class const_iterator {
	
	public:

		typedef T								value_type;
		typedef	ptrdiff_t						difference_type;
		typedef T*								pointer;
		typedef	T&								reference;
		typedef std::random_access_iterator_tag	iterator_category;

		const_iterator(void) : valPtr_(0) {}

		const_iterator(const T *valPtr) : valPtr_(valPtr) {}

		const_iterator(iterator<T> const &it) : valPtr_(it.operator->()) {}

		~const_iterator(void) {}

		const_iterator	&operator=(const_iterator const &it) {
			valPtr_ = it.valPtr_;
			return *this;
		}

		bool	operator==(const_iterator const &it) const {
			return (valPtr_ == it.valPtr_);
		}

		bool	operator!=(const_iterator const &it) const {
			return (valPtr_ != it.valPtr_);
		}

		T const &operator*(void) const {
			return *valPtr_;
		}

		T const *operator->(void) const {
			return valPtr_;
		}

		const_iterator	&operator++(void) {
			valPtr_++;
			return *this;
		}

		const_iterator	operator++(int) {
			T	*retPtr = valPtr_;
			valPtr_++;
			return retPtr;
		}
		
		const_iterator	&operator--(void) {
			valPtr_--;
			return *this;
		}

		const_iterator	operator--(int) {
			T	*retPtr = valPtr_;
			valPtr_--;
			return retPtr;
		}

		const_iterator	operator+(int const n) {
			T const	*retPtr = valPtr_ + n;
			return retPtr;
		}

		friend const_iterator operator+(const int n, const_iterator const &it) {
			return const_iterator(it.valPtr_ + n);
		}

	private:

		const T	*valPtr_;

};

}

#endif
