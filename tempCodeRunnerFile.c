/******************************************************************
 * Simon Fraser University
 * ENSC-151 Introduction to Software Development for Engineers
 * reduce.cpp -- Program to reduce a rational to lowest terms.
 *
 * Date:   2025.10.12
 ******************************************************************/
void reduce(int& num, int& den);
int gcd(int x, int y);


/******************************************************************
 * reduce -- reduce the rational to lowest terms
 *
 * Parameters:
 *   num -- the numerator of the rational (input/output)
 *   den -- the denominator of the rational (input/output)
 *
 * Returns: nothing
 ******************************************************************/
void 
reduce(int& num, int& den)
{
  if (den == 0) { // Error case. Just make it 0/1
    num = 0;
    den = 1;
  } else {
    if (den < 0) { // Make sure only numerator is negative.
      num *= -1;
      den *= -1;
    }

    int div;
    if (num >= 0) {
      div = gcd(num, den);
    } else {
      div = gcd(-num, den);
    }
    if (div > 1) {
      num /= div;
      den /= div;
    }
  }
}

/******************************************************************
 * gcd -- Calculate the greatest common divisor
 *
 * This algorithm assumes that x and y are positive. This is usually
 * known as Euclid's Algorithm.
 *
 * Parameters:
 *   x, y -- the numbers to find the gcd of (input)
 *
 * Returns: the greatest common divisor of x and y
 ******************************************************************/
int
gcd(int x, int y)
{
  while (y > 0) {
    int z;
    z = x % y;
    x = y;
    y = z;
  }
  return(x);
}

/******************************************************************
 * $RCSfile$   $Revision$
 * $Date$
 * $State$ 
 *
 *                     REVISION HISTORY
 *
 * $Log$
 *
 ******************************************************************/