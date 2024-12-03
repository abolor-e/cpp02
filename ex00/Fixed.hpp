#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

/*COPY CONSTRUCTOR
A copy constructor is used to create a NEW object as a copy of an existing
object. This is necessary when an object is passed by value or returned by value 
from a function. It ensures that the new object gets a copy of the internal state
of the original object.*/

typedef std::string str;

class Fixed
{
    private:
        int fp;
        static const int fractionalBits;
    public:
        int getRawBits(void) const;
        void setRawBits(int const raw);
        Fixed();
        ~Fixed();
        Fixed(const Fixed& a);
        Fixed &operator=(const Fixed &a);
};

#endif