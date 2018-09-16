/**********************
Author: Daniel Bowder
Date: Sept 16, 2018

Problem: https://projecteuler.net/problem=16
  "2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
   What is the sum of the digits of the number 2^1000?"

***********************/

#include <iostream>
#include <cmath>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::to_string;


double power_diget_sum(double value) {

  // Raise 2 to the power of the value provided by the user
  double exponential_value = pow(2,value);
  // Convert the exponential_value to a string object
  string s = to_string(exponential_value);

  // Loop through each string char value adding the int representation
  // to the sum value. If we hit a decimal value, break out of the loop.
  double sum;
  for (int i=0;i<s.length();i++) {
    if (s.at(i) == '.')
      break;
    sum += (int)(s.at(i))-48;
  }

  // Return the sum value we caluclated to be the power didget sum.
  return sum;
}



int main(int argc, char* argv[]) {
  cout << "Problem . " << power_diget_sum(1000) <<  endl;
}
