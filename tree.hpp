/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 14:45:56 by fhamel            #+#    #+#             */
/*   Updated: 2022/01/10 00:26:09 by fhamel           ###   ########.fr       */
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
# include "iterator.hpp"

namespace ft {

template <class Key, class T>
class Node {

	public:

		typedef Key										key_type;
		typedef T										mapped_type;
		typedef ft::pair<const key_type, mapped_type>	value_type;
		typedef Node<key_type, mapped_type>				node;

	private:

		bool			color_;
		value_type		*data_;
		node			*parent_;
		node			*left_;
		node			*right_;

		static node	end_;
		static node	rend_;

	public:

		/* Default */
		Node(void) : color_(RED), data_(), parent_(), left_(), right_()
			{ return; }

		/* Copy */
		Node(const node &N) :
		color_(N.color_), data_(N.data_), parent_(N.parent_), left_(N.left_), right_(N.right_)
			{ return; }

		/* Parameters */
		Node(value_type *data, node *parent = NULL, node *left = NULL, node *right = NULL) :
		color_(RED), data_(data), parent_(parent), left_(left), right_(right)
			{ return; }

		~Node(void)
			{ return; }

		void	base(void) const
			{ return data_; }

		node	&operator=(const node &N)
			{ data_ = N.data_; }

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
		
		value_type	&data(void) const
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

		node	*successor(void) const
		{
		}
		
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
		
		/* Operator Overload */
		template <class _Node>
		bool	operator==(const _Node &N)
			{ return (base() == N.base()); }
		
		template <class _Node>
		bool	operator!=(const _Node &N)
			{ return !(*this == N); }
		
		value_type	&operator*(void) const
			{ return data(); }
		
		value_type	*operator->(void) const
			{ return &(operator*()); }

		node	*next(void) const// ++it
		{
			if (this == &node::end_ || this == &node::rend_) {
				return NULL;
			}
			node	*next = rightChild();
			while (next && next->leftChild()) {
				next = next->leftChild();
			}
			if (!next && parent()) {
				next = parent();
				if (isRightChild()) {
					while (next->isRightChild()) {
						next = next->parent();
					}
					if (next->isRoot()) {
						next = node::endNode();
					}
					else {
						next = next->parent();
					}
				}
			}
			else if (!next && isRoot()) {
				next = node::endNode();
			}
			return next;
		}

		node	*prev(void) const// --it
		{
			if (this == &node::end_ || this == &node::rend_) {
				return parent();
			}
			node	*prev = leftChild();
			while (prev && prev->rightChild()) {
				prev = prev->rightChild();
			}
			if (!prev && parent()) {
				prev = parent();
				if (isLeftChild()) {
					while (prev->isLeftChild()) {
						prev = prev->parent();
					}
					if (prev->isRoot()) {
						prev = node::endNode();
					}
					else {
						prev = prev->parent();
					}
				}
			}
			else if (!prev && isRoot()) {
				prev = node::endNode();
			}
			return prev;
		}

		static node	*endNode(void)
			{ return &node::end_; }

		static node	*rendNode(void)
			{ return &node::rend_; }

		static void	setEndLeft(node *N)
			{ node::end_.setParent(N); }
		
		static void	setRendRight(node *N)
			{ node::rend_.setParent(N); }

};

// Static variables declaration
template <class Key, class T>
Node<Key, T>	Node<Key, T>::end_ = Node<Key, T>(NULL);

template <class Key, class T>
Node<Key, T>	Node<Key, T>::rend_ = Node<Key, T>(NULL);

template <
	class Key,
	class T,
	class Compare,
	class PairAlloc,
	class Alloc = std::allocator<Node<Key, T> >,
	class Iterator = bi_iterator<Node<Key, T> >
>
class Tree {

	private:

		typedef Key										key_type;
		typedef T										mapped_type;
		typedef ft::pair<const key_type, mapped_type>	value_type;
		typedef Compare									key_compare;
		typedef PairAlloc								pair_allocator_type;
		typedef Alloc									allocator_type;
		typedef size_t									size_type;
		typedef Node<key_type, mapped_type>				node;
		typedef Iterator								iterator;

		pair_allocator_type	pairAlloc_;
		allocator_type		alloc_;
		key_compare			comp_;
		node				*root_;

