/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:49:35 by fhamel            #+#    #+#             */
/*   Updated: 2021/12/07 20:15:17 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <stdexcept>

# include "random_access_iterator.hpp"
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
		typedef	typename ft::iterator<T>			iterator;
		typedef typename ft::const_iterator<T>		const_iterator;

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

		size_type	size(void) const { return size_; }
		
		size_type	max_size(void) const { return alloc_.max_size(); }

		// void	resize(size_type n, value_type val = value_type()) {
			// return ;
		// }

		size_type	capacity(void) const { return capacity_; }

		bool	empty(void) const { return ((size_ == 0) ? true : false ); }
		
		// void	reserve(size_type n) {
		// 	return ;
		// }

		/********************************/
		/***      ELEMENT ACCESS      ***/
		/********************************/

		reference			operator[](size_type n) { return *(memPtr_ + n); }
		
		const_reference		operator[](size_type n) const { return *(memPtr_ + n); }

		/*------------------------------------------*/

		reference			at(size_type n) {
			if (n < 0 || size_ <= n) {
				throw(std::out_of_range("vector"));
			}
			return *(memPtr_ + n);
		}
		
		const_reference		at(size_type n) const {
			if (n < 0 || size_ <= n) {
				throw(std::out_of_range("vector"));
			}
			return *(memPtr_ + n);
		}

		/*------------------------------------------*/

		reference			front(void) { return *memPtr_; }
		const_reference		front(void) const { return *memPtr_; }

		/*------------------------------------------*/

		reference			back(void) { return *(memPtr_ + (size_ - 1)); }
		const_reference		back(void) const { return *(memPtr_ + (size_ - 1)); }

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
			++size_;
			return ;
		}

		/* single element */
		iterator	insert(iterator position, const value_type &val) {
			iterator	ret = position;
			if (capacity_ == 0) {
				memPtr_ = alloc_.allocate(1);
				++capacity_;
				if (position.base() == 0) {
					*memPtr_ = val;
					ret = this->begin();
				} else {
					*position = val;
				}
			} else if (size_ + 1 > capacity_) {
				std::cout << "REALLOCATION" << std::endl;
				T	*newPtr = alloc_.allocate(2 * capacity_, memPtr_);
				T	*tmpPtr = newPtr;
				capacity_ *= 2;
				for (iterator it = this->begin(); it != position; it++) {
					*tmpPtr = *it; ++tmpPtr;
					alloc_.destroy(it.base());
				}
				ret = iterator(tmpPtr);
				*tmpPtr = val; ++tmpPtr;
				for (iterator it = position; it != this->end(); it++) {
					*tmpPtr = *it; ++tmpPtr;
					alloc_.destroy(it.base());
				}
				alloc_.deallocate(memPtr_, capacity_);
				memPtr_ = newPtr;
			} else {
				std::cout << "NO REALLOCATION" << std::endl;
				for (iterator it = this->end() - 1; it != position - 1; it--) {
					*(it + 1) = *it;
				}
				*position = val;
			}
			++size_;
			return ret;
		}

		/* fill */
		void	insert(iterator position, size_type n, const value_type &val) {
			if (capacity_ == 0) {
				memPtr_ = alloc_.allocate(n);
				capacity_ = n;
				T	*tmpPtr = memPtr_;
				if (position.base() == 0) {
					for (size_type i = 0; i < n; i++) {
						*tmpPtr = val; ++tmpPtr;
					}
				} else {
					for (size_type i = 0; i < n; i++) {
						*position = val; ++position;
					}
				}
			} else if (size_ + n > capacity_) {
				std::cout << "REALLOCATION" << std::endl;
				size_type	sizeAlloc = ((size_ + n > 2 * capacity_) ? size_ + n : 2 * capacity_);
				T	*newPtr = alloc_.allocate(sizeAlloc, memPtr_);
				T	*tmpPtr = newPtr;
				for (iterator it = this->begin(); it != position; it++) {
					*tmpPtr = *it; ++tmpPtr;
					alloc_.destroy(it.base());
				}
				for (size_type i = 0; i < n; i++) {
					*tmpPtr = val; ++tmpPtr;
				}
				for (iterator it = position; it != this->end(); it++) {
					*tmpPtr = *it; ++tmpPtr;
					alloc_.destroy(it.base());
				}
				alloc_.deallocate(memPtr_, capacity_);
				memPtr_ = newPtr;
				capacity_ = sizeAlloc;
			} else {
				std::cout << "NO REALLOCATION" << std::endl;
				for (iterator it = this->end() - 1; it != position - 1; it--) {
					*(it + n) = *it;
				}
				for (size_type i = 0; i < n; i++) {
					*position = val; ++position;
				}
			}
			size_ += n;
		}

		/* range */
		// template <class InputIterator>
		// void	insert(iterator position, InputIterator first, InputIterator last) {}

	private:
		
		Alloc		alloc_;
		pointer		memPtr_;
		size_type	capacity_;
		size_type	size_;
		
};

}

#endif
