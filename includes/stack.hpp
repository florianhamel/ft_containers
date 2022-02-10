/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 01:29:50 by fhamel            #+#    #+#             */
/*   Updated: 2022/02/10 23:36:13 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft {

template <class T, class Container = vector<T> >
class stack {

	public:

		typedef T			value_type;
		typedef Container	container_type;
		typedef size_t		size_type;

	private:

		container_type	container_;

	public:

		stack(const container_type &ctnr = container_type())
			{ container_ = ctnr; }

		stack(const stack &x)
			{ *this = x; }

		~stack(void)
			{ return; }

		stack	&operator=(const stack &x)
			{ container_ = x.container_; return *this; }

		bool	empty(void) const
			{ return container_.empty(); }

		size_type	size(void) const
			{ return container_.size(); }

		value_type	&top(void)
			{ return container_.back(); }

		const value_type	&top(void) const
			{ return container_.back(); }

		void	push(const value_type &val)
			{ container_.push_back(val); }

		void	pop(void)
			{ container_.pop_back(); }

		template <class U, class _Container>
		friend bool	operator==(const stack<U, _Container> &lhs, const stack<U, _Container> &rhs)
			{ return (lhs.container_ == rhs.container_); }

		template <class U, class _Container>
		friend bool	operator<(const stack<U, _Container> &lhs, const stack<U, _Container> &rhs)
			{ return (lhs.container_ < rhs.container_); }

};

template <class T, class Container>
bool	operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{ return !(lhs == rhs); }

template <class T, class Container>
bool	operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{ return !(lhs > rhs); }

template <class T, class Container>
bool	operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{ return (rhs < lhs); }

template <class T, class Container>
bool	operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{ return !(lhs < rhs); }

}

#endif
