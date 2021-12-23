/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 16:50:10 by fhamel            #+#    #+#             */
/*   Updated: 2021/12/23 16:51:53 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

namespace ft {

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

		template <class InputIterator>
		reverse_iterator(reverse_iterator<InputIterator> const &rev_it) : baseIter_(rev_it.base())
			{ return; }

		~reverse_iterator(void)
			{ return; }

		iterator_type	base(void) const
			{ return baseIter_; }

		/********************************/
		/***    OPERATOR OVERLOADS    ***/
		/********************************/

		template <class InputIterator>
		reverse_iterator	&operator=(reverse_iterator<InputIterator> const &rev_it)
			{ baseIter_ = rev_it.base(); return *this; }

		template <class InputIterator>
		bool				operator==(InputIterator const &rev_it) const
			{ return (base() == rev_it.base()); }

		template <class InputIterator>
		bool				operator!=(InputIterator const &rev_it) const
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
		 
		reverse_iterator	operator+(const int n)
			{ return reverse_iterator(base() - n); }
		
		friend reverse_iterator operator+(const int n, reverse_iterator rev_it)
			{ return rev_it + n; }
	
		reverse_iterator	operator-(const int n)
			{ return reverse_iterator(base() + n); }

		ptrdiff_t	operator-(reverse_iterator const &rev_it)
			{ return rev_it.base() - base(); }

		template <class RandomAccessIterator>
		bool		operator<(RandomAccessIterator const &rev_it)
			{ return (rev_it.base() < base()); }

		template <class RandomAccessIterator>
		bool		operator>(RandomAccessIterator const &rev_it)
			{ return (rev_it.base() > base()); }

		template <class RandomAccessIterator>
		bool		operator<=(RandomAccessIterator const &rev_it)
			{ return (rev_it.base() <= base()); }
		
		template <class RandomAccessIterator>
		bool		operator>=(RandomAccessIterator const &rev_it)
			{ return (rev_it.base() >= base()); }

		reverse_iterator	&operator+=(int const n)
			{ baseIter_ -= n; return *this; }

		reverse_iterator	&operator-=(int const n)
			{ baseIter_ += n; return *this; }

		reference			operator[](int const n)
			{ return *(base().base() - n); }

};

}

#endif
