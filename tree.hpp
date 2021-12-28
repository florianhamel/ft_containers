/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 14:45:56 by fhamel            #+#    #+#             */
/*   Updated: 2021/12/28 01:51:05 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
# define TREE_HPP

# define BLACK 0
# define RED 1
# define LEAF NULL

# include <memory>

# include "utility.hpp"

namespace ft {

template <class Key, class T>
class Node {

	private:

		typedef Key									key_type;
		typedef T									mapped_type;
		typedef pair<const key_type, mapped_type>	value_type;
		typedef Node<key_type, mapped_type>			node;

		bool		color_;
		value_type	data_;
		Node		*parent_;
		node		*left_;
		node		*right_;

	public:

		Node(void) : color_(RED), data_(), parent_(), left_(), right_()
			{ return; }

		Node(const node &N) :
		color_(N.color_), data_(N.data_), parent_(N.parent_), left_(N.left_), right_(N.right_)
			{ return; }

		Node(value_type data, node *parent, node *left, node *right) :
		color_(RED), data_(data), parent_(parent), left_(left), right_(right)
			{ return; }

		~Node(void)
			{ return; }

		node	&operator=(const node &N)
		{
			color_ = N.color_; data_ = N.data_;
			parent_ = N.parent_; left_ = N.left_; right_ = N.right;
			return *this;
		}

		bool	color(void) const
			{ return color_; }
		
		value_type	&data(void)
			{ return data_; }

		const key_type	&key(void) const
			{ return data_.first; }
		
		mapped_type	&mapped(void) const
			{ return data_.second; }
		
		node	*parent(void) const
			{ return parent_; }
		
		node	*leftChild(void) const
			{ return left_; }
		
		node	*rightChild(void) const
			{ return right_; }

		void	setColor(bool color)
			{ color_ = color; }

		void	setMapped(mapped_type x)
			{ data_.second = x; }

		void	setParent(node *N)
			{ parent_ = N; }
		
		void	setLeftChild(node *N)
			{ left_ = N; }
		
		void	setRightChild(node *N)
			{ right_ = N; }
};

template <class Key, class T, class Alloc = std::allocator<Node<Key, T> > 
>
class Tree {

	private:
		
		typedef Key									key_type;
		typedef T									mapped_type;
		typedef Alloc								allocator_type;
		typedef pair<const key_type, mapped_type>	value_type;
		typedef Node<key_type, mapped_type>			node;

		allocator_type	alloc_;
		node			*root_;

	public:

		Tree(void) : root_()
			{ return; }
		
		/* 
		** Temporary copy constructor
		** Needs deep copy implementation
		*/
		Tree(const Tree &tree) : root_(tree.root_)
			{ return; }
		
		~Tree(void)
			{ return; }

		/* 
		** Temporary assignment operator
		** Needs deep copy implementation
		*/
		Tree	&operator=(const Tree &tree)
			{ root_ = tree.root_; return *this; }


		node	*newNode(value_type x, node *P, node *LC, node *RC)
		{
			node	*newN = alloc_.allocate(1, 0);
			// newN->setColor(RED);
			alloc_.construct(newN, Node<Key, T>(x, P, LC, RC));
			return newN;
		}

		node	*rotateLeft(node *N)
		{
			node 	*P = N->parent();
			node	*RC = N->rightChild();
			node	*RLC = RC->leftChild();
			if (RC == LEAF) {
				return NULL;
			}
			if (!isRoot(N) && N->data() < P->data()) {
				P->setLeftChild(RC);
			}
			else if (!isRoot(N) && N->data() > P->data()) {
				P->setRightChild(RC);
			}
			RC->setParent(P);
			RC->setLeftChild(N);
			N->setParent(RC);
			N->setRightChild(RLC);
			if (RLC != LEAF) {
				RLC->setParent(N);
			}
			return RC;
		}

		node	*rotateRight(node *N)
		{
			node	*P = N->parent();
			node	*LC = N->leftChild();
			node	*LRC = LC->rightChild();
			if (LC == LEAF) {
				return NULL;
			}
			if (!isRoot(N) && N->data() < P->data()) {
				P->setLeftChild(LC);
			}
			else if (!isRoot(N) && N->data() > P->data()) {
				P->setRightChild(LC);
			}
			LC->setParent(P);
			LC->setRightChild(N);
			N->setParent(LC);
			N->setLeftChild(LRC);
			if (LRC != LEAF) {
				LRC->setParent(N);
			}
			return LC;
		}

		void	setRoot(node *root)
			{ root_ = root; }

		private:

			bool	isRoot(node *N)
				{ return (N->parent() == NULL); }

};

}

#endif
