/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:39:56 by fhamel            #+#    #+#             */
/*   Updated: 2021/12/26 17:09:22 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_HPP
# define UTILITY_HPP

namespace ft {

/* pair */
template <class T1, class T2>
struct pair {

	typedef T1	first_type;
	typedef T2	second_type;

	first_type	first;
	second_type	second;

	pair(void) : first(), second()
		{ return; }
	
	template <class T, class U>
	pair(const pair<T, U> &pr) : first(pr.first), second(pr.second)
		{ return; }
	
	pair(const first_type &x, const second_type &y) : first(x), second(y)
		{ return; }

	pair	&operator=(const pair &pr)
		{ first = pr.first; second = pr.second; return *this; }

	template <class T, class U>
	friend bool	operator==(const pair<T, U> &lhs, const pair<T, U> &rhs)
		{ return ((lhs.first == rhs.first) && (lhs.second == rhs.second)); }

	template <class T, class U>
	friend bool	operator<(const pair<T, U> &lhs, const pair<T, U> &rhs)
		{ return ((lhs.first < rhs.first) || (!(lhs.first > rhs.first) && (lhs.second < rhs.second))); }

};

template <class T1, class T2>
bool	operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{ return !(lhs == rhs); }

template <class T1, class T2>
bool	operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{ return !(lhs > rhs); }

template <class T1, class T2>
bool	operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{ return (rhs < lhs); }

template <class T1, class T2>
bool	operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{ return !(lhs < rhs); }

/* make_pair */
template <class T1, class T2>
pair<T1, T2>	make_pair(T1 x, T2 y)
	{ return pair<T1, T2>(x, y); }

}

#endif
