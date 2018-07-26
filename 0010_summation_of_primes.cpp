/**********************
Author: Daniel Bowder
Date: July 26, 2018

Problem: https://projecteuler.net/problem=10
  "The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
   Find the sum of all the primes below two million."

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

long long int summation_of_primes(int value) {
  // Initialize a variable to hold our sum of primes.
  long long int sum = 0;

  // Setup Percent Print Helper Variables
  bool currentPercentPrint = false;
  int currentPercent = 0;
  int newPercent = 0;

  // For each number up to our value,
  for (int i=2;i<value;i++){ // Start at 2, because 1 doesn't count as prime.
    // check and see if that number is prime.
    // If that number is prime,
    if (isPrime(i)) {
      // Add the number to our sum of primes.
      sum = sum + i;
    }


    newPercent = (int)(i/(double)value*100);
    if (newPercent != currentPercent) {
      cout << newPercent << "% complete..." << endl;
      currentPercent = newPercent;
    }
  }
  // Return the sum of all of our prime numbers up to the value specified.
  return sum;
}

int main(int argc, char* argv[]) {
  cout << "Problem 10. " << summation_of_primes(2000000) <<  endl;
}
