#include "Fixed.hpp"
const int Fixed::fractionalBits = 8;

//Default Constructor!
Fixed::Fixed() : fixed_point(0)
{
    //std::cout << "Default constructor called" << std::endl;
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
    //std::cout << "Int constructor called" << std::endl;
    this->fixed_point = nbr * fp_calc(2, this->fractionalBits);
}

//Param floating-point nbr constructor!
Fixed::Fixed(const float nbr)
{
    //std::cout << "Float constructor called" << std::endl;
    this->fixed_point = nbr * fp_calc(2, this->fractionalBits);
}

Fixed::Fixed(Fixed const &a)
{
    //std::cout << "Copy constructor called" << std::endl;
    *this = a;
}

Fixed &Fixed::operator=(Fixed const &a)
{
    //std::cout << "Copy assignment operator called" << std::endl;
    if (this != &a)
        this->fixed_point = a.getRawBits();
    return *this;
}

//Destructor!
Fixed::~Fixed()
{
    //std::cout << "Destructor called" << std::endl;
}

//-----------------------------------------------------//

int Fixed::getRawBits(void) const
{
    return (this->fixed_point);
}

void    Fixed::setRawBits(int const raw)
{
    //std::cout << "setRawBits member function called" << std::endl;
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

bool    Fixed::operator>(Fixed ob) const
{
    return (this->toFloat() > ob.toFloat());
}

bool    Fixed::operator<(Fixed ob) const
{
    return (this->toFloat() < ob.toFloat());
}

bool    Fixed::operator>=(Fixed ob) const
{
    return (this->toFloat() >= ob.toFloat());
}

bool    Fixed::operator<=(Fixed ob) const
{
    return (this->toFloat() <= ob.toFloat());
}

bool    Fixed::operator==(Fixed ob) const
{
    return (this->toFloat() == ob.toFloat());
}

bool    Fixed::operator!=(Fixed ob) const
{
    return (this->toFloat() != ob.toFloat());
}

float   Fixed::operator+(Fixed ob) const
{
    return (this->toFloat() + ob.toFloat());
}

float   Fixed::operator-(Fixed ob) const
{
    return (this->toFloat() - ob.toFloat());
}

float   Fixed::operator*(Fixed ob) const
{
    return (this->toFloat() * ob.toFloat());
}

float   Fixed::operator/(Fixed ob) const
{
    return (this->toFloat() / ob.toFloat());
}

Fixed   Fixed::operator++()
{
    this->setRawBits(this->getRawBits() + 1);
    return (*this);
}

Fixed   Fixed::operator--()
{
    this->setRawBits(this->getRawBits() - 1);
    return (*this);
}

Fixed   Fixed::operator++(int increment)
{
    Fixed   pre;
    pre = *this;
    if (!increment)
        increment = 1;
    this->setRawBits(getRawBits() + increment);
    return (pre);
}

Fixed   Fixed::operator--(int decrement)
{
    Fixed prev;
    prev = *this;
    if (!decrement)
        decrement = 1;
    this->setRawBits(getRawBits() - decrement);
    return (prev);
}

Fixed   &Fixed::min(Fixed &a, Fixed &b)
{
    if (a.toFloat() < b.toFloat())
        return (a);
    else
        return(b);
}

const Fixed &Fixed::min(Fixed const &a, Fixed const &b)
{
    if (a.toFloat() < b.toFloat())
        return (a);
    else
        return(b);
}

Fixed   &Fixed::max(Fixed &a, Fixed &b)
{
    if (a.toFloat() < b.toFloat())
        return (b);
    else
        return(a);
}

const Fixed &Fixed::max(Fixed const &a, Fixed const &b)
{
    if (a.toFloat() < b.toFloat())
        return (b);
    else    
        return (a);
}