	public:

		Tree(void) :
		pairAlloc_(), alloc_(), comp_(), root_()
			{ return; }

		Tree(const key_compare &comp,
		const pair_allocator_type &pairAlloc,
		const allocator_type &alloc = allocator_type()) :
		pairAlloc_(pairAlloc), alloc_(alloc), comp_(comp), root_()
			{ return; }

		Tree(const Tree &t)
			{ *this = t; }

		~Tree(void)
			{ deleteTree(root()); }	

		node	*root(void) const
			{ return root_; }

		void	setRoot(node *root)
			{ root_ = root; }

		void	copyTree(node *src, node *dst)
		{
			if (!src) {
				return;
			}
			if (src->leftChild()) {
				dst->setLeftChild(newNode(src->leftChild()->data()));
				dst->leftChild()->setParent(dst);
			}
			if (src->rightChild()) {
				dst->setRightChild(newNode(src->rightChild()->data()));
				dst->rightChild()->setParent(dst);
			}
			copyTree(src->leftChild(), dst->leftChild());
			copyTree(src->rightChild(), dst->rightChild());
		}

		Tree	&operator=(const Tree &t)
		{
			root_ = newNode(t.root()->data());
			copyTree(t.root(), root());
			return *this;
		}
		
		/********************************/
		/***          INSERT          ***/
		/********************************/
		/* 
		** /!\ Careful with checking if parent/uncle color is BLACK with
		** parentColor()/uncleColor() == BLACK -> parent/uncle may just not exist
		*/
		
		/*
		** Cases 1 -> 3 for left side and 4 -> 6 for symetrical right side
		*/
	
