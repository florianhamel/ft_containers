/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 14:45:56 by fhamel            #+#    #+#             */
/*   Updated: 2022/01/05 01:16:57 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
# define TREE_HPP

# define BLACK 0
# define RED 1

# define CASE_OK -1
# define CASE_0 0
# define CASE_1 1
# define CASE_2 2
# define CASE_3 3
# define CASE_4 4
# define CASE_5 5
# define CASE_6 6

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
		value_type	*data_;
		Node		*parent_;
		node		*left_;
		node		*right_;

	public:

		Node(void) : color_(RED), data_(), parent_(), left_(), right_()
			{ return; }

		Node(const node &N) :
		color_(N.color_), data_(N.data_), parent_(N.parent_), left_(N.left_), right_(N.right_)
			{ return; }

		Node(value_type *data, node *parent, node *left, node *right) :
		color_(RED), data_(data), parent_(parent), left_(left), right_(right)
			{ return; }

		~Node(void)
		{ return; }

		node	&operator=(const node &N)
		{
			data_ = N.data_;
			return *this;
		}

		/* Getters */
		bool	color(void) const
			{ return color_; }
		
		bool	parentColor(void) const
		{
			if (parent() == NULL) {
				return BLACK;
			}
			return parent()->color();
		}

		bool	uncleColor(void) const
		{
			if (uncle() == NULL) {
				return BLACK;
			}
			return uncle()->color();
		}

		bool	siblingColor(void) const
		{
			if (sibling() == NULL) {
				return BLACK;
			}
			return sibling()->color();
		}

		bool	leftChildColor(void) const
		{
			if (leftChild() == NULL) {
				return BLACK;
			}
			return leftChild()->color();
		}

		bool	rightChildColor(void) const
		{
			if (rightChild() == NULL) {
				return BLACK;
			}
			return rightChild()->color();
		}
		
		value_type	&data(void)
			{ return *data_; }

		const key_type	&key(void) const
			{ return data_->first; }
		
		mapped_type	&mapped(void) const
			{ return data_->second; }
		
		node	*grandParent(void) const
		{
			if (parent_ == NULL) {
				return NULL;
			}
			return parent_->parent();
		}

		node	*parent(void) const
			{ return parent_; }

		node	*uncle(void) const
		{
			if (parent() == NULL || grandParent() == NULL) {
				return NULL;
			}
			if (parent()->isLeftChild()) {
				return grandParent()->rightChild();
			}
			return grandParent()->leftChild();
		}

		node	*sibling(void) const
		{
			if (parent() == NULL) {
				return NULL;
			}
			if (isLeftChild()) {
				return parent()->rightChild();
			}
			return parent()->leftChild();
		}

		node	*leftChild(void) const
			{ return left_; }
		
		node	*rightChild(void) const
			{ return right_; }

		
		/* Checkers */
		bool	isLeftChild(void) const
		{
			if (parent() == NULL) {
				return false;
			}
			if (parent()->leftChild() == this) {
				return true;
			}
			return false;
		}

		bool	isRightChild(void) const
		{
			if (parent() == NULL) {
				return false;
			}
			if (parent()->rightChild() == this) {
				return true;
			}
			return false;
		}

		bool	isRoot(void) const
			{ return (parent() == NULL); }
		
		bool	isLeaf(void) const
			{ return (leftChild() == NULL && rightChild() == NULL); }

		/* Setters */
		void	setColor(bool color)
			{ color_ = color; }

		void	setMapped(mapped_type x)
			{ data_->second = x; }

		void	setParent(node *N)
			{ parent_ = N; }
		
		void	setLeftChild(node *N)
			{ left_ = N; }
		
		void	setRightChild(node *N)
			{ right_ = N; }
};

template <
	class Key,
	class T,
	class PairAlloc = std::allocator<pair<const Key, T> >,
	class Alloc = std::allocator<Node<Key, T> >,
	class Compare = std::less<Key>
>
class Tree {

	private:

		typedef Key									key_type;
		typedef T									mapped_type;
		typedef Compare								key_compare;
		typedef pair<const key_type, mapped_type>	value_type;
		typedef PairAlloc							pair_allocator_type;
		typedef Alloc								allocator_type;
		typedef Node<key_type, mapped_type>			node;

		pair_allocator_type	pairAlloc_;
		allocator_type		alloc_;
		key_compare			comp;
		node				*root_;

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

		node	*newNode(value_type *x, node *parent, node *leftChild, node *rightChild)
		{
			node	*newN = alloc_.allocate(1, 0);
			alloc_.construct(newN, Node<Key, T>(x, parent, leftChild, rightChild));
			return newN;
		}

