/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:27:54 by fhamel            #+#    #+#             */
/*   Updated: 2021/12/20 22:30:08 by fhamel           ###   ########.fr       */
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

	private:

		T	*ptr_;

	public:

		iterator(void)
			{ return; }

		template <class U>
		iterator(iterator<U> const &it)
			{ *this = it; }

		iterator(T *ptr) : ptr_(ptr)
			{ return; }

		~iterator(void)
			{ return; }

		T	*base(void) const
			{ return ptr_; }

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

};

template <class T>
class const_iterator : public base_iterator<std::random_access_iterator_tag, T>{

	private:

		const T	*ptr_;

	public:

		const_iterator(void) : ptr_(0)
			{ return; }

		template <class U>
		const_iterator(const_iterator<U> const &it)
			{ *this = it; }

		const_iterator(const T *valPtr) : ptr_(valPtr)
			{ return; }

		const_iterator(iterator<T> const &it) : ptr_(it.base())
			{ return; }

		~const_iterator(void)
			{ return; }

		const T	*base(void) const
			{ return ptr_; }

		/********************************/
		/***    OPERATOR OVERLOADS    ***/
		/********************************/

		const_iterator	&operator=(const_iterator const &it)
			{ ptr_ = it.ptr_; return *this; }

		bool	operator==(const_iterator const &it) const
			{ return (ptr_ == it.ptr_); }

		bool	operator!=(const_iterator const &it) const
			{ return (ptr_ != it.ptr_); }

		const T	&operator*(void) const
			{ return *ptr_; }

		const T	*operator->(void) const
			{ return ptr_; }

		const_iterator	&operator++(void)
			{ ++ptr_; return *this; }

		const_iterator	operator++(int)
			{ const T *retPtr = ptr_; ptr_++; return retPtr; }
		
		const_iterator	&operator--(void)
			{ --ptr_; return *this; }

		const_iterator	operator--(int)
			{ const T *retPtr = ptr_; --ptr_; return retPtr; }

		const_iterator	operator+(int const n)
			{ const T *retPtr = ptr_ + n; return retPtr; }
		
		friend const_iterator	operator+(const int n, const_iterator const &it)
			{ return (it.ptr_ + n); }

		const_iterator	operator-(int const n)
			{ const T *retPtr = ptr_ - n; return retPtr; }
		
		friend const_iterator operator-(const int n, const_iterator const &it)
			{ return (it.ptr_ - n); }
		
		ptrdiff_t		operator-(const_iterator const &it)
			{ return (ptr_ - it.ptr_); }

		bool			operator<(const_iterator const &it) const
			{ return (ptr_ < it.ptr_); }

		template <class iterator1, class iterator2>
		friend bool		operator<(iterator1 const &it1, iterator2 const &it2);

		bool			operator>(const_iterator const &it) const
			{ return (ptr_ > it.ptr_); }	
		
		template <class iterator1, class iterator2>
		friend bool		operator>(iterator1 const &it1, iterator2 const &it2);

		bool			operator<=(const_iterator const &it) const { return (ptr_ <= it.ptr_); }

		template <class iterator1, class iterator2>
		friend bool		operator>=(iterator1 const &it1, iterator2 const &it2);

		bool			operator>=(const_iterator const &it) const { return (ptr_ >= it.ptr_); }
		
		template <class iterator1, class iterator2>
		friend bool		operator>(iterator1 const &it1, iterator2 const &it2);

		const_iterator	&operator+=(int const n) { return (ptr_ + n); }

		const_iterator	&operator-=(int const n) { return (ptr_ - n); }

		const_iterator	&operator[](int const n) { return *(ptr_ + n); }

};

template <class iterator1, class iterator2>
bool	operator<(iterator1 const &it1, iterator2 const &it2)
	{ return (it1.base() < it2.base()); }

template <class iterator1, class iterator2>
bool	operator>(iterator1 const &it1, iterator2 const &it2)
	{ return (it1.base() > it2.base()); }

template <class iterator1, class iterator2>
bool	operator<=(iterator1 const &it1, iterator2 const &it2)
	{ return (it1.base() <= it2.base()); }

