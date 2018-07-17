/**********************
Author: Daniel Bowder
Date: July 15, 2018

Problem: https://projecteuler.net/problem=1
  "If we list all the natural numbers below 10 that are multiples of 3 or 5,
   we get 3, 5, 6 and 9. The sum of these multiples is 23. Find the sum of 
   all the multiples of 3 or 5 below 1000."

***********************/

#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

int multiples_of_3_and_5(int max) {
  // Prepare a sum counter to add up all of the multiples we find that match our condition.
  int sum = 0;
  // Count from 0 to the maximum number defined when we called the function.
  for (int i=0; i < max; i++) {
    // If the number we're currently on is evently divisble by 3, or evenly divisble by 5, then,
    if (0 == i % 3 || 0 == i % 5) {
      // add this number to our sum counter, as it meets our conditions. 
      sum += i;
    }
  }
  return sum;
}

int main() {
  cout << "Problem 1. " << multiples_of_3_and_5(1000) << endl;
}
