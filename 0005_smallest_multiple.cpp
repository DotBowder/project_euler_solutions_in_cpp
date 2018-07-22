/**********************
Author: Daniel Bowder
Date: July 21, 2018

Problem: https://projecteuler.net/problem=5
  "2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
  What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?"
***********************/

#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

int smallest_multiple(int limit) {
  // Setup variable x to be checked for divisibility from 1 to our limit number
  int x = 1;
  // Because we don't know how big x will be, we create an infinite while loop
  while (true) {
    // Setup a bool which we can flip if the current x value doesn't meet the
    //    condition of being evenly divisible by numbers 1 to our limit number
    bool isEvenlyDivisible = true;
    // For all of the numbers i from 1 to our limit number,
    for (int i=1;i<limit;i++) {
      // if x is not evently divisible by i,
      if ( 0 != x % i) {
        // then it is not the number we're looking for.
        isEvenlyDivisible = false;
        break;
      }
    }
    // If we did not find a condidition to discard this x value,
    if (true == isEvenlyDivisible) {
      // return x as it is the smallest number evently divisible by 1 to limit
      return x;
    }

    // If x was not evenly divisible by all numbers 1 to limit, incriment and continue searching.
    x++;
  }
  return 0;
}

int main(int argc, char* argv[]) {
  cout << "Problem 3. " << smallest_multiple(20) <<  endl;
}