		node	*rotateLeft(node *N)
		{
			node 	*parent = N->parent();
			node	*rightChild = N->rightChild();
			node	*rightLeftChild = rightChild->leftChild();
			if (rightChild == NULL) {
				return NULL;
			}
			if (!N->isRoot() && N->data() < parent->data()) {
				parent->setLeftChild(rightChild);
			}
			else if (!N->isRoot() && N->data() > parent->data()) {
				parent->setRightChild(rightChild);
			}
			if (N->isRoot()) {
				root_ = rightChild;
			}
			rightChild->setParent(parent);
			rightChild->setLeftChild(N);
			N->setParent(rightChild);
			N->setRightChild(rightLeftChild);
			if (rightLeftChild != NULL) {
				rightLeftChild->setParent(N);
			}
			return rightChild->leftChild();
		}

		node	*rotateRight(node *N)
		{
			node	*parent = N->parent();
			node	*leftChild = N->leftChild();
			node	*leftRightChild = leftChild->rightChild();
			if (leftChild == NULL) {
				return NULL;
			}
			if (!N->isRoot() && N->data() < parent->data()) {
				parent->setLeftChild(leftChild);
			}
			else if (!N->isRoot() && N->data() > parent->data()) {
				parent->setRightChild(leftChild);
			}
			if (N->isRoot()) {
				root_ = leftChild;
			}
			leftChild->setParent(parent);
			leftChild->setRightChild(N);
			N->setParent(leftChild);
			N->setLeftChild(leftRightChild);
			if (leftRightChild != NULL) {
				leftRightChild->setParent(N);
			}
			return leftChild->rightChild();
		}

		/* 
		** /!\ Careful with checking if parent/uncle color is BLACK with
		** parentColor()/uncleColor() == BLACK -> parent/uncle may just not exist
		*/
		
		/*
		** Cases 1 -> 3 for left side and 4 -> 6 for symetrical right side
		*/
		int		checkInsertViolations(node *N)
		{
			// std::cout << "key node: " << N->key() << std::endl;
			if (N->color() == BLACK) {
				return CASE_OK;
			}
			if (N->parentColor() == RED && N->parent()->isRoot()) {
				return CASE_0;
			}
			if (N->parentColor() == RED && N->uncleColor() == RED) {
				if (N->parent()->isLeftChild()) {
					return CASE_1;
				}
				return CASE_4;
			}
			if (N->parentColor() == RED && N->uncleColor() == BLACK) {
				if (N->parent()->isLeftChild() && N->isRightChild()) {
					return CASE_2;
				}
				if (N->parent()->isLeftChild() && N->isLeftChild()) {
					return CASE_3;
				}
				if (N->parent()->isRightChild() && N->isLeftChild()) {
					return CASE_5;
				}
				return CASE_6;
			}
			return CASE_OK;
		}

		void	fixInsertViolations(node *N)
		{
			int	caseIndex = checkInsertViolations(N);
			while (!(caseIndex == CASE_OK)) {
				if (caseIndex == CASE_0) {
					N->parent()->setColor(BLACK);
					break;
				}
				else if (caseIndex == CASE_1 || caseIndex == CASE_4) {
					N->parent()->setColor(BLACK);
					N->uncle()->setColor(BLACK);
					N->grandParent()->setColor(RED);
					N = N->grandParent();
				}
				else if (caseIndex == CASE_2) {
					N = rotateLeft(N->parent());
				}
				else if (caseIndex == CASE_3) {
					N->parent()->setColor(BLACK);
					N->grandParent()->setColor(RED);
					rotateRight(N->grandParent());
					break;
				}
				else if (caseIndex == CASE_5) {
					N = rotateRight(N->parent());
				}
				else if (caseIndex == CASE_6) {
					N->parent()->setColor(BLACK);
					N->grandParent()->setColor(RED);
					rotateLeft(N->grandParent());
					break;
				}
				caseIndex = checkInsertViolations(N);
			}
		}

		void	insertNode(node *N)
		{
			node	*current = root_;
			if (root_ == NULL) {
				root_ = N;
				return;
			}
			while (current != NULL) {
				if (!comp(N->key(), current->key()) && !comp(current->key(), N->key())) {
					// modifyMapped(); -> modify the value if key already exists
					return ;
				}
				if (comp(N->key(), current->key())) {
					if (current->leftChild() == NULL) {
						current->setLeftChild(N);
						N->setParent(current);
						break;
					}
					else {
						current = current->leftChild();
					}
				}
				else {
					if (current->rightChild() == NULL) {
						current->setRightChild(N);
						N->setParent(current);
						break;
					}
					else {
						current = current->rightChild();
					}
				}
			}
			fixInsertViolations(N);
		}

		node	*inOrderPredecessor(node *N)
		{
			node	*prede = N->leftChild();
			while (prede != NULL && prede->rightChild()) {
				prede = prede->rightChild();
			}
			return prede;
		}

		node	*inOrderSuccessor(node *N)
		{
			node	*succe = N->rightChild();
			while (succe != NULL && succe->leftChild()) {
				succe = succe->leftChild();
			}
			return succe;
		}

		/* Delete */
		bool	checkRedCase(node *N)
		{
			if (N->color() == RED) {
				return true;
			}
			if (N->leftChildColor() == RED || N->rightChildColor() == RED) {
				return true;
			}
			return false;
		}

