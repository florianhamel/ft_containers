/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 17:11:36 by fhamel            #+#    #+#             */
/*   Updated: 2021/12/26 01:15:50 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_HPP
# define ALGORITHM_HPP

namespace ft {

/*--- equal() ---*/
/* equality */
template <class InputIterator1, class InputIterator2>
bool	equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
{
	while (first1 != last1) {
		if (*first1 != *first2) {
			return false;
		}
		++first1; ++first2;
	}
	return true;
}

/* predicate */
template <class InputIterator1, class InputIterator2, class BinaryPredicate>
bool	equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
{
	while (first1 != last1) {
		if (!pred(*first1, *first2)) {
			return false;
		}
		++first1; ++first2;
	}
	return true;
}



/*--- lexicographical_compare()---*/
/* default */
template <class InputIterator1, class InputIterator2>
bool	lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
InputIterator2 first2, InputIterator2 last2)
{
	while (first1 != last1) {
		if (first2 == last2 || *first2 < *first1) {
			return false;
		}
		else if (*first1 < *first2) {
			return true;
		}
		++first1; ++first2;
	}
	return (first2 != last2);
}

/* custom */
template <class InputIterator1, class InputIterator2, class Compare>
bool	lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
InputIterator2 first2, InputIterator2 last2, Compare comp)
{
	while (first1 != last1) {
		if (first2 == last2 || !comp(*first1, *first2)) {
			return false;
		}
		++first1; ++first2;
	}
	return true;
}

}

#endif
