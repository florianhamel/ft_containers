/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:27:54 by fhamel            #+#    #+#             */
/*   Updated: 2021/11/30 16:40:24 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include <iterator>

template <class T>
class const_iterator;

namespace ft {

template <class T>
class iterator {
	
	typedef T								value_type;
	typedef	ptrdiff_t						difference_type;
	typedef T*								pointer;
	typedef	T&								reference;
	typedef std::random_access_iterator_tag	iterator_category;

	public:

		iterator(void) {}

		iterator(iterator const &it) { *this = it; }

		iterator(T *valPtr) : valPtr_(valPtr) {}

		~iterator(void) {}

		T	*base(void) const { return valPtr_; }

		/********************************/
		/***    OPERATOR OVERLOADS    ***/
		/********************************/
		iterator	&operator=(iterator const &it) { valPtr_ = it.valPtr_; return *this; }

		bool		operator==(iterator const &it) const { return (valPtr_ == it.valPtr_); }

		bool		operator!=(iterator const &it) const { return (valPtr_ != it.valPtr_); }

		T			&operator*(void) const { return *valPtr_; }

		T			*operator->(void) const { return valPtr_; }

		iterator	&operator++(void) { valPtr_++; return *this; }

		iterator	operator++(int) { T *retPtr = valPtr_; valPtr_++; return retPtr; }
		
		iterator	&operator--(void) { valPtr_--; return *this; }

		iterator	operator--(int) { T *retPtr = valPtr_; valPtr_--; return retPtr; }

		iterator	operator+(int const n) { T *retPtr = valPtr_ + n; return retPtr; }
		friend iterator operator+(const int n, iterator const &it) { return (it.valPtr_ + n); }

		iterator	operator-(int const n) { T *retPtr = valPtr_ - n; return retPtr; }
		friend iterator operator-(const int n, iterator const &it) { return (it.valPtr_ - n); }
		ptrdiff_t	operator-(iterator const &it) { return (valPtr_ - it.valPtr_); }

		bool		operator<(iterator const &it) const { return (valPtr_ < it.valPtr_); }
		template <class iterator1, class iterator2>
		friend bool	operator<(iterator1 const &it1, iterator2 const &it2);

		bool		operator>(iterator const &it) const { return (valPtr_ < it.valPtr_); }
		template <class iterator1, class iterator2>
		friend bool	operator>(iterator1 const &it1, iterator2 const &it2);


		bool		operator<=(iterator const &it) const { return (valPtr_ <= it.valPtr_); }

		bool		operator>=(iterator const &it) const { return (valPtr_ >= it.valPtr_); }

		iterator	&operator+=(int const n) { return (valPtr_ + n); }

		iterator	&operator-=(int const n) { return (valPtr_ - n); }

		T			&operator[](int const n) { return *(valPtr_ + n); }

	private:

		T	*valPtr_;

};

template <class T>
class const_iterator {
	
	public:

		typedef T								value_type;
		typedef	ptrdiff_t						difference_type;
		typedef T*								pointer;
		typedef	T&								reference;
		typedef std::random_access_iterator_tag	iterator_category;

		const_iterator(void) : valPtr_(0) {}

		const_iterator(const_iterator const &it) { *this = it; }

		const_iterator(const T *valPtr) : valPtr_(valPtr) {}

		const_iterator(iterator<T> const &it) : valPtr_(it.base()) {}

		~const_iterator(void) {}

		const T	*base(void) const { return valPtr_; }

		/********************************/
		/***    OPERATOR OVERLOADS    ***/
		/********************************/
		const_iterator	&operator=(const_iterator const &it) { valPtr_ = it.valPtr_; return *this; }

		bool			operator==(const_iterator const &it) const { return (valPtr_ == it.valPtr_); }

		bool			operator!=(const_iterator const &it) const { return (valPtr_ != it.valPtr_); }

		const T 		&operator*(void) const { return *valPtr_; }

		const T 		*operator->(void) const { return valPtr_; }

		const_iterator	&operator++(void) { valPtr_++; return *this; }

		const_iterator	operator++(int) { const T *retPtr = valPtr_; valPtr_++; return retPtr; }
		
		const_iterator	&operator--(void) { valPtr_--; return *this; }

		const_iterator	operator--(int) { const T *retPtr = valPtr_; valPtr_--; return retPtr; }

		const_iterator	operator+(int const n) { const T *retPtr = valPtr_ + n; return retPtr; }
		friend const_iterator	operator+(const int n, const_iterator const &it) { return (it.valPtr_ + n); }

		const_iterator	operator-(int const n) { const T *retPtr = valPtr_ - n; return retPtr; }
		friend const_iterator operator-(const int n, const_iterator const &it) { return (it.valPtr_ - n); }
		
		ptrdiff_t		operator-(const_iterator const &it) { return (valPtr_ - it.valPtr_); }

		bool			operator<(const_iterator const &it) const { return (valPtr_ < it.valPtr_); }
		template <class iterator1, class iterator2>
		friend bool		operator<(iterator1 const &it1, iterator2 const &it2);

		bool			operator>(const_iterator const &it) const { return (valPtr_ > it.valPtr_); }	
		template <class iterator1, class iterator2>
		friend bool		operator>(iterator1 const &it1, iterator2 const &it2);

		bool			operator<=(const_iterator const &it) const { return (valPtr_ <= it.valPtr_); }

		bool			operator>=(const_iterator const &it) const { return (valPtr_ >= it.valPtr_); }

		const_iterator	&operator+=(int const n) { return (valPtr_ + n); }

		const_iterator	&operator-=(int const n) { return (valPtr_ - n); }

		const_iterator	&operator[](int const n) { return *(valPtr_ + n); }

	private:

		const T	*valPtr_;

};

template <class iterator1, class iterator2>
bool	operator<(iterator1 const &it1, iterator2 const &it2) {
	return (it1.base() < it2.base());
}

}

#endif
