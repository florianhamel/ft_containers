/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 17:11:22 by fhamel            #+#    #+#             */
/*   Updated: 2022/02/11 01:17:23 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAITS_HPP
# define TYPE_TRAITS_HPP

# include <iterator> // std::distance

namespace ft {

/********************************/
/***      ITERATOR_TRAITS     ***/
/********************************/

template <class Iterator>
struct iterator_traits {
	typedef typename Iterator::value_type			value_type;
	typedef typename Iterator::difference_type		difference_type;
	typedef typename Iterator::pointer				pointer;
	typedef typename Iterator::reference			reference;
	typedef typename Iterator::iterator_category	iterator_category;
};

template <class T>
struct iterator_traits<T*> {
	typedef T								value_type;
	typedef std::ptrdiff_t					difference_type;
	typedef T*								pointer;
	typedef T&								reference;
	typedef std::random_access_iterator_tag	iterator_category;

};

template <class T>
struct iterator_traits<const T*> {
	typedef T								value_type;
	typedef std::ptrdiff_t					difference_type;
	typedef const T*						pointer;
	typedef const T&						reference;
	typedef std::random_access_iterator_tag	iterator_category;
};

/********************************/
/***         ENABLE_IF        ***/
/********************************/

template <bool, class T = void> struct enable_if {};
template <class T> struct enable_if<true, T> { typedef T type; };

/********************************/
/***     INTEGRAL_CONSTANT    ***/
/********************************/

template <class T, T v>
struct integral_constant {
	typedef T						value_type;
	static const T 					value = v;
	typedef integral_constant<T, v>	type;
};

struct true_type : public integral_constant<bool, true> {};
struct false_type : public integral_constant<bool, false> {};

/********************************/
/***        IS_INTEGRAL       ***/
/********************************/

template <class T> struct is_integral : 					public false_type {};
/* any different type from following types is not integral */
template <> struct is_integral<bool> :						public true_type {};
template <> struct is_integral<char> :						public true_type {};
template <> struct is_integral<char16_t> :					public true_type {};
template <> struct is_integral<char32_t> :					public true_type {};
template <> struct is_integral<wchar_t> :					public true_type {};
template <> struct is_integral<signed char> :				public true_type {};
template <> struct is_integral<short int> :					public true_type {};
template <> struct is_integral<int> :						public true_type {};
template <> struct is_integral<long int> :					public true_type {};
template <> struct is_integral<long long int> :				public true_type {};
template <> struct is_integral<unsigned char> :				public true_type {};
template <> struct is_integral<unsigned short int> :		public true_type {};
template <> struct is_integral<unsigned int> :				public true_type {};
template <> struct is_integral<unsigned long int> :			public true_type {};
template <> struct is_integral<unsigned long long int> :	public true_type {};

/********************************/
/***        IS_ITERATOR       ***/
/********************************/

template <class T>
class has_iterator_category {
	typedef char	one;
	struct two { char firstByte; char secondByte; };
	template <class U> static one test(typename U::iterator_category* = 0);
	template <class U> static two test(...);
	
	public:
		static const bool value = (sizeof(test<T>(0)) == 1);
};

template <class T, class U, bool = has_iterator_category<T>::value>
struct is_conv_to : public integral_constant<bool, std::is_convertible<typename iterator_traits<T>::iterator_category, U>::value> {};

template <class T, class U>
struct is_conv_to<T, U, false> : public false_type {};

template <class Iter>
struct is_input_iterator : public is_conv_to<Iter, std::input_iterator_tag> {};

template <class Iter>
struct is_forward_iterator : public is_conv_to<Iter, std::forward_iterator_tag> {};

template <class Iter>
struct is_random_access_iterator : public is_conv_to<Iter, std::random_access_iterator_tag> {};

}

#endif
