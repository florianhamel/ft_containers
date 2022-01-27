/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:09:33 by fhamel            #+#    #+#             */
/*   Updated: 2022/01/27 23:45:00 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define SET_HPP

# include <functional>
# include <memory>

# include "algorithm.hpp"
# include "utility.hpp"

# include "iterator_bonus.hpp"
# include "tree_bonus.hpp"

namespace ft {

template <
	class T,
	class Compare = std::less<T>,
	class Alloc = std::allocator<T>
>
class set {

	class ValueCompare {

		private:
			Compare	comp_;

		public:
			ValueCompare(const Compare &comp = Compare()) : comp_(comp)
				{ return; }

			bool	operator()(const T &x, const T &y) const
				{ return comp_(x.first, y.first); }
	
	};

	public:
	
		typedef T													key_type;
		typedef T													value_type;
		typedef Compare												key_compare;
		typedef Compare												value_compare;
		typedef Alloc												allocator_type;
		typedef typename allocator_type::reference					reference;
		typedef typename allocator_type::const_reference			const_reference;
		typedef typename allocator_type::pointer					pointer;
		typedef typename allocator_type::const_pointer				const_pointer;
		typedef	NodeSet<T>											node;
		typedef bi_iterator_set<node>								iterator;
		typedef bi_iterator_set<node>								const_iterator;
		typedef reverse_iterator_set<const_iterator>				const_reverse_iterator;
		typedef reverse_iterator_set<iterator>						reverse_iterator;
		typedef ptrdiff_t											difference_type;
		typedef size_t												size_type;
		typedef TreeSet<value_type, key_compare, allocator_type>	tree;

	private:

		key_compare		comp_;
		allocator_type	alloc_;
		tree			tree_;
		size_type		size_;
	
	public:

		set(const key_compare &comp = key_compare(),
		const allocator_type &alloc = allocator_type()) :
		comp_(comp), alloc_(alloc), tree_(comp_, alloc_), size_()
			{ return; }

		template <class InputIterator>
		set(InputIterator first, InputIterator last,
		const key_compare &comp = key_compare(),
		const allocator_type &alloc = allocator_type()) :
		comp_(comp), alloc_(alloc), tree_(comp_, alloc_), size_()
		{
			for (; first != last; ++first)  {
				insert(first.operator*());
			}
		}

		set(const set &st) :
		comp_(st.key_comp()), alloc_(st.get_allocator())
			{ *this = st; }

		~set(void)
			{ return; }
		
		set	&operator=(const set &st)
		{
			tree_ = st.tree_;
			size_ = st.size();
			return *this;
		}
		
	/********************************/
	/***         ITERATORS        ***/
	/********************************/

		iterator	begin(void)
			{ return size_ ? iterator(tree_.minNode()) : iterator(NULL); }

		const_iterator	begin(void) const
			{ return size_ ? const_iterator(tree_.minNode()) : const_iterator(NULL); }
		
		iterator	end(void)
			{ return size_ ? iterator(tree_.endNode()) : iterator(NULL); }
		
		const_iterator	end(void) const
			{ return size_ ? const_iterator(tree_.endNode()) : const_iterator(NULL); }

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

		bool	empty(void) const
			{ return (size() == 0); }

		size_type	size(void) const
			{ return size_; }
		
		size_type	max_size(void) const
			{ return tree_.maxSize(); }

		/********************************/
		/***         MODIFIERS        ***/
		/********************************/

		/*** INSERT ***/
		/* single element */
		pair<iterator, bool>	insert(const value_type &val)
		{
			pair<iterator, bool>	retPair = tree_.insertNode(val);
			if (retPair.second) {
				++size_;
			}
			return retPair;
		}

		/* hint */
		iterator	insert(iterator position, const value_type &val)
		{
			position = static_cast<iterator>(position);
			pair<iterator, bool>	retPair = tree_.insertNode(val);
			if (retPair.second) {
				++size_;
			}
			return retPair.first;
		}

		/* range */
		template <class InputIterator>
		void	insert(InputIterator first, InputIterator last)
		{
			pair<iterator, bool>	retPair;
			for (; first != last; ++first) {
				retPair = tree_.insertNode(*first);
				if (retPair.second) {
					++size_;
				}
			}
		}

		/*** ERASE ***/
		/* iterator */
		void	erase(iterator position)
		{
			if (tree_.setDelete(position.base())) {
				--size_;
			}
		}

		/* reference */
		size_type	erase(const key_type &k)
		{
			size_type	ret = tree_.searchDelete(k);
			size_ -= ret;
			return ret;
		}

		/* range */
		void	erase(iterator first, iterator last)
		{
			while (first != last) {
				if (tree_.setDelete((first++).base())) {
					--size_;
				}
			}
		}
		
		/*** SWAP ***/
		void	swap(set &st)
		{
			size_type	tmpSize = size_;
			tree_.swapTreeData(st.tree_);
			size_ = st.size();
			st.size_ = tmpSize;
		}

		/*** CLEAR ***/
		void	clear(void)
		{
			// Set the min/max left/right child to NULL instead
			// of end nodes so the delete algorithm doesn't go into them
			if (tree_.minNode()) {
				tree_.minNode()->setLeftChild(NULL);
			}
			if (tree_.maxNode()) {
				tree_.maxNode()->setRightChild(NULL);
			}
			tree_.deleteTree(tree_.root());
			tree_.setRoot(NULL);
			size_ = 0;
		}

	/********************************/
	/***        OBSERVERS         ***/
	/********************************/

		value_compare	value_comp(void) const
			{ return value_compare(); }
		
		key_compare	key_comp(void) const
			{ return comp_; }

	/********************************/
	/***        OPERATIONS        ***/
	/********************************/

		/*** FIND ***/
		iterator	find(const key_type &k)
		{
			node	*N = tree_.searchNode(k, tree_.root());
			if (N == NULL) {
				return end();
			}
			return iterator(N);
		}

		const_iterator	find(const key_type &k) const
		{
			node	*N = tree_.searchNode(k, tree_.root());
			if (N == NULL) {
				return end();
			}
			return const_iterator(N);
		}

		/*** COUNT ***/
		size_type	count(const key_type &k) const
			{ return tree_.countNodes(k, tree_.root()); }
		
		/*** LOWER BOUND ***/
		iterator	lower_bound(const key_type &k)
			{ return iterator(tree_.lowerBound(k)); }

		const_iterator	lower_bound(const key_type &k) const
			{ return const_iterator(tree_.lowerBound(k)); }

		iterator	upper_bound(const key_type &k)
			{ return iterator(tree_.upperBound(k)); }
		
		const_iterator	upper_bound(const key_type &k) const
			{ return const_iterator(tree_.upperBound(k)); }

		pair<iterator, iterator>	equal_range(const key_type &k)
		{
			iterator	lower = lower_bound(k);
			iterator	upper = upper_bound(k);
			return ft::make_pair<iterator, iterator>(lower, upper);
		}

		pair<const_iterator, const_iterator>	equal_range(const key_type &k) const
		{
			const_iterator	lower = lower_bound(k);
			const_iterator	upper = upper_bound(k);
			return ft::make_pair<const_iterator, const_iterator>(lower, upper);
		}
	
		/********************************/
		/***        ALLOCATOR         ***/
		/********************************/

		allocator_type	get_allocator(void) const
			{ return alloc_; }

		/********************************/
		/***          UTILS           ***/
		/********************************/

		// tmp function for tests
		node	*root(void) const
			{ return tree_.root(); }

};

