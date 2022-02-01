/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_bonus.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:16:33 by fhamel            #+#    #+#             */
/*   Updated: 2022/01/26 03:27:04 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_BONUS_HPP
# define TREE_BONUS_HPP

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

# include "iterator.hpp"

namespace ft {

template <class T>
class NodeSet {

	public:

		typedef T					key_type;
		typedef T					value_type;
		typedef NodeSet<value_type>	node;

	private:

		bool			color_;
		value_type		data_;
		node			*parent_;
		node			*left_;
		node			*right_;

	public:

		/* Default */
		NodeSet(void) :
		color_(RED), data_(), parent_(), left_(), right_()
			{ return; }

		/* Copy */
		NodeSet(const node &N) :
		color_(RED), data_(N.copyData()), parent_(), left_(), right_()
			{ return; }

		/* Parameters */
		NodeSet(value_type data) :
		color_(RED), data_(data), parent_(), left_(), right_()
			{ return; }

		~NodeSet(void)
			{ return; }

		node	*base(void) const
			{ return &data(); }

		node	&operator=(const node &N)
			{ data_ = N.copyData(); return *this; }

		/********************************/
		/***         GETTERS          ***/
		/********************************/
		bool	color(void) const
			{ return color_; }

		value_type	&data(void)
			{ return data_; }
		
		value_type	copyData(void) const
			{ return data_; }

		const value_type &constData(void) const
			{ return data_; }

		const key_type	&key(void) const
			{ return data_; }
		
		node	*parent(void) const
			{ return parent_; }

		node	*leftChild(void) const
			{ return left_; }
		
		node	*rightChild(void) const
			{ return right_; }

		node	*grandParent(void) const
		{
			if (parent_ == NULL) {
				return NULL;
			}
			return parent_->parent();
		}

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

		/********************************/
		/***          COLOR           ***/
		/********************************/
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

		/********************************/
		/***        CHECKERS          ***/
		/********************************/
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


		/********************************/
		/***         SETTERS          ***/
		/********************************/
		void	setColor(bool color)
			{ color_ = color; }

		void	setParent(node *N)
			{ parent_ = N; }
		
		void	setLeftChild(node *N)
			{ left_ = N; }
		
		void	setRightChild(node *N)
			{ right_ = N; }
		

		/********************************/
		/***    OPERATOR OVERLOAD     ***/
		/********************************/
		bool	operator==(const node &N)
			{ return (base() == N.base()); }
		
		bool	operator!=(const node &N)
			{ return !(*this == N); }
		
		value_type	&operator*(void) const
			{ return constData(); }


		node	*next(void) const
		{
			node	*next = rightChild();
			while (next && next->leftChild()) {
				next = next->leftChild();
			}
			if (!next && !isRoot()) {
				next = parent();
				if (isRightChild()) {
					while (next->isRightChild()) {
						next = next->parent();
					}
					if (next->isRoot()) {
						next = next->rightChild();
					}
					else {
						next = next->parent();
					}
				}
			}
			return next;
		}
		
		node	*prev(void) const
		{
			node	*prev = leftChild();
			while (prev && prev->rightChild()) {
				prev = prev->rightChild();
			}
			if (!prev && !isRoot()) {
				prev = parent();
				if (isLeftChild()) {
					while (prev->isLeftChild()) {
						prev = prev->parent();
					}
					if (prev->isRoot()) {
						prev = prev->leftChild();
					}
					else {
						prev = prev->parent();
					}
				}
			}
			return prev;
		}
};

template <
	class T,
	class Compare,
	class PairAlloc,
	class Iterator = bi_iterator_set<NodeSet<T> >
>
class TreeSet {

	private:

		typedef T														key_type;
		typedef T														value_type;
		typedef Compare													key_compare;
		typedef NodeSet<value_type>										node;
		typedef PairAlloc												pair_alloc_type;
		typedef typename pair_alloc_type::template rebind<node>::other	allocator_type;
		typedef size_t													size_type;
		typedef Iterator												iterator;

		key_compare		comp_;
		pair_alloc_type	pairAlloc_;
		allocator_type	alloc_;
		
		node			*root_;
		node			*min_;
		node			*max_;
		node			*end_;
		node			*rend_;

	public:

