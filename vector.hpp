/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:49:35 by fhamel            #+#    #+#             */
/*   Updated: 2021/12/14 01:55:45 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <stdexcept>
# include <iterator> // std::distance()

# include "type_traits.hpp"
# include "random_access_iterator.hpp"

namespace ft {

template <class T, class Alloc = std::allocator<T> >
class vector
{

	public:

		typedef	T									value_type;
		typedef std::size_t							size_type;
		typedef Alloc								allocator_type;
		typedef typename Alloc::reference			reference;
		typedef typename Alloc::const_reference		const_reference;
		typedef typename Alloc::pointer				pointer;
		typedef typename Alloc::const_pointer		const_pointer;
		typedef	iterator<T>							iterator;
		typedef const_iterator<T>					const_iterator;
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

		explicit vector(const allocator_type &alloc = allocator_type()) :
		alloc_(alloc), begin_(0), end_(0), endCap_(0)
			{ return ; }

		explicit vector (size_type n, const value_type &val = value_type(),
        const allocator_type &alloc = allocator_type()) :
		alloc_(alloc), begin_(0), end_(0), endCap_(0)
		{
			begin_ = alloc_.allocate(n, 0);
			endCap_ = end_ = begin_ + n;
			for (pointer tmp = begin_; tmp != end_; ++tmp) {
				*tmp = val;
			}
		}

		~vector()
		{
			for (pointer tmp = begin_; tmp != end_; ++tmp) {
				alloc_.destroy(tmp);
			}
			alloc_.deallocate(begin_, capacity());
		}

		/********************************/
		/***        ITERATORS         ***/
		/********************************/

		iterator	begin(void)
			{ return iterator(begin_); }

		const_iterator	begin(void) const
			{ return const_iterator(begin_); }

		iterator	end(void)
			{ return iterator(end_); }

		const_iterator	end(void) const
			{ return const_iterator(end_); }

		/********************************/
		/***         CAPACITY         ***/
		/********************************/

		size_type	size(void) const
			{ return static_cast<size_type>(end_ - begin_); }
		
		size_type	max_size(void) const
			{ return static_cast<size_type>(alloc_.max_size()); }
 
		// void	resize(size_type n, value_type val = value_type()) {
			// return ;
		// }

		size_type	capacity(void) const
			{ return static_cast<size_type>(endCap_ - begin_); }

		bool	empty(void) const
			{ return (size() != 0); }
		
		// void	reserve(size_type n) {
		// 	return ;
		// }

		/********************************/
		/***      ELEMENT ACCESS      ***/
		/********************************/

		reference			operator[](size_type n)
			{ return *(begin_ + n); }

		const_reference		operator[](size_type n) const
			{ return *(begin_ + n); }

		/*------------------------------------------*/

		reference			at(size_type n)
		{
			if (n < 0 || size() <= n) {
				throw(std::out_of_range("vector"));
			}
			return *(begin_ + n);
		}

		const_reference		at(size_type n) const
		{
			if (n < 0 || size() <= n)
				{ throw(std::out_of_range("vector")); }
			return *(begin_ + n);
		}

		/*------------------------------------------*/

		reference			front(void)
			{ return *begin_; }
		
		const_reference		front(void) const
			{ return *begin_; }

		/*------------------------------------------*/

		reference			back(void)
			{ return *(end_ - 1); }
		
		const_reference		back(void) const
			{ return *(end_ - 1); }

		/********************************/
		/***         MODIFIERS        ***/
		/********************************/

		void	push_back(const value_type &val)
		{
			size_type oldSize = size();
			size_type oldCap = capacity();
			if (end_ == endCap_) {
				size_type sizeAlloc = (oldCap > 0) ? oldCap * 2 : 1;
				pointer newBegin = alloc_.allocate(sizeAlloc, begin_);
				for (pointer src = begin_, dst = newBegin; src != end_; ++src, ++dst) {
					*dst = *src;
					alloc_.destroy(src);
				}
				alloc_.deallocate(begin_, oldCap);
				begin_ = newBegin;
				endCap_ = begin_ + sizeAlloc;
			}
			end_ = begin_ + oldSize + 1;
			back() = val;
		}

		/*------------------------------------------*/

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
			position = static_cast<iterator>(position);
			first = static_cast<InputIterator>(first);
			last = static_cast<InputIterator>(last);
			std::cout << "Hey, this is the input_iterator specialization!\n";
			// parcourir from last to first et insert chaque elem à pos
			// immonde et pas opti mais fonctionnel ?
			// y'a pas vraiment d'autres moyens en fait non ?
		}

		template <class InputIterator>
		typename enable_if<
			is_forward_iterator<InputIterator>::value
		>::type insert(iterator position, InputIterator first, InputIterator last)
		{
			position = static_cast<iterator>(position);
			first = static_cast<InputIterator>(first);
			last = static_cast<InputIterator>(last);
			std::cout << "Hey, this is the forward_iterator specialization!\n";
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
				
			}
		}

		// template <class ForwardIterator>
		// typename enable_if<
		// 	is_forward_iterator<ForwardIterator>::value
		// >::type insert(iterator position, ForwardIterator first, ForwardIterator last)
		// {
		// 	position = static_cast<iterator>(position);
		// 	first = static_cast<InputIterator>(first);
		// 	last = static_cast<InputIterator>(last);
		// 	std::cout << "Hey, this is the forward_iterator specialization!\n";
		// }

		/*------------------------------------------*/
		
		private:

		/********************************/
		/***           UTILS          ***/
		/********************************/

		pointer	realloc_(size_type addCap)
		{
			size_type	oldCap = capacity();
			size_type	totalCap = oldCap + addCap;
			size_type	newCap = (totalCap > 2 * oldCap) ? totalCap : 2 * oldCap;
			pointer		newBegin = alloc_.allocate(newCap, begin_);
			endCap_ = newBegin + newCap;
			return newBegin;
		}

		iterator	insertAlloc_(iterator position, size_type n, const value_type &val)
		{
			if (position == begin_) {
				begin_ = alloc_.allocate(n, 0);
				endCap_ = end_ = begin_ + n;
				for (iterator tmp = begin(); tmp != end(); ++tmp) {
					*tmp = val;
				}
			} else {
				for (size_type i = 0; i < n; ++i, ++position) {
					*position = val;
				}
			}
			return iterator(begin_);
		}

		template <class InputIter>
		typename enable_if<
			is_forward_iterator<InputIter>::value
		>::type	insertAlloc_(iterator position, InputIter first, InputIter last)
		{
			difference_type	lenRange = std::distance(first, last);
			if (position == begin_) {
				begin_ = alloc_.allocate(lenRange, 0);
				endCap_ = begin_ + lenRange;
				end_ = begin_;
				for (iterator tmp = begin(); end_ != endCap_ && first != last; ++tmp, ++first) {
					*tmp = *first;
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
			size_type		oldSize = size();
			size_type		oldCap = capacity();
			difference_type	offPos = position - begin_;
			size_type		sizeAlloc = (oldSize + n > oldCap * 2) ? oldSize + n : oldCap * 2;
			pointer			newBegin = alloc_.allocate(sizeAlloc, begin_);
			iterator		newPos(newBegin + offPos);
			iterator		its(begin_);
			iterator		itd(newBegin);
			for (; its != endCap_ && its != position; ++its, ++itd) {
				*itd = *its;
				alloc_.destroy(its.base());
			}
			while (itd < newPos) {
				++itd;
			}
			for (size_type i = 0; i < n; ++i, ++itd) {
				*itd = val;
			}
			for (; its != end(); ++its, ++itd) {
				*itd = *its;
				alloc_.destroy(its.base());
			}
			alloc_.deallocate(begin_, oldCap);
			begin_ = newBegin;
			end_ = (offPos >= 0 && offPos >= static_cast<long>(oldSize + n)) ?
				begin_ + offPos + n : begin_ + oldSize + n;
			endCap_ = begin_ + sizeAlloc;
			return newPos;
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
			iterator tmp = position;
			for (size_type i = 0; i < n; ++i, ++tmp) {
				*tmp = val;
			}
			end_ += n;
			return position;
		}
};

}

#endif
