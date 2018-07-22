/**********************
Author: Daniel Bowder
Date: July 21, 2018

Problem: https://projecteuler.net/problem=7
  "By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
   What is the 10001st prime number?"

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

double nthPrime(double value) {
  // Prepare placeholder for the current prime
  int currentPrime = 0;
  // Count the number of primes we've found
  int counter = 0;
  // Index our current number to be tested for prime-ness
  int x = 0;
  // While we haven't found enough primes yet,
  while (counter <= value + 1) {
    // Check if our x index is prime. If it is,
    if (isPrime(x)) {
      // set our current prime,
      currentPrime = x;
      // incriment x,
      x++;
      // and incriment our prime counter.
      counter++;
    } else {
      // If this nubmer is not prime, incriment x and continue.
      x++;
    }
  }
  // When we've counted enough prime numbers to equal our nth prime, 
  return currentPrime;
}

int main(int argc, char* argv[]) {
  cout << "Problem 7. " << nthPrime(10001) <<  endl;
}
