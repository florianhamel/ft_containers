/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 16:50:10 by fhamel            #+#    #+#             */
/*   Updated: 2021/12/26 01:06:44 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include "type_traits.hpp"

namespace ft {

/********************************/
/***       BASE_ITERATOR      ***/
/********************************/

template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
struct base_iterator {
	typedef T			value_type;
	typedef Distance	difference_type;
	typedef Pointer		pointer;
	typedef Reference	reference;
	typedef Category	iterator_category;
};

/********************************/
/***         ITERATOR         ***/
/********************************/

template <class T, class Pointer = T*, class Reference = T&>
class ra_iterator : 
public base_iterator<std::random_access_iterator_tag, T,
ptrdiff_t, Pointer, Reference> {

	public:

		typedef typename iterator_traits<ra_iterator>::value_type			value_type;
		typedef typename iterator_traits<ra_iterator>::difference_type		difference_type;
		typedef typename iterator_traits<ra_iterator>::pointer				pointer;
		typedef typename iterator_traits<ra_iterator>::reference			reference;
		typedef typename iterator_traits<ra_iterator>::iterator_category	iterator_category;

	private:

		pointer	ptr_;

	public:

		ra_iterator(void) : ptr_()
			{ return; }

		ra_iterator(ra_iterator<T> const &it) : ptr_(it.base())
			{ return; }

		explicit ra_iterator(pointer ptr) : ptr_(ptr)
			{ return; }

		~ra_iterator(void)
			{ return; }

		pointer	base(void) const
			{ return ptr_; }

		/********************************/
		/***    OPERATOR OVERLOADS    ***/
		/********************************/

		template <class Iter>
		ra_iterator		&operator=(Iter const &it)
			{ ptr_ = it.base(); return *this; }

		template <class Iter>
		bool			operator==(Iter it) const
			{ return (base() == it.base()); }

		template <class Iter>
		bool			operator!=(Iter it) const
			{ return (base() != it.base()); }

		reference		operator*(void) const
			{ return *base(); }

		pointer			operator->(void) const
			{ return base(); }

		ra_iterator		&operator++(void)
			{ ++ptr_; return *this; }

		ra_iterator		operator++(int)
			{ ra_iterator retIter = *this; ++ptr_; return retIter; }
		
		ra_iterator		&operator--(void)
			{ --ptr_; return *this; }

		ra_iterator		operator--(int)
			{ ra_iterator retIter = *this; --ptr_; return retIter; }
		 
		ra_iterator		operator+(difference_type n) const
			{ return ra_iterator(base() + n); }
		
		friend ra_iterator operator+(difference_type n, ra_iterator it)
			{ return it + n; }
	
		ra_iterator		operator-(difference_type n) const
			{ return ra_iterator(base() - n); }

		difference_type	operator-(ra_iterator const &it) const
			{ return base() - it.base(); }

		template <class Iter>
		typename enable_if <
			is_random_access_iterator<Iter>::value,
		bool>::type		operator<(Iter const &it) const
			{ return (base() < it.base()); }

		template <class Iter>
		typename enable_if <
			is_random_access_iterator<Iter>::value,
		bool>::type		operator>(Iter const &it) const
			{ return (base() > it.base()); }

		template <class Iter>
		typename enable_if <
			is_random_access_iterator<Iter>::value,
		bool>::type		operator<=(Iter const &it) const
			{ return (base() <= it.base()); }
		
		template <class Iter>
		typename enable_if <
			is_random_access_iterator<Iter>::value,
		bool>::type		operator>=(Iter const &it) const
			{ return (base() >= it.base()); }

		ra_iterator		&operator+=(difference_type n)
			{ ptr_ += n; return *this; }

		ra_iterator		&operator-=(difference_type n)
			{ ptr_ -= n; return *this; }

		reference		operator[](difference_type n) const
			{ return *(base() + n); }

};

/********************************/
/***     REVERSE_ITERATOR     ***/
/********************************/

template <class Iter>
class reverse_iterator {

	public:

		typedef Iter										iterator_type;
		typedef typename iterator_type::value_type			value_type;
		typedef typename iterator_type::difference_type		difference_type;
		typedef typename iterator_type::pointer				pointer;
		typedef typename iterator_type::reference			reference;
		typedef typename iterator_type::iterator_category	iterator_category;

	private:

		iterator_type	baseIter_;

	public:

		reverse_iterator(void) : baseIter_()
			{ return; }

		explicit reverse_iterator(iterator_type it) : baseIter_(it)
			{ return; }

		template <class _Iter>
		reverse_iterator(const reverse_iterator<_Iter> &rev_it) : baseIter_(rev_it.base())
			{ return; }

		~reverse_iterator(void)
			{ return; }

		iterator_type	base(void) const
			{ return baseIter_; }

		/********************************/
		/***    OPERATOR OVERLOADS    ***/
		/********************************/

		template <class _Iter>
		reverse_iterator	&operator=(reverse_iterator<_Iter> const &rev_it)
			{ baseIter_ = rev_it.base(); return *this; }

		template <class _Iter>
		bool				operator==(_Iter const &rev_it) const
			{ return (base() == rev_it.base()); }

