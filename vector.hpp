/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:49:35 by fhamel            #+#    #+#             */
/*   Updated: 2021/11/24 16:28:30 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>

# include "rai.hpp"
# include "const_rai.hpp"
# include "iterator_traits.hpp"

namespace ft {

template < class T, class Alloc = std::allocator<T> >
class vector {

	public:

		/********************************/
		/***  VECTOR PUBLIC TYPEDEFS  ***/
		/********************************/

		typedef	T									value_type;
		typedef Alloc								allocator_type;
		typedef typename Alloc::reference			reference;
		typedef typename Alloc::const_reference		const_reference;
		typedef typename Alloc::pointer				pointer;
		typedef typename Alloc::const_pointer		const_pointer;
		typedef	typename rai<T>						iterator;
		typedef typename const_rai<T>				const_iterator;

		typedef std::size_t							size_type;
		
		/********************************/
		/***  VECTOR PUBLIC MEMBERS   ***/
		/********************************/

		explicit vector(const allocator_type &alloc = allocator_type()) :
		alloc_(alloc), capacity_(0), size_(0) {
			return ;
		}

		explicit vector (size_type n, const value_type &val = value_type(),
        const allocator_type &alloc = allocator_type()) :
		alloc_(alloc), capacity_(n), size_(n) {
			memPtr_ = alloc_.allocate(size_, memPtr_);
			for (size_type i = 0;  i < size_; i++) {
				memPtr_[i] = val;
			}
			return ;
		}

		~vector(void) {
			for (size_type i = 0; i < size_; i++) {
				alloc_.destroy(&memPtr_[i]);
			}
			alloc_.deallocate(memPtr_, capacity_);
			return ;
		}

		/********************************/
		/***        ITERATORS         ***/
		/********************************/

		iterator	begin(void) {
			return iterator(memPtr_);
		}

		const_iterator	begin(void) const {
			return const_iterator(memPtr_);
		}

		iterator	end(void) {
			
			return iterator(&memPtr_[size_]);
		}

		const_iterator	end(void) const {
			return iterator(&memPtr_[size_]);
		}

		/********************************/
		/***         CAPACITY         ***/
		/********************************/

		size_type	size(void) const {
			return size_;
		}
		
		size_type	max_size(void) const {
			return alloc_.max_size();
		}

		// void	resize(size_type n, value_type val = value_type()) {
		// 	return ;
		// }

		size_type	capacity(void) const {
			return capacity_;
		}

		bool	empty(void) const {
			if (size_ == 0) {
				return true;
			}
			return false;
		}

		// void	reserve(size_type n) {
		// 	return ;
		// }

		/********************************/
		/***         MODIFIERS        ***/
		/********************************/
	
		void	push_back(const value_type &val) {
			if (capacity_ == 0) {
				memPtr_ = alloc_.allocate(1, 0);
				capacity_ = 1;
			} else if (size_ + 1 > capacity_) {
				T	*newPtr = alloc_.allocate(2 * capacity_, memPtr_);
				for (size_type i = 0; i < size_; i++) {
					newPtr[i] = memPtr_[i];
					alloc_.destroy(&memPtr_[i]);
				}
				alloc_.deallocate(memPtr_, capacity_);
				memPtr_ = newPtr;
				capacity_ *= 2;
			}
			memPtr_[size_] = val;
			size_++;
			return ;
		}

	private:

		/********************************/
		/***  VECTOR PRIVATE MEMBERS  ***/
		/********************************/
		
		Alloc		alloc_;
		pointer		memPtr_;
		size_type	capacity_;
		size_type	size_;
		
};

}

#endif
