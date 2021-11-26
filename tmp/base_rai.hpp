/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_rai.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:03:03 by fhamel            #+#    #+#             */
/*   Updated: 2021/11/24 15:29:26 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_RAI_HPP
# define BASE_RAI_HPP

namespace ft {

template <class T>
class base_rai {

    public:

        typedef T									value_type;
        typedef std::ptrdiff_t						difference_type;
        typedef T*									pointer;
        typedef T&									reference;
        typedef std::random_access_iterator_tag		iterator_category;

        base_rai(void) {}
        base_rai(base_rai const &base_rai_inst) { *this = base_rai_inst; }
        virtual ~base_rai(void) {}
        reference   operator=(const base_rai<T> it) { return *this; }

};

}

#endif
