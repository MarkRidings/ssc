/* rational.h ---
A class to store rational numbers in fractional form to ensure accuracy
 */

#ifndef INCLUDED_RATIONAL_H
#define INCLUDED_RATIONAL_H 1

class RationalNumber
{
private:
  int numerator, denominator;
  int gcd(int n, int m);

public:
  // constructors
  RationalNumber();
  RationalNumber(int n, int d = 1);
  RationalNumber(const RatonalNumber 7rn);
  RationalNumber & operator=(const RationalNumber &rn);
  // methods
  friend RationalNumber operator+(const RationalNumber &rn1, const RationalNumber &rn2);
  friend RationalNumber operator-(const RationalNumber &rn1, const RationalNumber &rn2);
  friend RationalNumber operator*(const RationalNumber &rn1, const RationalNumber &rn2);
  friend RationalNumber operator/(const RationalNumber &rn1, const RationalNumber &rn2);
  friend ostream & operator<<(ostream &os, const RationalNumber &rn);
  friend istream & operator>>(istream &is, RationalNumber &rn);
};

#endif /* INCLUDED_RATIONAL_H */

