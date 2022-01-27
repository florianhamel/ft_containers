/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_random_bonus.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 23:44:45 by fhamel            #+#    #+#             */
/*   Updated: 2022/01/28 00:13:50 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <time.h>

#include "set.hpp"

template <class T>
void	printTree(ft::NodeSet<T> *current)
{
	if (current->parent() == NULL) {
		std::cout << current->key() << std::endl;
	}
	if (current->leftChild() == NULL) {
		std::cout << "NIL" << " ";
	} else {
		std::cout << current->leftChild()->key() << " ";
	}

	if (current->rightChild() == NULL) {
		std::cout << "NIL" << " ";
	} else {
		std::cout << current->rightChild()->key() << " ";
	}

	std::cout << "\n-----\n";
	if (current->leftChild() != NULL) {
		printTree(current->leftChild());
	}
	if (current->rightChild() != NULL) {
		printTree(current->rightChild());
	}
	return;
}

int main(void)
{
	ft::set<int>	st;
	ft::set<int>::iterator	it, ite;
	srand(time(NULL));
	for (int i = 0; i < 10; ++i) {
		st.insert(rand() % 100);
	}
	it = st.begin(); ite = st.end();
	for (; it != ite; ++it) {
		std::cout << *it << ": ";
		if (it.base()->color()) {
			std::cout << "RED";
		}
		else {
			std::cout << "BLACK";
		}
		std::cout << " ";
	}
	std::cout << "\n##########\n";
	printTree<int>(st.root());
	return 0;
}