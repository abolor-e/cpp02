#include "Fixed.hpp"

/*
🟦
Accuracy vs Precision
Integers are highly accurate and not precise 
Float numbers are not accurate but highly precise

When we see float numbers, for example, 0.1 and try to see if this number is equal to 0.1 using
if (float(0.1) == 0.1) will be false. This is because float numbers are represented by binary numbers and 
there is no binary number for 0.1 so it is only closest representation to 0.1 using binary numbers.

Integers are accurate but not precise because when we, for example, substract 2 from 3.5 we get 1 not 1.5. 
But when we substract 2 from 3 we get exact 1 not 1.00001.

In the program you are writing if there is a need to check if your floating point is equal to certain value
you can check it in this way:

🔴
return value = float;
float i = 0.1;
epsilon = 1e - 10;

if abs(a - b) < epsilon
	print("a and b are approximately equal");
else
	print("a and b are different");
🔴
*/

/*
🟦
The structure of a Floating point number
Value = (-1) x 2^(e-127) x 1.m

For single-precision floats (32 bits): (there is also double-precision which is double 64 bits)
- 1 bit for sign
- 8 bits fpr exponent
23 bits for mantissa

🟦
Overflow and Underflow
Overflow occurs when a result exceeds the largest representable value in floating point 3.4028235 x 10^38

Underflow happens when a result is too small to be represented. The smallest non-zero positive float 1.4 x 10^-45

🟦
When substracting nearly equal float numbers there is a loss of significance, for example:
🔴
float a = 1.0
float b = 1.000001;

float result = b - a; (result is very small 0.000001 but the precision may be lost and this happens when working with close values)
🔴


*/

int main()
{
	Fixed a;
	Fixed b(a);
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}