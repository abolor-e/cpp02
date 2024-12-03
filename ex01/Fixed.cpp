#include "Fixed.hpp"
const int Fixed::fractionalBits = 8;

//Default Constructor!
Fixed::Fixed() : fixed_point(0)
{
    std::cout << "Default constructor called" << std::endl;
}

//Param int constructor!
float Fixed::fp_calc(int a, int exponent) const
{
    while (exponent != 1)
    {
        a *= 2;
        exponent--;
    }
    return (a);
}

Fixed::Fixed(const int nbr)
{
    std::cout << "Int constructor called" << std::endl;
    this->fixed_point = nbr * fp_calc(2, this->fractionalBits);
}

//Param floating-point nbr constructor!
Fixed::Fixed(const float nbr)
{
    std::cout << "Float constructor called" << std::endl;
    this->fixed_point = nbr * fp_calc(2, this->fractionalBits);
}

Fixed::Fixed(Fixed const &a)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = a;
}

Fixed &Fixed::operator=(Fixed const &a)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &a)
        this->fixed_point = a.getRawBits();
    return *this;
}

//Destructor!
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

//-----------------------------------------------------//

int Fixed::getRawBits(void) const
{
    return (this->fixed_point);
}

void    Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->fixed_point = raw;
}

float Fixed::toFloat(void) const
{       
    float a = fp_calc(2, this->fractionalBits);
    return (this->fixed_point / a);
}

int Fixed::toInt(void) const
{
    int a = fp_calc(2, this->fractionalBits);
    return (this->fixed_point / a);
}

std::ostream	&operator<<(std::ostream &str, Fixed const &fixed_nbr)
{
	return (str << fixed_nbr.toFloat());
}