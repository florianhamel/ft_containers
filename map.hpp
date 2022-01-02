/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:38:55 by fhamel            #+#    #+#             */
/*   Updated: 2022/01/01 21:39:40 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# define BLACK 0
# define RED 1
# define LEAF NULL

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

	public:
	
		typedef Key															key_type;
		typedef T															mapped_type;
		typedef pair<const key_type, mapped_type>							value_type;
		typedef Compare														key_compare;
		// typedef value_compare											map;
		typedef Alloc														allocator_type;
		typedef typename allocator_type::reference							reference;
		typedef typename allocator_type::const_reference					const_reference;
		typedef typename allocator_type::pointer							pointer;
		typedef typename allocator_type::const_pointer						const_pointer;
		// typedef bi_iterator<value_type>									iterator;
		// typedef bi_iterator<value_type, const_pointer, const_reference>	const_iterator;
		// typedef reverse_iterator<const_iterator>							const_reverse_iterator;
		// typedef reverse_iterator<iterator>								reverse_iterator;
		typedef ptrdiff_t													difference_type;
		typedef size_t														size_type;
		typedef Tree<Key, T>												tree;

	private:

		tree	tree_;
	
	public:

	private:
		

};

}

#endif
