/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:49:35 by fhamel            #+#    #+#             */
/*   Updated: 2022/02/12 13:15:22 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <stdexcept>

# include <iostream>

# include "iterator.hpp"
# include "algorithm.hpp"

namespace ft {

template <class T, class Alloc = std::allocator<T> >
class vector {

	public:

		typedef	T									value_type;
		typedef Alloc								allocator_type;
		typedef typename Alloc::reference			reference;
		typedef typename Alloc::const_reference		const_reference;
		typedef typename Alloc::pointer				pointer;
		typedef typename Alloc::const_pointer		const_pointer;
		typedef std::size_t							size_type;
		typedef ra_iterator<T, const T*, const T&>	const_iterator;								
		typedef ra_iterator<T>						iterator;
		typedef reverse_iterator<const_iterator>	const_reverse_iterator;
		typedef reverse_iterator<iterator>			reverse_iterator;
		typedef typename iterator::difference_type	difference_type;

	private:

		Alloc		alloc_;
		pointer		begin_;
		pointer		end_;
		pointer		endCap_;

	public:

		/********************************/
		/***  VECTOR PUBLIC MEMBERS   ***/
		/********************************/

		/* default */
		explicit vector(const allocator_type &alloc = allocator_type()) :
		alloc_(alloc), begin_(0), end_(0), endCap_(0)
			{ return ; }

		/* fill */
		explicit vector(size_type n, const value_type &val = value_type(),
        const allocator_type &alloc = allocator_type()) :
		alloc_(alloc), begin_(0), end_(0), endCap_(0)
			{ assign(n, val); }

		/* range */
		template <class InputIterator>
		vector(InputIterator first, InputIterator last,
		const allocator_type &alloc = allocator_type()) :
		alloc_(alloc), begin_(0), end_(0), endCap_(0)
			{ assign(first, last); }

		/* copy */
		vector(const vector &x)
			{ *this = x; }

		~vector(void)
		{
			for (pointer tmp = begin_; tmp != end_; ++tmp) {
				alloc_.destroy(tmp);
			}
			alloc_.deallocate(begin_, capacity());
		}

		vector	&operator=(const vector &x)
		{
			alloc_ = x.get_allocator();
			if (x.capacity() > 0) {
				begin_ = end_ = alloc_.allocate(x.capacity(), begin_);
				endCap_ = begin_ + x.capacity();
				const_iterator	its = x.begin();
				for (iterator itd = begin(); end_ != endCap_ && its != x.end(); ++itd, ++its) {
					*itd = *its;
					++end_;
				}
			}
			else {
				begin_ = end_ = endCap_ = NULL;
			}
			return *this; 
		}

		/********************************/
		/***        ITERATORS         ***/
		/********************************/

		iterator			begin(void)
			{ return iterator(begin_); }

		const_iterator		begin(void) const
			{ return const_iterator(begin_); }

		iterator			end(void)
			{ return iterator(end_); }

		const_iterator		end(void) const
			{ return const_iterator(end_); }

		reverse_iterator	rbegin(void)
			{ return reverse_iterator(end()); }

		const_reverse_iterator	rbegin(void) const
			{ return const_reverse_iterator(end()); }

		reverse_iterator	rend(void)
			{ return reverse_iterator(begin()); }

		const_reverse_iterator	rend(void) const
			{ return const_reverse_iterator(begin()); }

		/********************************/
		/***         CAPACITY         ***/
		/********************************/

		size_type	size(void) const
			{ return static_cast<size_type>(end_ - begin_); }
		
		size_type	max_size(void) const
			{ return static_cast<size_type>(alloc_.max_size()); }
 
		void	resize(size_type n, value_type val = value_type()) {
			if (n > max_size()) {
				throw std::length_error("vector");
			}
			else if (n <= size()) {
				erase(begin() + n, end());
			}
			else {
				insert(end(), n - size(), val);
			}
		}

		size_type	capacity(void) const
			{ return static_cast<size_type>(endCap_ - begin_); }

		bool	empty(void) const
			{ return (size() == 0); }
		
		void	reserve(size_type n)
		{
			if (n > max_size()) {
				throw std::length_error("allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size");
			}
			else if (n > capacity()) {
				iterator	oldBegin = begin(), oldBegin_ = begin();
				iterator	oldEnd = end();
				begin_ = end_ = realloc_(n);
				endCap_ = begin_ + n;
				for (iterator tmp = begin(); end_ != endCap_ && oldBegin != oldEnd; ++tmp, ++oldBegin) {
					*tmp = *oldBegin;
					++end_;
				}
				if (oldBegin_.base() != begin_) {
					alloc_.deallocate(oldBegin_.base(), oldEnd.base() - oldBegin_.base());
				}
			}
		}

		/********************************/
		/***      ELEMENT ACCESS      ***/
		/********************************/

		reference		operator[](size_type n)
			{ return *(begin_ + n); }

		const_reference	operator[](size_type n) const
			{ return *(begin_ + n); }

		reference		at(size_type n)
		{
			if (n < 0 || size() <= n) {
				throw(std::out_of_range("vector"));
			}
			return *(begin_ + n);
		}

		const_reference	at(size_type n) const
		{
			if (n < 0 || size() <= n) {
				throw(std::out_of_range("vector"));
			}
			return *(begin_ + n);
		}

		reference		front(void)
			{ return *begin_; }
		
		const_reference	front(void) const
			{ return *begin_; }

		reference		back(void)
			{ return *(end_ - 1); }
		
		const_reference	back(void) const
			{ return *(end_ - 1); }

		/********************************/
		/***         MODIFIERS        ***/
		/********************************/

		/*--- assign() ---*/
		/* range */
		template <class InputIterator>
		typename enable_if<
			is_input_iterator<InputIterator>::value &&
			!is_forward_iterator<InputIterator>::value
		>::type	assign(InputIterator first, InputIterator last)
		{
			for (iterator tmp = begin(); tmp != end_; ++tmp) {
				alloc_.destroy(begin_);
			}
			alloc_.deallocate(begin_, capacity());
			begin_ = end_ = endCap_ = 0;
			for (; first != last; ++first) {
				push_back(*first);
				++end_;
			}
		}

		template <class InputIterator>
		typename enable_if<
			is_forward_iterator<InputIterator>::value
		>::type	assign(InputIterator first, InputIterator last)
		{
			for (iterator tmp = begin(); tmp != end(); ++tmp) {
				alloc_.destroy(tmp.base());
			}
			alloc_.deallocate(begin_, capacity());
			begin_ = end_ = endCap_ = NULL;
			insertAlloc_(begin(), first, last);
		}

		/* fill */
		void	assign(size_type n, const value_type &val)
		{
			iterator	it = begin(), ite = end();
			for (; it != ite; ++it) {
				alloc_.destroy(it.base());
			}
			alloc_.deallocate(begin_, capacity());
			begin_ = end_ = endCap_ = NULL;
			insertAlloc_(begin(), n, val);
		}

		/*--- push_back() ---*/
		void	push_back(const value_type &val)
		{
			size_type oldSize = size();
			size_type oldCap = capacity();
			if (end_ == endCap_) {
				size_type sizeAlloc = (oldCap > 0) ? oldCap * 2 : 1;
				pointer newBegin = alloc_.allocate(sizeAlloc, begin_);
				for (pointer src = begin_, dst = newBegin; src != end_; ++src, ++dst) {
					alloc_.construct(dst, *src);
					alloc_.destroy(src);
				}
				alloc_.deallocate(begin_, oldCap);
				begin_ = newBegin;
				end_ = begin_ + oldSize;
				endCap_ = begin_ + sizeAlloc;
			}
			alloc_.construct(end_, val);
			++end_;
		}

		/*--- pop_back() ---*/
		void	pop_back(void)
		{
			if (!empty()) {
				--end_;
				alloc_.destroy(end_);
			}
		}

		/*--- insert() ---*/
		/* single element */
		iterator	insert(iterator position, const value_type &val)
		{
			if (!begin_) {
				return insertAlloc_(position, 1, val);
			}
			if (end_ == endCap_) {
				return insertRealloc_(position, 1, val);
			}
			return insert_(position, 1, val);
		}

		/* fill */
		void	insert(iterator position, size_type n, const value_type &val)
		{
			if (!begin_) {
				insertAlloc_(position, n, val);
			}
			else if (end_ + n > endCap_) {
				insertRealloc_(position, n, val);
			}
			else {
				insert_(position, n, val);
			}
		}

		/* range */
		template <class InputIterator>
		typename enable_if<
			is_input_iterator<InputIterator>::value &&
			!is_forward_iterator<InputIterator>::value
		>::type insert(iterator position, InputIterator first, InputIterator last)
		{
			for (; first != last; ++first, ++position) {
				insert(position, *first);
			}
		}

		template <class InputIterator>
		typename enable_if<
			is_forward_iterator<InputIterator>::value
		>::type insert(iterator position, InputIterator first, InputIterator last)
		{
			difference_type lenRange = std::distance(first, last);
			if (lenRange <= 0) {
				return ;
			}
			else if (!begin_) {
				insertAlloc_(position, first, last);
			}
			else if (end_ + lenRange > endCap_) {
				insertRealloc_(position, first, last);
			}
			else {
				insert_(position, first, last);
			}
		}

		/*--- erase() ---*/
		/* single element */
		iterator	erase(iterator position)
		{
			alloc_.destroy(position.base());
			for (iterator tmp = position; tmp != end() - 1; ++tmp) {
				*tmp = *(tmp + 1);
			}
			--end_;
			return position;
		}

		/* range */
		iterator	erase(iterator first, iterator last)
		{
			difference_type	lenRange = last - first;
			for (iterator tmp = first; tmp != last; ++tmp) {
				alloc_.destroy(tmp.base());
			}
			for (iterator tmp = first; tmp != end() - lenRange; ++tmp) {
				*tmp = *(tmp + lenRange);
			}
			end_ -= lenRange;
			return first;
		}

		/*--- swap() ---*/
		void	swap(vector	&x)
		{
			pointer	tmpBegin = begin_, tmpEnd = end_, tmpEndCap = endCap_;
			begin_ = x.begin_; end_ = x.end_; endCap_ = x.endCap_;
			x.begin_ = tmpBegin; x.end_ = tmpEnd; x.endCap_ = tmpEndCap;
		}

		/*--- clear() ---*/
		void	clear(void)
		{
			for (; end_ != begin_; --end_) {
				alloc_.destroy(end_ - 1);
			}
		}

		/********************************/
		/***         ALLOCATOR        ***/
		/********************************/

		allocator_type	get_allocator(void) const
			{ return alloc_; }

		private:

		/********************************/
		/***           UTILS          ***/
		/********************************/

		pointer	realloc_(size_type addCap)
		{
			size_type	oldCap = capacity();
			size_type	totalCap = oldCap + addCap;
			size_type	newCap = (totalCap > (2 * oldCap)) ? totalCap : (2 * oldCap);
			pointer		newBegin = alloc_.allocate(newCap, begin_);
			endCap_ = newBegin + newCap;
			return newBegin;
		}

		iterator	insertAlloc_(iterator position, size_type n, const value_type &val)
		{
			if (position == begin()) {
				begin_ = end_ = realloc_(n);
				for (size_type i = 0; end_ != endCap_ && i < n; ++i) {
					alloc_.construct(end_, val);
					++end_;
				}
			} else {
				for (size_type i = 0; i < n; ++i, ++position) {
					*position = val;
				}
			}
			return begin();
		}

		template <class InputIter>
		typename enable_if<
			is_forward_iterator<InputIter>::value
		>::type	insertAlloc_(iterator position, InputIter first, InputIter last)
		{
			difference_type	lenRange = std::distance(first, last);
			if (position.base() == begin_) {
				begin_ = end_ = realloc_(lenRange);
				for (; end_ != endCap_ && first != last; ++first) {
					alloc_.construct(end_, *first);
					++end_;
				}
			}
			else {
				for (; first != last; ++first, ++position) {
					*position = *first;
				}
			}
		}
		
		iterator	insertRealloc_(iterator position, size_type n, const value_type &val)
		{
			difference_type	offPos = position - begin();
			iterator		oldBegin = begin();
			iterator		oldEnd = end();
			size_type		oldCap = capacity();
			begin_ = end_ = realloc_(n);
			iterator	itd = begin();
			iterator	its = oldBegin;
			for (; end_ != endCap_ && its != position; ++itd, ++its) {
				*itd = *its;
				alloc_.destroy(its.base());
				++end_;
			}
			for (size_type i = 0; end_ != endCap_ && i < n; ++itd, ++i) {
				*itd = val;
				++end_;
			}
			for (; end_ != endCap_ && its != oldEnd; ++itd, ++its) {
				*itd = *its;
				alloc_.destroy(its.base());
				++end_;
			}
			alloc_.deallocate(oldBegin.base(), oldCap);
			return begin() + offPos;
		}

		template <class InputIterator>
		typename enable_if<
			is_forward_iterator<InputIterator>::value
		>::type	insertRealloc_(iterator position, InputIterator first, InputIterator last)
		{
			difference_type	lenRange = std::distance(first, last);
			iterator		oldBegin = begin();
			iterator		oldEnd = end();
			size_type		oldCap = capacity();
			begin_ = end_ = realloc_(lenRange);
			iterator	itd = begin();
			iterator	its = oldBegin;
			for (; end_ != endCap_ && its != position; ++itd, ++its) {
				*itd = *its;
				alloc_.destroy(its.base());
				++end_;
			}
			for (; end_ != endCap_ && first != last; ++itd, ++first) {
				*itd = *first;
				++end_;
			}
			for (; end_ != endCap_ && its != oldEnd; ++itd, ++its) {
				*itd = *its;
				alloc_.destroy(its.base());
				++end_;
			}
			alloc_.deallocate(oldBegin.base(), oldCap);
		}

		iterator	insert_(iterator position, size_type n, const value_type &val)
		{
			for (iterator it = end() - 1; it != position - 1; --it) {
				*(it + n) = *it;
			}
			iterator	tmp = position;
			for (size_type i = 0; end_ != endCap_ && i < n; ++i, ++tmp) {
				*tmp = val;
				++end_;
			}
			return position;
		}

		template <class InputIterator>
		typename enable_if<
			is_forward_iterator<InputIterator>::value
		>::type	insert_(iterator position, InputIterator first, InputIterator last)
		{
			difference_type	lenRange = std::distance(first, last);
			for (iterator it = end() - 1; it != position - 1; --it) {
				*(it + lenRange) = *it;
			}
			for (; end_ != endCap_ && first != last; ++position, ++first) {
				*position = *first;
				++end_;
			}
		}
};

template <class T, class Alloc>
bool	operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
{
	if ((lhs.size() != rhs.size()) || !equal(lhs.begin(), lhs.end(), rhs.begin())) {
		return false;
	}
	return true;
}

template <class T, class Alloc>
bool	operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
{
	if (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())) {
		return true;
	}
	return false;
}

template <class T, class Alloc>
bool	operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{ return !(lhs == rhs); }

template <class T, class Alloc>
bool	operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{ return !(lhs > rhs); }

template <class T, class Alloc>
bool	operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{ return (rhs < lhs); }

template <class T, class Alloc>
bool	operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{ return !(lhs < rhs); }

}

#endif
