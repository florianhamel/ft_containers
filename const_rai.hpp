/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_rai.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:36:06 by fhamel            #+#    #+#             */
/*   Updated: 2021/11/24 16:27:08 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_RAI_HPP
# define CONST_RAI_HPP

# include "base_rai.hpp"

namespace ft {

template <class T>
class const_rai : public base_rai<T> {

    public:

		typedef typename base_rai<T>::value_type			value_type;
        typedef typename base_rai<T>::difference_type		difference_type;
        typedef typename base_rai<T>::pointer				pointer;
        typedef typename base_rai<T>::reference				reference;
        typedef typename base_rai<T>::iterator_category		iterator_category;
    
		const_rai(void) :
        valPtr_(0) {
            return ;
        }

        const_rai(pointer valPtr) :
        valPtr_(valPtr) {
            return ;
        }

        ~const_rai(void) {
            return ;
        }

        reference	operator=(const_rai<T> it) {
            valPtr_ = it.valPtr_;
            return *this;
        }

        bool	operator==(const_rai<T> it) const {
            return (valPtr_ == it.valPtr_);
        }

        bool	operator!=(const_rai<T> it) const {
            return (valPtr_ != it.valPtr_);
        }

        reference	operator*(void) const {
            return *valPtr_;
        }

        pointer	operator->(void) const {
            return valPtr_;
        }

        const_rai<T>	&operator++(void) {
            valPtr_++;
            return *this;
        }

        const_rai<T>	operator++(int) {
            pointer	retPtr = valPtr_;
            valPtr_++;
            return retPtr;
        }
        
        const_rai<T>	&operator--(void) {
            valPtr_--;
            return *this;
        }

        const_rai<T>	operator--(int) {
            pointer	retPtr = valPtr_;
            valPtr_--;
            return retPtr;
        }

        const_rai<T>	operator+(const int n) {
            pointer	retPtr = valPtr_ + n;
            return retPtr;
        }

        friend	const_rai<T>	operator+(const_rai<T> &it, const int n);

    private:

		pointer const	valPtr_;

};

#endif
