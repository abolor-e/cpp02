#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:

    int fixed_point;
    static const int fractionalBits;

    public:
    int getRawBits(void) const;
    void    setRawBits(int const raw);
    float fp_calc(int a, int exponent) const;
    float toFloat(void) const;
    int toInt(void) const;

    Fixed();
    Fixed(const int nbr);
    Fixed(const float nbr);
    Fixed(Fixed const &a);
    Fixed &operator=(Fixed const &a);
    ~Fixed();
};

std::ostream	&operator<<(std::ostream &str, Fixed const &fixed_nbr);

#endif