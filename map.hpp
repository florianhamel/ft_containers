/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:38:55 by fhamel            #+#    #+#             */
/*   Updated: 2022/01/10 00:23:28 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <functional>
# include <memory>

# include "utility.hpp"
# include "iterator.hpp"
# include "tree.hpp"

namespace ft {

template <
	class Key,
	class T,
	class Compare = std::less<Key>,
	class Alloc = std::allocator<pair<const Key, T> >
>
class map {

	class ValueCompare {

		private:
			Compare	comp_;

		public:
			ValueCompare(const Compare &comp = Compare()) : comp_(comp)
				{ return; }

			bool	operator()(const Key &x, const Key &y) const
				{ return comp_(x, y); }
	
	};

	public:
	
		typedef Key															key_type;
		typedef T															mapped_type;
		typedef pair<const key_type, mapped_type>							value_type;
		typedef Compare														key_compare;
		typedef map::ValueCompare											value_compare;
		typedef Alloc														allocator_type;
		typedef typename allocator_type::reference							reference;
		typedef typename allocator_type::const_reference					const_reference;
		typedef typename allocator_type::pointer							pointer;
		typedef typename allocator_type::const_pointer						const_pointer;
		typedef	Node<key_type, mapped_type>									node;
		typedef bi_iterator<node>											iterator;
		typedef bi_iterator<node, const node*, const node&>					const_iterator;
		typedef reverse_iterator<const_iterator>							const_reverse_iterator;
		typedef reverse_iterator<iterator>									reverse_iterator;
		typedef ptrdiff_t													difference_type;
		typedef size_t														size_type;
		typedef Tree<key_type, mapped_type, key_compare, allocator_type>	tree;

	private:

		key_compare		comp_;
		allocator_type	alloc_;
		tree			tree_;
		size_type		size_;
	
	public:

		map(const key_compare &comp = key_compare(),
		const allocator_type &alloc = allocator_type()) :
		comp_(comp), alloc_(alloc), tree_(tree(comp_, alloc_)), size_()
			{ return; }

		map(const map &m)
			{ tree_ = m.tree_; }

		~map(void)
			{ return; }
		
		map	&operator=(const map &m)
			{ tree_ = m.tree_; return *this; }
		
	/********************************/
	/***         ITERATORS        ***/
	/********************************/

		iterator	begin(void)
			{ return iterator(tree_.min()); }

		const_iterator	begin(void) const
			{ return const_iterator(tree_.min()); }
		
		iterator	end(void)
			{ return iterator(node::endNode()); }
		
		const_iterator	end(void) const
			{ return const_iterator(node::endNode()); }

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
			{ return alloc_.max_size(); }

		/********************************/
		/***      ELEMENT ACCESS      ***/
		/********************************/

		mapped_type	&operator[](const key_type &k)
		{
			node	*N = tree_.search(k, tree_.root());
			if (N) {
				return N->mapped();
			}
			value_type	newPair = ft::make_pair<const key_type, mapped_type>(k, mapped_type());
			N = tree_.insertNode(newPair).first.base();
			return N->mapped();
		}

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
		{ tree_.deleteNode(position.base()); }

		/* reference */
		size_type	erase(const key_type &k)
			{ return tree_.searchDelete(k, tree_.root(), 0); }

		/* range */
		void	erase(iterator first, iterator last)
		{
			for (; first != last; ++first) {
				tree_.deleteNode(first.base());
			}
		}
		
		/*** SWAP ***/
		void	swap(map &m)
		{
			node	*tmp = tree_.root();
			tree_.setRoot(m.root());
			m.tree_.setRoot(tmp);
		}

		/*** CLEAR ***/
		void	clear(void)
		{
			tree_.deleteTree(tree_.root());
			tree_.setRoot(NULL);
			tree_.updateEndNodes();
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
			{ return iterator(tree_.search(k, tree_.root())); }

		const_iterator	find(const key_type &k) const
			{ return const_iterator(tree_.search(k, tree_.root())); }

		/*** COUNT ***/
		size_type	count(const key_type &k) const
			{ return countNodes(k, tree_.root(), 0); }
		
		/*** LOWER BOUND ***/
		iterator	lower_bound(const key_type &k)
			{ return iterator(tree_.lowerBoundNode(k, tree_.root())); }

		const_iterator	lower_bound(const key_type &k) const
			{ return const_iterator(tree_.lowerBoundNode(k, tree_.root())); }

		iterator	upper_bound(const key_type &k)
			{ return iterator(tree_.upperBoundNode(k, tree_.root())); }
		
		const_iterator	upper_bound(const key_type &k) const
			{ return const_iterator(tree_.upperBoundNode(k, tree_.root())); }

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
	/***          UTILS           ***/
	/********************************/

		// tmp function for tests
		node	*root(void) const
			{ return tree_.root(); }

};

}

#endif
