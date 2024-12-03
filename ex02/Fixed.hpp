#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
	int	fixed_point;
	static const int fractionalBits;

	public:
	Fixed();
	Fixed(const int nbr);
	Fixed(const float nbr);
	Fixed(Fixed const &a);
	Fixed &operator=(Fixed const &a);
	~Fixed();

	int getRawBits(void) const;
	void    setRawBits(int const raw);
	float fp_calc(int a, int exponent) const;
	float toFloat(void) const;
	int toInt(void) const;

	bool    operator>(Fixed ob) const;
	bool    operator<(Fixed ob) const;
	bool    operator<=(Fixed ob) const;
	bool    operator>=(Fixed ob) const;

	bool    operator==(Fixed ob) const;
	bool    operator!=(Fixed ob) const;
	float   operator+(Fixed ob) const;
	float   operator-(Fixed ob) const;
	float   operator*(Fixed ob) const;
	float   operator/(Fixed ob) const;

	Fixed   operator++();
	Fixed   operator--();
	Fixed   operator++(int increment);
	Fixed   operator--(int decrement);

	static Fixed   &min(Fixed &a, Fixed &b);
	static Fixed   &max(Fixed &a, Fixed &b);
	static const Fixed &min(Fixed const &a, Fixed const &b);
	static const Fixed &max(Fixed const &a, Fixed const &b);
};

std::ostream	&operator<<(std::ostream &str, Fixed const &fixed_nbr);

#endif