		/* Default */
		TreeSet(void) :
		comp_(), pairAlloc_(), alloc_(),
		root_(), min_(), max_(), end_(), rend_()
		{
			end_ = alloc_.allocate(1, 0);
			alloc_.construct(end_, node());
			rend_ = alloc_.allocate(1, 0);
			alloc_.construct(rend_, node());
		}

		/* Copy */
		TreeSet(const TreeSet &t)
			{ *this = t; }

		/* Parameters */
		TreeSet(const key_compare &comp,
		const pair_alloc_type &pairAlloc,
		const allocator_type &alloc = allocator_type()) :
		comp_(comp), pairAlloc_(pairAlloc), alloc_(alloc),
		root_(), min_(), max_(), end_(), rend_()
		{
			end_ = alloc_.allocate(1, 0);
			alloc_.construct(end_, node());
			rend_ = alloc_.allocate(1, 0);
			alloc_.construct(rend_, node());
		}

		~TreeSet(void)
		{
			deleteTree(root());
			setRoot(NULL);
		}

		/* Assignment */
		TreeSet	&operator=(const TreeSet &t)
		{
			root_ = t.root() ? newNode(t.root()->data()) : NULL;
			rend_ = newNode(t.rendNode()->data());
			end_ = newNode(t.endNode()->data());
			copyTree(t.root(), root(), t.rendNode(), t.endNode());
			min_ = minFind();
			max_ = maxFind();
			updateEndNodes();
			return *this;
		}
		
		node	*root(void) const
			{ return root_; }

		void	setRoot(node *root)
			{ root_ = root; }
	

