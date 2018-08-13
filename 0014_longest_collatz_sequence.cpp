/**********************
Author: Daniel Bowder
Date: August 13, 2018

Problem: https://projecteuler.net/problem=14
  "The following iterative sequence is defined for the set of positive integers:

    n → n/2 (n is even)
    n → 3n + 1 (n is odd)

    Using the rule above and starting with 13, we generate the following sequence:
    13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1

    It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

    Which starting number, under one million, produces the longest chain?

    NOTE: Once the chain starts the terms are allowed to go above one million."

***********************/

#include <iostream>
#include <cmath>

using std::cout;
using std::endl;


double longest_collatz_sequence(double upperLimit) {
  // Create variables to hold our max discovered value so we can return it later
  double maxStart = 0;
  int maxSteps = 0;

  // For each number from 1 to the upperLimit defined by the user
  for (int i=1;i<upperLimit;i++) {
    // Prepare a step counter, a while loop stop condition
    int stepCount = 1;
    bool finished = false;
    // Set ii to be our variable we can modify and play with for this iteration.
    double ii = i;

    // While we're not done,
    while (!finished) {
      // Check the nubmer is 1,
      if ( ii == 1 ) {
        // If the number is 1, we've met our win-condition, and we can break.
        break;
      } else if (1 == fmod(ii,2)) {
        // If the number is even, preform the even operation and go again.
        ii = ((3*ii) + 1);
        stepCount++;
      } else {
        // If the number is odd, preform the odd operation and go again.
        ii = (ii/2);
        stepCount++;
      }
    }

    // If the number we're on currently has a higher step-count than the current maximum,
    //    set this number to the maximum values.
    if (stepCount > maxSteps) {
      maxSteps = stepCount;
      maxStart = i;
    }
  }

  // Return our start value with the maximum step size.
  return maxStart;
}

int main(int argc, char* argv[]) {
  cout << "Problem 14. " << longest_collatz_sequence(1000000) <<  endl;
}
