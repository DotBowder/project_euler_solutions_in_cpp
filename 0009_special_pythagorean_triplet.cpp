/**********************
Author: Daniel Bowder
Date: Month Day, 2018

Problem: https://projecteuler.net/problem=9
  "A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
      a^2 + b^2 = c^2

   For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

   There exists exactly one Pythagorean triplet for which a + b + c = 1000.
   Find the product abc."

***********************/

#include <iostream>
#include <math.h>
#include <cmath>

using std::cout;
using std::endl;


int special_pythagorean_triplet(double value) {
  for (int a=1;a<value;a++) {
    for (int b=1;b<value;b++) {
      for (int c=1;c<value;c++) {
        if (a+b+c == value) {
          if (a * a + b * b == c * c) {
            return (a*b*c);
          }
        }
      }
    }
  }
  return 0;
}

int main(int argc, char* argv[]) {
  cout << "Problem 9. " << special_pythagorean_triplet(1000) <<  endl;
}
