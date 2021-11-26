/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rai.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:16:16 by fhamel            #+#    #+#             */
/*   Updated: 2021/11/24 16:28:13 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAI_HPP
# define RAI_HPP

# include "base_rai.hpp"

namespace ft {

template <class T>
class rai : public base_rai<T> {

    public:

		typedef typename base_rai<T>::value_type			value_type;
        typedef typename base_rai<T>::difference_type		difference_type;
        typedef typename base_rai<T>::pointer				pointer;
        typedef typename base_rai<T>::reference				reference;
        typedef typename base_rai<T>::iterator_category		iterator_category;
    
        rai(void) :
        valPtr_(0) {
            return ;
        }

        rai(pointer valPtr) :
        valPtr_(valPtr) {
            return ;
        }

        ~rai(void) {
            return ;
        }

        reference	operator=(const rai<T> it) {
            valPtr_ = it.valPtr_;
            return *this;
        }

        bool	operator==(const rai<T> it) const {
        	return (valPtr_ == it.valPtr_);
        }

        bool	operator!=(const rai<T> it) const {
        	return (valPtr_ != it.valPtr_);
        }

        reference	operator*(void) const {
            return *valPtr_;
        }

        pointer	operator->(void) const {
            return valPtr_;
        }

        rai<T>	&operator++(void) {
            valPtr_++;
            return *this;
        }

        rai<T>	operator++(int) {
            pointer	retPtr = valPtr_;
            valPtr_++;
            return retPtr;
        }
        
        rai<T>	&operator--(void) {
            valPtr_--;
            return *this;
        }

        rai<T>	operator--(int) {
            pointer	retPtr = valPtr_;
            valPtr_--;
            return retPtr;
        }

        rai<T>	operator+(const int n) {
            pointer	retPtr = valPtr_ + n;
            return retPtr;
        }

        friend	rai<T>	operator+(const rai<T> &it, const int n);

    private:
		
		pointer	valPtr_;

};

#endif
