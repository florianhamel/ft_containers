/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:27:54 by fhamel            #+#    #+#             */
/*   Updated: 2021/12/13 15:06:09 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include <iterator>

# include "type_traits.hpp"

template <class T>
class const_iterator;

namespace ft {

template <class T>
class iterator : public base_iterator<std::random_access_iterator_tag, T> {
	
	public:

		iterator(void) {}

		iterator(iterator const &it) { *this = it; }

		iterator(T *ptr) : ptr_(ptr) {}

		~iterator(void) {}

		T	*base(void) const { return ptr_; }

		/********************************/
		/***    OPERATOR OVERLOADS    ***/
		/********************************/

		iterator	&operator=(iterator const &it)
			{ ptr_ = it.ptr_; return *this; }

		bool		operator==(iterator const &it) const
			{ return (ptr_ == it.ptr_); }

		bool		operator!=(iterator const &it) const
			{ return (ptr_ != it.ptr_); }

		T			&operator*(void) const
			{ return *ptr_; }

		T			*operator->(void) const
			{ return ptr_; }

		iterator	&operator++(void)
			{ ptr_++; return *this; }

		iterator	operator++(int)
			{ T *retPtr = ptr_; ptr_++; return retPtr; }
		
		iterator	&operator--(void)
			{ ptr_--; return *this; }

		iterator	operator--(int)
			{ T *retPtr = ptr_; ptr_--; return retPtr; }

		iterator	operator+(int const n)
			{ T *retPtr = ptr_ + n; return retPtr; }
		
		friend iterator operator+(const int n, iterator const &it)
			{ return (it.ptr_ + n); }

		iterator	operator-(int const n)
			{ T *retPtr = ptr_ - n; return retPtr; }
		
		friend iterator operator-(const int n, iterator const &it)
			{ return (it.ptr_ - n); }
		
		ptrdiff_t	operator-(iterator const &it)
			{ return (ptr_ - it.ptr_); }

		bool		operator<(iterator const &it) const
			{ return (ptr_ < it.ptr_); }
		
		template <class iterator1, class iterator2>
		friend bool	operator<(iterator1 const &it1, iterator2 const &it2);

		bool		operator>(iterator const &it) const
			{ return (ptr_ < it.ptr_); }
		
		template <class iterator1, class iterator2>
		friend bool	operator>(iterator1 const &it1, iterator2 const &it2);


		bool		operator<=(iterator const &it) const
			{ return (ptr_ <= it.ptr_); }

		bool		operator>=(iterator const &it) const
			{ return (ptr_ >= it.ptr_); }

		iterator	&operator+=(int const n)
			{ return (ptr_ + n); }

		iterator	&operator-=(int const n)
			{ return (ptr_ - n); }

		T			&operator[](int const n)
			{ return *(ptr_ + n); }

	private:

		T	*ptr_;

};

template <class T>
class const_iterator : public base_iterator<std::random_access_iterator_tag, T>{
	
	public:

		const_iterator(void) : ptr_(0) {}

		const_iterator(const_iterator const &it) { *this = it; }

		const_iterator(const T *valPtr) : ptr_(valPtr) {}

		const_iterator(iterator<T> const &it) : ptr_(it.base()) {}

		~const_iterator(void) {}

		const T	*base(void) const { return ptr_; }

		/********************************/
		/***    OPERATOR OVERLOADS    ***/
		/********************************/

		const_iterator	&operator=(const_iterator const &it) { ptr_ = it.ptr_; return *this; }

		bool			operator==(const_iterator const &it) const { return (ptr_ == it.ptr_); }

		bool			operator!=(const_iterator const &it) const { return (ptr_ != it.ptr_); }

		const T 		&operator*(void) const { return *ptr_; }

		const T 		*operator->(void) const { return ptr_; }

		const_iterator	&operator++(void) { ptr_++; return *this; }

		const_iterator	operator++(int) { const T *retPtr = ptr_; ptr_++; return retPtr; }
		
		const_iterator	&operator--(void) { ptr_--; return *this; }

		const_iterator	operator--(int) { const T *retPtr = ptr_; ptr_--; return retPtr; }

		const_iterator	operator+(int const n) { const T *retPtr = ptr_ + n; return retPtr; }
		friend const_iterator	operator+(const int n, const_iterator const &it) { return (it.ptr_ + n); }

		const_iterator	operator-(int const n) { const T *retPtr = ptr_ - n; return retPtr; }
		friend const_iterator operator-(const int n, const_iterator const &it) { return (it.ptr_ - n); }
		
		ptrdiff_t		operator-(const_iterator const &it) { return (ptr_ - it.ptr_); }

		bool			operator<(const_iterator const &it) const { return (ptr_ < it.ptr_); }
		template <class iterator1, class iterator2>
		friend bool		operator<(iterator1 const &it1, iterator2 const &it2);

		bool			operator>(const_iterator const &it) const { return (ptr_ > it.ptr_); }	
		template <class iterator1, class iterator2>
		friend bool		operator>(iterator1 const &it1, iterator2 const &it2);

		bool			operator<=(const_iterator const &it) const { return (ptr_ <= it.ptr_); }

		bool			operator>=(const_iterator const &it) const { return (ptr_ >= it.ptr_); }

		const_iterator	&operator+=(int const n) { return (ptr_ + n); }

		const_iterator	&operator-=(int const n) { return (ptr_ - n); }

		const_iterator	&operator[](int const n) { return *(ptr_ + n); }

	private:

		const T	*ptr_;

};

template <class iterator1, class iterator2>
bool	operator<(iterator1 const &it1, iterator2 const &it2) {
	return (it1.base() < it2.base());
}

}

#endif