		int		checkInsertViolations(node *N)
		{
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
			int caseIndex = checkInsertViolations(N);
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

		ft::pair<iterator, bool>	insertNode(const value_type &val)
		{
			node	*N = newNode(val);
			ft::pair<iterator, bool>	retPair = ft::make_pair<iterator, bool>(iterator(N), true);
			if (root_ == NULL) {
				root_ = N;
				updateEndNodes();
				return retPair;
			}
			node	*current = root_;
			while (current != NULL) {
				if (!comp_(N->key(), current->key()) && !comp_(current->key(), N->key())) {
					retPair.second = false;
					current->setMapped(val.second);
					return retPair;
				}
				if (comp_(N->key(), current->key())) {
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
			updateEndNodes();
			return retPair;
		}

		/********************************/
		/***          DELETE          ***/
		/********************************/
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
				updateEndNodes();
			}
			else if (N->leftChild() == NULL || N->rightChild() == NULL) {
				if (!checkRedCase(N)) {
					doubleBlack = true;
				}
				N = deleteReplace(N);
				if (doubleBlack) {
					fixDoubleBlack(N);
				}
				updateEndNodes();
			}
			else {
				replace = inOrderPredecessor(N);
				pairAlloc_.destroy(&N->data());
				pairAlloc_.construct(&N->data(), value_type(replace->data()));
				deleteNode(replace);
			}
		}

		size_type countNodes(const key_type &k, node *current, int count)
		{
			if (current == NULL) {
				return count;
			}
			if (current->key() == k) {
				return count + 1;
			}
			return (searchDelete(k, current->leftChild(), count) +
			searchDelete(k, current->rightChild(), count));
		}

		size_type searchDelete(const key_type &k, node *current, int count)
		{
			if (current == NULL) {
				return count;
			}
			if (!comp_(k, current->key()) && !comp_(current->key(), k)) {
				deleteNode(current);
				return count + 1;
			}
			return (searchDelete(k, current->leftChild(), count) +
			searchDelete(k, current->rightChild(), count));
		}

		/********************************/
		/***           UTILS          ***/
		/********************************/

		node	*newNode(const value_type &val)
		{
			node	*newN = alloc_.allocate(1, 0);
			value_type	*newPair = pairAlloc_.allocate(1, 0);
			pairAlloc_.construct(newPair, ft::pair<const key_type, mapped_type>(val));
			alloc_.construct(newN, node(newPair));
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

		node	*search(const key_type &k, node *current) const
		{
			if (!current) {
				return NULL;
			}
			if (current->key() == k) {
				return current;
			}
			node	*ret = search(k, current->leftChild());
			if (ret) {
				return ret;
			}
			return search(k, current->rightChild());
		}

		node	*max(void) const
		{
			node	*current = root_;
			while (current && current->rightChild()) {
				current = current->rightChild();
			}
			return current;
		}

		node	*min(void) const
		{
			node	*current = root_;
			while (current && current->leftChild()) {
				current = current->leftChild();
			}
			return current;
		}

		void	updateEndNodes(void)
		{
			node::setEndLeft(max());
			node::setRendRight(min());
		}

		node	*lowerBoundNode(const key_type &k, node *current)
		{
			if (!current) {
				return NULL;
			}
			if (!comp_(k, current->key()) && !comp_(current->key(), k)) {
				return current;
			}
			node	*left = !comp_(current->key(), k) ? lowerBoundNode(k, current->leftChild()) : NULL;
			node	*right = !comp_(k, current->key()) ? lowerBoundNode(k, current->rightChild()) : NULL;
			node	*best = NULL;
			if (left || right) {
				if (left && right) {
					best = comp_(left->key(), right->key()) ? left : right;
					if (comp_(k, current->key())) {
						best = comp_(best->key(), current->key()) ? best : current;
					}
				}
				else if (left) {
					best = left;
					if (comp_(k, current->key())) {
						best = comp_(best->key(), current->key()) ? best : current;
					}
				}
				else if (right) {
					best = right;
					if (comp_(k, current->key())) {
						best = comp_(best->key(), current->key()) ? best : current;
					}
				}
			}
			else {
				return (comp_(k, current->key()) ? current : NULL);
			}
			return best;
		}

		node	*upperBoundNode(const key_type &k, node *current)
		{
			node	*left = NULL;
			node	*right = NULL;
			node	*best = NULL;
			if (!current) {
				return NULL;
			}
			if (!comp_(current->key(), k)) {
				left = upperBoundNode(k, current->leftChild());
			}
			if (!comp_(k, current->key())) {
				right = upperBoundNode(k, current->rightChild());
			}
			if (left || right) {
				if (left && right) {
					best = comp_(left->key(), right->key()) ? left : right;
					if (comp_(k, current->key())) {
						best = comp_(best->key(), current->key()) ? best : current;
					}
				}
				else if (left) {
					best = left;
					if (comp_(k, current->key())) {
						best = comp_(best->key(), current->key()) ? best : current;
					}
				}
				else if (right) {
					best = right;
					if (comp_(k, current->key())) {
						best = comp_(best->key(), current->key()) ? best : current;
					}
				}
			}
			else {
				return (comp_(k, current->key()) ? current : NULL);
			}
			return best;
		}

		node	*inOrderPredecessor(node *N) const
		{
			node	*prede = N->leftChild();
			while (prede && prede->rightChild()) {
				prede = prede->rightChild();
			}
			return prede;
		}

		node	*inOrderSuccessor(node *N) const
		{
			node	*succe = N->rightChild();
			while (succe && succe->leftChild()) {
				succe = succe->leftChild();
			}
			return succe;
		}

		/* delete utils */
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
			else if (!N->isRoot() && N->isLeftChild()) {
				N->parent()->setLeftChild(NULL); 
			}
			else if (!N->isRoot()) {
				N->parent()->setRightChild(NULL);
			}
			pairAlloc_.destroy(&N->data());
			pairAlloc_.deallocate(&N->data(), 1);
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
				if (N->isLeftChild()) {
					N->parent()->setLeftChild(N->rightChild());
				}
				else if (N->isRightChild()) {
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
			pairAlloc_.destroy(&N->data());
			pairAlloc_.deallocate(&N->data(), 1);
			alloc_.destroy(N);
			alloc_.deallocate(N, 1);
			return replace;
		}

		void	deleteTree(node *current)
		{
			if (current == NULL) {
				return;
			}
			deleteTree(current->leftChild());
			deleteTree(current->rightChild());
			pairAlloc_.destroy(&current->data());
			pairAlloc_.deallocate(&current->data(), 1);
			alloc_.destroy(current);
			alloc_.deallocate(current, 1);
		} 

};

}

#endif