template <class T, class Compare, class Alloc>
bool	operator==(const set<T, Compare, Alloc> &lhs,
const set<T, Compare, Alloc> &rhs)
{
	if ((lhs.size() != rhs.size()) || !equal(lhs.begin(), lhs.end(), rhs.begin())) {
		return false;
	}
	return true;
}

template <class T, class Compare, class Alloc>
bool	operator<(const set<T, Compare, Alloc> &lhs,
const set<T, Compare, Alloc> &rhs)
{
	if (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())) {
		return true;
	}
	return false;
}

template <class T, class Compare, class Alloc>
bool	operator!=(const set<T, Compare, Alloc> &lhs,
const set<T, Compare, Alloc> &rhs)
	{ return !(lhs == rhs); }

template <class T, class Compare, class Alloc>
bool	operator<=(const set<T, Compare, Alloc> &lhs,
const set<T, Compare, Alloc> &rhs)
	{ return !(lhs > rhs); }

template <class T, class Compare, class Alloc>
bool	operator>(const set<T, Compare, Alloc> &lhs,
const set<T, Compare, Alloc> &rhs)
	{ return (rhs < lhs); }

template <class T, class Compare, class Alloc>
bool	operator>=(const set<T, Compare, Alloc> &lhs,
const set<T, Compare, Alloc> &rhs)
	{ return !(lhs < rhs); }

}

#endif