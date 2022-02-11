/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_bonus.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 01:21:17 by fhamel            #+#    #+#             */
/*   Updated: 2022/02/11 01:18:36 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_BONUS_HPP
# define ITERATOR_BONUS_HPP

# include "iterator.hpp"

/********************************/
/***  BIDIRECTIONAL_ITERATOR  ***/
/********************************/

namespace ft {

template <class T, class Pointer = T*, class Reference = T&>
class bi_iterator_set :
public base_iterator<
	std::bidirectional_iterator_tag,
	T,
	ptrdiff_t,
	Pointer,
	Reference
> {

	public:

		typedef typename iterator_traits<bi_iterator_set>::value_type			value_type;
		typedef typename iterator_traits<bi_iterator_set>::difference_type		difference_type;
		typedef typename iterator_traits<bi_iterator_set>::pointer				pointer;
		typedef typename iterator_traits<bi_iterator_set>::reference			reference;
		typedef typename iterator_traits<bi_iterator_set>::iterator_category	iterator_category;
		typedef typename T::value_type											depth_type;

	private:
		
		pointer	ptr_;
	
	public:

		bi_iterator_set(void) : ptr_()
			{ return; }

		bi_iterator_set(bi_iterator_set<T> const &it) : ptr_(it.base())
			{ return; }
		
		bi_iterator_set(bi_iterator_set<T, const T&, const T*> const &it) : ptr_(it.base())
			{ return; }

		explicit bi_iterator_set(pointer ptr) : ptr_(ptr)
			{ return; }

		~bi_iterator_set(void)
			{ return; }
		
		pointer	base(void) const
			{ return ptr_; }

		/********************************/
		/***    OPERATOR OVERLOADS    ***/
		/********************************/

		bi_iterator_set	&operator=(const bi_iterator_set &it)
			{ ptr_ = it.base(); return *this; }

		template <class Iter>
		bool		operator==(const Iter &it) const
			{ return (base() == it.base()); }
		
		template <class Iter>
		bool		operator!=(const Iter &it) const
			{ return !(*this == it); }
			
		const depth_type	&operator*(void) const
			{ return ptr_->constData(); }

		const depth_type	*operator->(void) const
			{ return &(operator*()); }
		
		bi_iterator_set	&operator++(void)
			{ ptr_ = ptr_->next(); return *this; }

		bi_iterator_set	operator++(int)
			{ bi_iterator_set it = bi_iterator_set(ptr_); ptr_ = ptr_->next(); return it; }

		bi_iterator_set	&operator--(void)
			{ ptr_ = ptr_->prev(); return *this; }

		bi_iterator_set	operator--(int)
			{ bi_iterator_set it = bi_iterator_set(ptr_); ptr_ = ptr_->prev(); return it; }

};

template <class Iter>
class reverse_iterator_set {

	public:

		typedef Iter										iterator_type;
		typedef typename iterator_type::value_type			value_type;
		typedef typename iterator_type::difference_type		difference_type;
		typedef typename iterator_type::pointer				pointer;
		typedef typename iterator_type::reference			reference;
		typedef typename iterator_type::iterator_category	iterator_category;
		typedef typename iterator_type::depth_type			depth_type;


	private:

		iterator_type	baseIter_;

	public:

		reverse_iterator_set(void) : baseIter_()
			{ return; }

		explicit reverse_iterator_set(iterator_type it) : baseIter_(it)
			{ return; }

		template <class _Iter>
		reverse_iterator_set(const reverse_iterator_set<_Iter> &rev_it) : baseIter_(rev_it.base())
			{ return; }

		~reverse_iterator_set(void)
			{ return; }

		iterator_type	base(void) const
			{ return baseIter_; }

		/********************************/
		/***    OPERATOR OVERLOADS    ***/
		/********************************/

		template <class _Iter>
		reverse_iterator_set	&operator=(reverse_iterator<_Iter> const &rev_it)
			{ baseIter_ = rev_it.base(); return *this; }

		template <class _Iter>
		bool					operator==(_Iter const &rev_it) const
			{ return (base() == rev_it.base()); }

		template <class _Iter>
		bool					operator!=(_Iter const &rev_it) const
			{ return (base() != rev_it.base()); }

		const depth_type		&operator*(void) const
			{ iterator_type tmp = baseIter_; return *--tmp; }

		const depth_type		*operator->(void) const
			{ return &(operator*()); }

		reverse_iterator_set	&operator++(void)
			{ --baseIter_; return *this; }

		reverse_iterator_set	operator++(int)
			{ reverse_iterator_set retIter = *this; --baseIter_; return retIter; }
		
		reverse_iterator_set	&operator--(void)
			{ ++baseIter_; return *this; }

		reverse_iterator_set	operator--(int)
			{ reverse_iterator_set retIter = *this; ++baseIter_; return retIter; }

};

}

#endif
