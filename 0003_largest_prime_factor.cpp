/**********************
Author: Daniel Bowder
Date: July 16, 2018

Problem: https://projecteuler.net/problem=3
  "The prime factors of 13195 are 5, 7, 13 and 29.
   What is the largest prime factor of the number 600851475143 ?"

***********************/

#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

bool isPrime(double i) {
  // Iterate through numbers less than or equal to half of the value querried for prime.
  for (double ii=2; ii <= i/2; ii++) {
    // If any number we iterate through is a factor of the original number,
    if (0 == fmod(i, ii)) {
      // then the original number is not prime, return false.
      return false;
    }
  }
  // If we've checked all of the numbers up to 1/2 of the value querried and found no
  // factors, then this number is prime. Return true.
  return true;
}

double largest_prime_factor(double value) {
  // Iterate through all the numbers from the given value to 0.
  for (double i=value-1; i > 1; i--)  {
    // If the number we iterate over is a factor of the given value,
    if (0 == fmod(value, i)) {
      // check if the number is prime. If it is prime,
      if (isPrime(i)) {
        // return the number we're on.
        return i;
        // As we're counting downward from the value we received,
        // the first Prime we run accross here will be the largest prime factor.
        }
      }
  }
  return 0;
}

int main(int argc, char* argv[]) {
  cout << "Problem 3. " << largest_prime_factor(600851475143) <<  endl;
}
