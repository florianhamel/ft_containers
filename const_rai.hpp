/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_rai.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:36:06 by fhamel            #+#    #+#             */
/*   Updated: 2021/11/24 15:33:10 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_RAI_HPP
# define CONST_RAI_HPP

# include "base_rai.hpp"

namespace ft {

template <class T>
class rai : public base_rai {

    public:
    
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

        base_rai<T>::pointer const  valPtr_;

};

#endif