template <class iterator1, class iterator2>
bool	operator>=(iterator1 const &it1, iterator2 const &it2)
	{ return (it1.base() >= it2.base()); }

// template <class Iterator>
// class reverse_iterator {

// 	public:

// 		typedef Iterator								iterator_type;
// 		typedef typename Iterator::value_type			value_type;
// 		typedef typename Iterator::difference_type		difference_type;
// 		typedef typename Iterator::pointer				pointer;
// 		typedef typename Iterator::reference			reference;
// 		typedef typename Iterator::iterator_category	iterator_category;

// 	private:

// 		iterator_type	baseIter_;

// 	public:

// 		reverse_iterator(void) : baseIter_(iterator_type())
// 			{ return; }

// 		explicit reverse_iterator(iterator_type it) : baseIter_(it - 1)
// 			{ return; }

// 		template <class Iter>
// 		reverse_iterator(const reverse_iterator<Iter> &rev_it)
// 			{ *this = rev_it; }

// 		~reverse_iterator(void)
// 			{ return; }

// 		iterator_type	base(void) const
// 			{ return iterator_type(baseIter_ + 1); }

// 		/********************************/
// 		/***    OPERATOR OVERLOADS    ***/
// 		/********************************/

// 		reverse_iterator	&operator=(reverse_iterator const &it)
// 			{ baseIter_ = it.baseIter_; return *this; }

// 		bool		operator==(reverse_iterator const &it) const
// 			{ return (baseIter_ == it.baseIter_); }

// 		bool		operator!=(reverse_iterator const &it) const
// 			{ return (baseIter_ != it.baseIter_); }

// 		value_type	&operator*(void) const
// 			{ return *(baseIter_ + 1); }

// 		value_type	*operator->(void) const
// 			{ return (baseIter_ + 1).base(); }

// 		reverse_iterator	&operator++(void)
// 			{ --baseIter_; return *this; }

// 		reverse_iterator	operator++(int)
// 			{ value_type *retPtr = baseIter_; --baseIter_; return retPtr; }
		
// 		reverse_iterator	&operator--(void)
// 			{ ++baseIter_; return *this; }

// 		reverse_iterator	operator--(int)
// 			{ value_type *retPtr = baseIter_; ++baseIter_; return retPtr; }

// 		reverse_iterator	operator+(int const n)
// 			{ value_type *retPtr = baseIter_ - n; return retPtr; }
		
// 		friend reverse_iterator operator+(const int n, reverse_iterator const &it)
// 			{ return (it.baseIter_ - n); }

// 		reverse_iterator	operator-(int const n)
// 			{ value_type *retPtr = baseIter_ + n; return retPtr; }
		
// 		friend reverse_iterator operator-(const int n, reverse_iterator const &it)
// 			{ return (it.baseIter_ + n); }
		
// 		ptrdiff_t	operator-(reverse_iterator const &it)
// 			{ return (it.baseIter_ - baseIter_); }

// 		bool	operator<(reverse_iterator const &it) const
// 			{ return (baseIter_ > it.baseIter_); }
		
// 		template <class reverse_iterator1, class reverse_iterator2>
// 		friend bool	operator<(reverse_iterator1 const &it1, reverse_iterator2 const &it2);

// 		bool		operator>(reverse_iterator const &it) const
// 			{ return (baseIter_ < it.baseIter_); }
		
// 		template <class reverse_iterator1, class reverse_iterator2>
// 		friend bool	operator>(reverse_iterator1 const &it1, reverse_iterator2 const &it2);


// 		bool	operator<=(reverse_iterator const &it) const
// 			{ return (baseIter_ <= it.baseIter_); }

// 		bool	operator>=(reverse_iterator const &it) const
// 			{ return (baseIter_ >= it.baseIter_); }

// 		reverse_iterator	&operator+=(int const n)
// 			{ return (baseIter_ + n); }

// 		reverse_iterator	&operator-=(int const n)
// 			{ return (baseIter_ - n); }

// 		value_type	&operator[](int const n)
// 			{ return *(baseIter_ + n); }

// };

}

#endif
