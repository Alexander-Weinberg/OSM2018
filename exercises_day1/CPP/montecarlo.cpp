/* This function estimate pi using the monte carlo method. 
 * Draws random samples of (x,y) from [0,1]x[0,1]
 *
 * estimate_pi = #incircle / #total
 */


#include <random>
#include <stdio.h>

#include <iostream>
using namespace std;

bool inCircle(double x, double y)
{
	double z;
	z = x * x + y * y;
	return (z <= 1);
}

int main() {
  unsigned seed = 3;
  
  std:: default_random_engine generator_unif(seed);
  return 0;
}