		template <class _Iter>
		bool				operator!=(_Iter const &rev_it) const
			{ return (base() != rev_it.base()); }

		reference			operator*(void) const
			{ iterator_type tmp = baseIter_; return *--tmp; }

		pointer				operator->(void) const
			{ return &operator*(); }

		reverse_iterator	&operator++(void)
			{ --baseIter_; return *this; }

		reverse_iterator	operator++(int)
			{ reverse_iterator retIter = *this; --baseIter_; return retIter; }
		
		reverse_iterator	&operator--(void)
			{ ++baseIter_; return *this; }

		reverse_iterator	operator--(int)
			{ reverse_iterator retIter = *this; ++baseIter_; return retIter; }
		 
		reverse_iterator	operator+(difference_type n) const
			{ return reverse_iterator(base() - n); }
		
		friend reverse_iterator operator+(difference_type n, reverse_iterator rev_it)
			{ return rev_it + n; }
	
		reverse_iterator	operator-(difference_type n) const
			{ return reverse_iterator(base() + n); }

		ptrdiff_t	operator-(reverse_iterator const &rev_it) const
			{ return rev_it.base() - base(); }

		template <class _Iter>
		bool		operator<(_Iter const &rev_it) const
			{ return (rev_it.base() < base()); }

		template <class _Iter>
		bool		operator>(_Iter const &rev_it) const
			{ return (rev_it.base() > base()); }

		template <class _Iter>
		bool		operator<=(_Iter const &rev_it) const
			{ return (rev_it.base() <= base()); }
		
		template <class _Iter>
		bool		operator>=(_Iter const &rev_it) const
			{ return (rev_it.base() >= base()); }

		reverse_iterator	&operator+=(difference_type n)
			{ baseIter_ -= n; return *this; }

		reverse_iterator	&operator-=(difference_type n)
			{ baseIter_ += n; return *this; }

		reference			operator[](difference_type n) const
			{ iterator_type tmp = baseIter_; return *(--tmp - n); }

};

// template <class Iter>
// typename enable_if <
// 	is_random_access_iterator<Iter>::value,
// reverse_iterator<Iter> >::type	operator+(reverse_iterator<Iter> it, const int n)
// 	{ return reverse_iterator<Iter>(base() - n); }

// template <class Iter>
// typename enable_if <
// 	is_random_access_iterator<Iter>::value,
// reverse_iterator<Iter> >::type	operator-(reverse_iterator<Iter> rev_it, const int n)
// 	{ return reverse_iterator<Iter>(base() + n); }

// template <class Iter1, class Iter2>
// typename enable_if <
// 	is_random_access_iterator<Iter1>::value &&
// 	is_random_access_iterator<Iter2>::value,
// ptrdiff_t>::type	operator-(const reverse_iterator<Iter1> &rev_it1, const reverse_iterator<Iter2> &rev_it2)
// 	{ return rev_it2.base() - rev_it1.base(); }

// template <class Iter1, class Iter2>
// typename enable_if <
// 	is_random_access_iterator<Iter1>::value &&
// 	is_random_access_iterator<Iter2>::value,
// bool>::type	operator<(const reverse_iterator<Iter1> &rev_it1, const reverse_iterator<Iter2> &rev_it2)
// 	{ return (rev_it2.base() < rev_it1.base()); }

// template <class Iter1, class Iter2>
// typename enable_if <
// 	is_random_access_iterator<Iter1>::value &&
// 	is_random_access_iterator<Iter2>::value,
// bool>::type	operator>(const reverse_iterator<Iter1> &rev_it1, const reverse_iterator<Iter2> &rev_it2)
// 	{ return (rev_it2.base() > rev_it1.base()); }

// template <class Iter1, class Iter2>
// typename enable_if <
// 	is_random_access_iterator<Iter1>::value &&
// 	is_random_access_iterator<Iter2>::value,
// bool>::type	operator<=(const reverse_iterator<Iter1> &rev_it1, const reverse_iterator<Iter2> &rev_it2)
// 	{ return (rev_it2.base() <= rev_it1.base()); }

// template <class Iter1, class Iter2>
// typename enable_if <
// 	is_random_access_iterator<Iter1>::value &&
// 	is_random_access_iterator<Iter2>::value,
// bool>::type	operator>=(const reverse_iterator<Iter1> &rev_it1, const reverse_iterator<Iter2> &rev_it2)
// 	{ return (rev_it2.base() >= rev_it1.base()); }

// template <class Iter>
// typename enable_if <
// 	is_random_access_iterator<Iter>::value,
// reverse_iterator<Iter> >::type	&operator+=(reverse_iterator<Iter> &rev_it,
// typename Iter::difference_type n)
// 	{ rev_it.baseIter_ -= n; return rev_it; }

// template <class Iter>
// typename enable_if <
// 	is_random_access_iterator<Iter>::value,
// reverse_iterator<Iter> >::type	&operator-=(reverse_iterator<Iter> &rev_it,
// typename Iter::difference_type n)
// 	{ rev_it.baseIter_ += n; return rev_it; }

}

#endif
