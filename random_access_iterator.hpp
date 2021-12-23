/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:27:54 by fhamel            #+#    #+#             */
/*   Updated: 2021/12/23 16:54:13 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include "type_traits.hpp"

template <class T>
class const_iterator;

namespace ft {

template <class T>
class iterator : public base_iterator<std::random_access_iterator_tag, T> {

	public: 

		typedef typename iterator_traits<iterator>::value_type			value_type;
		typedef typename iterator_traits<iterator>::difference_type		difference_type;
		typedef typename iterator_traits<iterator>::pointer				pointer;
		typedef typename iterator_traits<iterator>::reference			reference;
		typedef typename iterator_traits<iterator>::iterator_category	iterator_category;

	private:

		pointer	ptr_;

	public:

		iterator(void) : ptr_(0)
			{ return; }

		template <class U>
		iterator(iterator<U> it)
			{ *this = it; }

		iterator(pointer ptr) : ptr_(ptr)
			{ return; }

		~iterator(void)
			{ return; }

		pointer	base(void) const
			{ return ptr_; }

		/********************************/
		/***    OPERATOR OVERLOADS    ***/
		/********************************/

		iterator		&operator=(iterator const &it)
			{ ptr_ = it.base(); return *this; }

		template <class InputIterator>
		bool			operator==(InputIterator it) const
			{ return (base() == it.base()); }

		template <class InputIterator>
		bool			operator!=(InputIterator it) const
			{ return (base() != it.base()); }

		reference		operator*(void)
			{ return *base(); }

		pointer			operator->(void)
			{ return base(); }

		iterator		&operator++(void)
			{ ++ptr_; return *this; }

		iterator		operator++(int)
			{ iterator retIter = *this; ++ptr_; return retIter; }
		
		iterator		&operator--(void)
			{ --ptr_; return *this; }

		iterator		operator--(int)
			{ iterator retIter = *this; --ptr_; return retIter; }
		 
		iterator		operator+(const int n)
			{ return iterator(base() + n); }
		
		friend iterator operator+(const int n, iterator it)
			{ return it + n; }
	
		iterator		operator-(const int n)
			{ return iterator(base() - n); }

		difference_type	operator-(iterator const &it)
			{ return base() - it.base(); }

		template <class RandomAccessIterator>
		bool			operator<(RandomAccessIterator const &it)
			{ return (base() < it.base()); }

		template <class RandomAccessIterator>
		bool			operator>(RandomAccessIterator const &it)
			{ return (base() > it.base()); }

		template <class RandomAccessIterator>
		bool			operator<=(RandomAccessIterator const &it)
			{ return (base() <= it.base()); }
		
		template <class RandomAccessIterator>
		bool			operator>=(RandomAccessIterator const &it)
			{ return (base() >= it.base()); }

		iterator		&operator+=(int const n)
			{ ptr_ += n; return *this; }

		iterator		&operator-=(int const n)
			{ ptr_ -= n; return *this; }

		reference		operator[](int const n)
			{ return *(base() + n); }

};

template <class T>
class const_iterator : public base_iterator<std::random_access_iterator_tag, const T> {

	public:

		typedef typename iterator_traits<const_iterator>::value_type		value_type;
		typedef typename iterator_traits<const_iterator>::difference_type	difference_type;
		typedef typename iterator_traits<const_iterator>::pointer			pointer;
		typedef typename iterator_traits<const_iterator>::reference			reference;
		typedef typename iterator_traits<const_iterator>::iterator_category	iterator_category;

	private:

		pointer	ptr_;

	public:

		const_iterator(void) : ptr_(0)
			{ return; }

		template <class U>
		const_iterator(const_iterator<U> it)
			{ *this = it; }

		const_iterator(iterator<T> it) : ptr_(it.base())
			{ return; }

		const_iterator(pointer ptr) : ptr_(ptr)
			{ return; }

		~const_iterator(void)
			{ return; }

		pointer	base(void) const
			{ return ptr_; }

		/********************************/
		/***    OPERATOR OVERLOADS    ***/
		/********************************/

		const_iterator	&operator=(const_iterator const &it)
			{ ptr_ = it.base(); return *this; }

		template <class InputIterator>
		bool			operator==(InputIterator const &it) const
			{ return (base() == it.base()); }

		template <class InputIterator>
		bool			operator!=(InputIterator const &it) const
			{ return (base() != it.base()); }

		reference		operator*(void) const
			{ return *ptr_; }

		pointer			operator->(void) const
			{ return ptr_; }

		const_iterator	&operator++(void)
			{ ++ptr_; return *this; }

		const_iterator	operator++(int)
			{ const_iterator retIter = *this; ++ptr_; return retIter; }
		
		const_iterator	&operator--(void)
			{ --ptr_; return *this; }

		const_iterator	operator--(int)
			{ const_iterator retIter = *this; --ptr_; return retIter; }
		 
		const_iterator	operator+(const int n)
			{ return const_iterator(base() + n); }
		
		friend const_iterator operator+(const int n, const_iterator it)
			{ return it + n; }
	
		const_iterator	operator-(const int n)
			{ return const_iterator(base() - n); }

		difference_type	operator-(const_iterator const &it)
			{ return base() - it.base(); }

		template <class RandomAccessIterator>
		bool			operator<(RandomAccessIterator const &it)
			{ return (base() < it.base()); }

		template <class RandomAccessIterator>
		bool			operator>(RandomAccessIterator const &it)
			{ return (base() > it.base()); }

		template <class RandomAccessIterator>
		bool			operator<=(RandomAccessIterator const &it)
			{ return (base() <= it.base()); }
		
		template <class RandomAccessIterator>
		bool			operator>=(RandomAccessIterator const &it)
			{ return (base() >= it.base()); }

		const_iterator	&operator+=(int const n)
			{ ptr_+= n; return *this; }

		const_iterator	&operator-=(int const n)
			{ ptr_-= n; return *this; }

		reference		operator[](int const n)
			{ return *(base() + n); }

};

}

#endif
