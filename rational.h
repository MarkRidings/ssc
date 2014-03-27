/* rational.h ---
A class to store rational numbers in fractional form to ensure accuracy
 */

#ifndef INCLUDED_RATIONAL_H
#define INCLUDED_RATIONAL_H 1
#include <iostream>

using namespace std;

class RationalNumber
{
private:
  int numerator, denominator;
  int gcd(int n, int m);

public:
  // constructors
  RationalNumber();
  RationalNumber(int n, int d = 1);
  RationalNumber(const RationalNumber &rn);
  RationalNumber & operator=(const RationalNumber &rn);
  // methods
  double showDecimal(void);
  bool isLegal(void);
  bool isZero(void);
  friend RationalNumber operator+(const RationalNumber &rn1, const RationalNumber &rn2);
  friend RationalNumber operator-(const RationalNumber &rn1, const RationalNumber &rn2);
  friend RationalNumber operator*(const RationalNumber &rn1, const RationalNumber &rn2);
  friend RationalNumber operator/(const RationalNumber &rn1, const RationalNumber &rn2);
  friend ostream & operator<<(ostream &os, const RationalNumber &rn);
  friend istream & operator>>(istream &is, RationalNumber &rn);
};

#endif /* INCLUDED_RATIONAL_H */

// constructors
RationalNumber::RationalNumber()
{
}

// d (denominator) is optional default 1
RationalNumber::RationalNumber(int n, int d)
{
  int g = gcd(n, d);

  // make sure raitonal number is in reduced form
  numerator = n / g;
  denominator = d / g;
}

// copy constructor
RationalNumber::RationalNumber(const RationalNumber &rn)
{
  numerator = rn.numerator;
  denominator = rn.denominator;
}

// returns greatest common divisor of two integers
int RationalNumber::gcd(int n, int m)
{
  if (m == 0)          // base case
    return n;
  int r = n % m;       // keep computing remainder until zero
  return gcd(m, r);
}

// displays RationalNumber in decimal form
double RationalNumber::showDecimal(void)
{
  return (double)this->numerator / (double)this->denominator;
}

// returns true if denominator is non-zero, false otherwise
bool RationalNumber::isLegal(void)
{
  return (denominator != 0);
}

// returns true if numerator is zero (meaning number is zero), false otherwise
bool RationalNumber::isZero(void)
{
  return (numerator == 0);
}

//overloading assignment operator
RationalNumber & RationalNumber::operator=(const RationalNumber &rn)
{
  // if assigning to itself
  if (this == &rn)
    return *this;

  // otherwise assign new values from parameter
  numerator = rn.numerator;
  denominator = rn.denominator;
  return *this;
}

// overloading addition(+) operator
RationalNumber operator+(const RationalNumber &rn1, const RationalNumber &rn2)
{
  // fraction addition
  int num = (rn1.numerator * rn2.denominator) + (rn2.numerator * rn1.denominator);
  int dem = (rn1.denominator * rn2.denominator);
  RationalNumber result(num, dem);
  return result;
}

// overloading subtraction(-) operator
RationalNumber operator-(const RationalNumber &rn1, const RationalNumber &rn2)
{
  // fraction subtraction
  int num = (rn1.numerator * rn2.denominator) - (rn2.numerator * rn1.denominator);
  int dem = (rn1.denominator * rn2.denominator);
  RationalNumber result(num, dem);
  return result;
}

// overloading multiplication(*) operator
RationalNumber operator*(const RationalNumber &rn1, const RationalNumber &rn2)
{
  // fraction multiplication
  int num = (rn1.numerator * rn2.numerator);
  int dem = (rn1.denominator * rn2.denominator);
  RationalNumber result(num, dem);
  return result;
}

// overloading division(/) operator
RationalNumber operator/(const RationalNumber &rn1, const RationalNumber &rn2)
{
  // fraction division
  int num = (rn1.numerator * rn2.denominator);
  int dem = (rn1.denominator * rn2.numerator);
  RationalNumber result(num, dem);
  return result;
}

// overload std out to display a RationalNumber
ostream & operator<<(ostream &os, const RationalNumber &rn)
{
  // if number is negative, ensure negative is displayed on numerator
  if (rn.denominator < 0)
    os << rn.numerator * -1 << "/" << rn.denominator * -1;
  // if whole number, don't display denominator
  else if (rn.denominator == 1)
    os << rn.numerator;
  else
    os << rn.numerator << "/" << rn.denominator;
  return os;
}

// overload standard input to accept RationalNumber class
istream & operator>>(istream &is, RationalNumber &rn)
{
  char temp;
  int n, d, t;
  int new_d = 1;

  is >> n;

  // if next char is newline or space then input is integer
  if ((is.peek() == '\n') || (is.peek() == ' '))
      d = 1;
  // if next char is '.' then input is a decimal number
  else if (is.peek() == '.')
    {
      is >> temp;
      is >> d;
      t = d;               // temp holding to find out how many decimals

      // find # of decimal places in order to create RationalNumber
      while (t)
        {
          t /= 10;
          new_d *= 10;
        }

      // create numerator depending if input is positive/negative
      if (n < 0)
        n = (n * new_d) - d;
      else
        n = (n * new_d) + d;

      d = new_d;
    } //  end of decimal number input
  else
    //  input is a fraction
    {
      is >> temp;
      is >> d;
    }

  RationalNumber r(n, d); // create with new input
  rn = r;                 // assign to input parameter
  return is;
}

  
    
        
      
