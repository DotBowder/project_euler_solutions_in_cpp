/**********************
Author: Daniel Bowder
Date: July 21, 2018

Problem: https://projecteuler.net/problem=6
  "The sum of the squares of the first ten natural numbers is,
    1^2 + 2^2 + ... + 10^2 = 385

   The square of the sum of the first ten natural numbers is,
    (1 + 2 + ... + 10)^2 = 55^2 = 3025

   Hence the difference between the sum of the squares of the first
   ten natural numbers and the square of the sum is 3025 − 385 = 2640.

   Find the difference between the sum of the squares of the first
   one hundred natural numbers and the square of the sum."

***********************/

#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

int sum_square_difference(double value) {

  // Setup placeholder variables for the sum of squares and for the square of the sum.
  double sumSquares = 0;
  double squareSum = 0;

  // For each number from 1 to our value
  for (int i=1; i<=value;i++) {
    // Calculate the square value of the number and add it to our sum of squres
    sumSquares+=pow(i,2);
    // Add the value of our number to the square sum. Later we will square this sum.
    squareSum+=i;
  }
  // Square the sum of all values from 1 to our value
  squareSum = pow(squareSum,2);

  // Return the difference between the square of our sums, and the sum of our squares.
  return squareSum - sumSquares;
}

int main(int argc, char* argv[]) {
  cout << "Problem 6. " << sum_square_difference(100) <<  endl;
}