		/********************************/
		/***        ROTATIONS         ***/
		/********************************/
		node	*rotateLeft(node *N)
		{
			node 	*parent = N->parent();
			node	*rightChild = N->rightChild();
			node	*rightLeftChild = rightChild->leftChild();
			if (rightChild == NULL) {
				return NULL;
			}
			if (!N->isRoot() && comp_(N->key(), parent->key())) {
			// if (!N->isRoot() && N->data() < parent->data()) {}
				parent->setLeftChild(rightChild);
			}
			else if (!N->isRoot() && comp_(parent->key(), N->key())) {
			// else if (!N->isRoot() && N->data() > parent->data()) {
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
			if (!N->isRoot() && comp_(N->key(), parent->key())) {
			// if (!N->isRoot() && N->data() < parent->data()) {
				parent->setLeftChild(leftChild);
			}
			else if (!N->isRoot() && comp_(parent->key(), N->key())) {
			// else if (!N->isRoot() && N->data() > parent->data()) {
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
			min_->setLeftChild(NULL);
			max_->setRightChild(NULL);
			node	*current = root_;
			while (current != NULL) {
				if (!comp_(N->key(), current->key()) && !comp_(current->key(), N->key())) {
					alloc_.destroy(N);
					alloc_.deallocate(N, 1);
					retPair.first = iterator(current);
					retPair.second = false;
					min_->setLeftChild(rend_);
					max_->setRightChild(end_);
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

		bool	deleteNode(node *N)
		{
			node	*replace = NULL;
			bool	doubleBlack = false;
			bool	ret = false;
			if (N->isLeaf()) {
				if (!checkRedCase(N)) {
					fixDoubleBlack(N);
				}
				deleteLeaf(N);
				return true;
			}
			else if (N->leftChild() == NULL || N->rightChild() == NULL) {
				if (!checkRedCase(N)) {
					doubleBlack = true;
				}
				N = deleteReplace(N);
				if (doubleBlack) {
					fixDoubleBlack(N);
				}
				return true;
			}
			else {
				replace = inOrderPredecessor(N);
				pairAlloc_.destroy(&N->data());
				pairAlloc_.construct(&N->data(), replace->copyData());
				ret = deleteNode(replace);
			}
			return ret;
		}

		size_type	searchDeleteNode(const key_type &k, node *current)
		{
			size_type	count = 0;
			if (current == NULL) {
				return 0;
			}
			if (!comp_(k, current->key()) && !comp_(current->key(), k)) {
				if (deleteNode(current)) {
					return ++count;
				}
			}
			if (comp_(k, current->key())) {
				return (searchDeleteNode(k, current->leftChild()));
			}
			return (searchDeleteNode(k, current->rightChild()));
		}

		bool	setDelete(node *N)
		{
			if (min_ && max_) {
				min_->setLeftChild(NULL);
				max_->setRightChild(NULL);
			}
			bool ret = deleteNode(N);
			updateEndNodes();
			return ret;
		}

		size_type	searchDelete(const key_type &k)
		{
			if (min_ && max_) {
				min_->setLeftChild(NULL);
				max_->setRightChild(NULL);
			}
			size_type ret = searchDeleteNode(k, root());
			updateEndNodes();
			return ret;
		}

		/********************************/
		/***          BOUNDS          ***/
		/********************************/
		node	*lowerBoundNode(const key_type &k, node *current) const
		{
			if (!current || current == rendNode() || current == endNode()) {
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

		node	*lowerBound(const key_type &k) const
		{
			node *ret = lowerBoundNode(k, root());
			return (ret ? ret : endNode());
		}

		node	*upperBoundNode(const key_type &k, node *current) const
		{
			node	*left = NULL;
			node	*right = NULL;
			node	*best = NULL;
			if (!current || current == rendNode() || current == endNode()) {
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

		node	*upperBound(const key_type &k) const
		{
			node *ret = upperBoundNode(k, root());
			return (ret ? ret : endNode());
		}

		/********************************/
		/***           UTILS          ***/
		/********************************/
		node	*newNode(const value_type &val)
		{
			node	*newN = alloc_.allocate(1, 0);
			alloc_.construct(newN, val);
			return newN;
		}

		size_type	maxSize(void) const
			{ return alloc_.max_size(); }

		size_type countNodes(const key_type &k, node *current) const
		{
			size_type	count = 0;
			if (!current || current == rendNode() || current == endNode()) {
				return count;
			}
			if (!comp_(k, current->key()) && !comp_(current->key(), k)) {
				++count;
			}
			return (count + countNodes(k, current->leftChild()) +
			countNodes(k, current->rightChild()));
		}

		node	*searchNode(const key_type &k, node *current) const
		{
			if (!current || current == rendNode() || current == endNode()) {
				return NULL;
			}
			if (!comp_(k, current->key()) && !comp_(current->key(), k)) {
				return current;
			}
			node	*ret = searchNode(k, current->leftChild());
			if (ret) {
				return ret;
			}
			return searchNode(k, current->rightChild());
		}

		node	*endNode(void) const
			{ return end_; }

		node	*rendNode(void) const
			{ return rend_; }
		
		node	*minNode(void) const
			{ return min_; }
		
		node	*maxNode(void) const
			{ return max_; }

		void	updateEndNodes(void)
		{
			min_ = minFind();
			max_ = maxFind();
			if (min_ && max_) {
				min_->setLeftChild(rend_);
				max_->setRightChild(end_);
			}
			rend_->setParent(min_);
			end_->setParent(max_);
		}

		node	*minFind(void) const
		{
			node	*current = root_;
			while (current && current->leftChild()) {
				current = current->leftChild();
			}
			return current;
		}

		node	*maxFind(void) const
		{
			node	*current = root_;
			while (current && current->rightChild()) {
				current = current->rightChild();
			}
			return current;
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

		void	swapTreeData(TreeSet &t)
		{
			node		*tmpRoot = root();
			node		*tmpMin = minNode();
			node		*tmpMax = maxNode();
			node		*tmpRend = rendNode();
			node		*tmpEnd = endNode();

			root_ = t.root();
			min_ = t.minNode();
			max_ = t.maxNode();
			rend_ = t.rendNode();
			end_ = t.endNode();

			t.root_ = tmpRoot;
			t.min_ = tmpMin;
			t.max_ = tmpMax;
			t.rend_ = tmpRend;
			t.end_ = tmpEnd;
		}

		void	copyTree(node *src, node *dst, node *rend, node *end)
		{
			if (!src || src == end || src == rend) {
				return;
			}
			if (src->leftChild() && src->leftChild() != rend) {
				dst->setLeftChild(newNode(src->leftChild()->data()));
				dst->leftChild()->setParent(dst);
			}
			if (src->rightChild() && src->rightChild() != end) {
				dst->setRightChild(newNode(src->rightChild()->data()));
				dst->rightChild()->setParent(dst);
			}
			copyTree(src->leftChild(), dst->leftChild(), rend, end);
			copyTree(src->rightChild(), dst->rightChild(), rend, end);
		}

		void	deleteTree(node *current)
		{
			if (current == NULL) {
				return;
			}
			deleteTree(current->leftChild());
			deleteTree(current->rightChild());
			alloc_.destroy(current);
			alloc_.deallocate(current, 1);
		}

};

}

#endif