		void	deleteLeaf(node *N)
		{
			if (N->isRoot()) {
				root_ = NULL;
			}
			if (!N->isRoot() && N->isLeftChild()) {
				N->parent()->setLeftChild(NULL); 
			}
			else if (!N->isRoot()) {
				N->parent()->setRightChild(NULL);
			}
			alloc_.destroy(N);
			alloc_.deallocate(N, 1);
		}

		node	*deleteReplace(node *N)
		{
			node	*replace = NULL;
			if (N->leftChild() == NULL) {
				replace = N->rightChild();
				if (N->isRoot()) {
					root_ = N->rightChild();
				}
				N->rightChild()->setColor(BLACK);
				N->rightChild()->setParent(N->parent());
				if (!N->isRoot() && N->isLeftChild()) {
					N->parent()->setLeftChild(N->rightChild());
				}
				else {
					N->parent()->setRightChild(N->rightChild());
				}
			}
			else {
				replace = N->leftChild();
				if (N->isRoot()) {
					root_ = N->leftChild();
				}
				N->leftChild()->setColor(BLACK);
				N->leftChild()->setParent(N->parent());
				if (!N->isRoot() && N->isLeftChild()) {
					N->parent()->setLeftChild(N->leftChild());
				}
				else if (!N->isRoot()) {
					N->parent()->setRightChild(N->leftChild());
				}
			}
			alloc_.destroy(N);
			alloc_.deallocate(N, 1);
			return replace;
		}

		void	fixDoubleBlack(node *N)
		{
			while (N) {
				if (N->isRoot()) {
				// Break case
					N->setColor(BLACK);
					return;
				}
				if (N->siblingColor() == BLACK) {
				// 1) Sibling is BLACK
					if (N->sibling() &&
					(N->sibling()->leftChildColor() == RED ||
					N->sibling()->rightChildColor() == RED)) {
					// 1) a) Sibling has RED child
						if (N->isLeftChild() &&
						N->sibling()->rightChildColor() == BLACK) {
						// 1) a) i) LEFT sibling and sibling's far child is BLACK
							N->sibling()->setColor(RED);
							N->sibling()->leftChild()->setColor(BLACK);
							rotateRight(N->sibling());
						}
						else if (N->isRightChild() &&
						N->sibling()->leftChildColor() == BLACK) {
						// 1) a) ii) RIGHT sibling and sibling's far child is BLACK
							N->sibling()->setColor(RED);
							N->sibling()->rightChild()->setColor(BLACK);
							rotateLeft(N->sibling());
						}
						if (N->isLeftChild() &&
						N->sibling()->rightChildColor() == RED) {
						// 1) a) iii) LEFT sibling and sibling's far child is RED
							N->sibling()->setColor(N->parentColor());
							N->parent()->setColor(BLACK);
							N->sibling()->rightChild()->setColor(BLACK);
							rotateLeft(N->parent());
						}
						else if (N->isRightChild() &&
						N->sibling()->leftChildColor() == RED) {
						// 1) a) iv) RIGHT sibling and sibling's far child is RED
							N->sibling()->setColor(N->parentColor());
							N->parent()->setColor(BLACK);
							N->sibling()->leftChild()->setColor(BLACK);
							rotateRight(N->parent());
						}
						return;
					}
					else {
					// 1) b) Sibling has BLACK children (or sibling is NULL)
						if (N->sibling()) {
							N->sibling()->setColor(RED);
						}
						if (N->parentColor() == RED) {
							N->parent()->setColor(BLACK);
							return;
						}
						else {
							fixDoubleBlack(N->parent());
							return;
						}
					}
				}
				else {
				// 2) Sibling is RED
					N->sibling()->setColor(N->parentColor());
					N->parent()->setColor(RED);
					if (N->isLeftChild()) {
						rotateLeft(N->parent());
					}
					else {
						rotateRight(N->parent());
					}
					fixDoubleBlack(N);
					return;
				}
			}
		}

		void	deleteNode(node *N)
		{
			node	*replace = NULL;
			bool	doubleBlack = false;
			if (N->isLeaf()) {
				if (!checkRedCase(N)) {
					fixDoubleBlack(N);
				}
				deleteLeaf(N);
			}
			else if (N->leftChild() == NULL || N->rightChild() == NULL) {
				// std::cout << "node key: " << N->key() << std::endl;
				if (!checkRedCase(N)) {
					doubleBlack = true;
				}
				N = deleteReplace(N);
				if (doubleBlack) {
					fixDoubleBlack(N);
				}
			}
			else {
				replace = inOrderPredecessor(N);
				*N = *replace;
				deleteNode(replace);
			}
		}

		// ---------- //
		void	setRoot(node *root)
			{ root_ = root; }

		node	*getRoot(void) const
			{ return root_; }
		// ---------- //

		private:

};

}

#endif
