/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 01:51:08 by fhamel            #+#    #+#             */
/*   Updated: 2021/11/22 00:54:58 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include <cstddef>

namespace ft {

template <class T>
	class iterator {

		public:
	
			typedef T									value_type;
			typedef std::ptrdiff_t						difference_type;
			typedef T*									pointer;
			typedef T&									reference;
			typedef std::random_access_iterator_tag		iterator_category;

			iterator(void) :
			valPtr_(0) {
				return ;
			}

			iterator(T *valPtr) :
			valPtr_(valPtr) {
				return ;
			}

			~iterator(void) {
				return ;
			}

			reference	operator=(const iterator it) {
				valPtr_ = it.valPtr_;
				return *this;
			}

			bool	operator==(const iterator it) const {
				return (valPtr_ == it.valPtr_);
			}

			bool	operator!=(const iterator it) const {
				return (valPtr_ != it.valPtr_);
			}

			reference	operator*(void) const {
				return *valPtr_;
			}

			pointer	operator->(void) const {
				return valPtr_;
			}

			iterator<T>	&operator++(void) {
				valPtr_++;
				return *this;
			}

			iterator<T>	operator++(int) {
				pointer	retPtr = valPtr_;
				valPtr_++;
				return retPtr;
			}
			
			iterator<T>	&operator--(void) {
				valPtr_--;
				return *this;
			}

			iterator<T>	operator--(int) {
				pointer	retPtr = valPtr_;
				valPtr_--;
				return retPtr;
			}

			iterator<T>	operator+(const int n) {
				pointer	retPtr = valPtr_ + n;
				return retPtr;
			}

			friend operator+(iterator<T> it, const int n);
		
		private:

			pointer	valPtr_;

	};

	iterator<T>	operator+(iterator<T> it, const int n) {
		return (n + it.valPtr_);
	}

}

#endif
