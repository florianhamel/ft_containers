/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rai.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:16:16 by fhamel            #+#    #+#             */
/*   Updated: 2021/11/24 15:38:00 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAI_HPP
# define RAI_HPP

# include "base_rai.hpp"

namespace ft {

template <class T>
class rai : public base_rai {

    public:
    
        rai(void) :
        valPtr_(0) {
            return ;
        }

        iterator(T *valPtr) :
        valPtr_(valPtr) {
            return ;
        }

        ~iterator(void) {
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

        base_rai<T>::pointer valPtr_;

};

#endif
