/**********************
Author: Daniel Bowder
Date: July 19, 2018

Problem: https://projecteuler.net/problem=4
  "A palindromic number reads the same both ways.
  The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
  Find the largest palindrome made from the product of two 3-digit numbers."

***********************/

#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::vector;


int largest_palindrome_product() {
  // Create a list of palindromes
  vector<int> palindromes;
  // Iterate through all 3 didget numbers
  for (int i = 999; i >= 100; i--) {
    for (int ii = 999; ii >= 100; ii--) {
      // Gather the product of a set of numbers
      int product = i * ii;
      // Convert the product into a string variable
      string productString = to_string(product);
      // Start at the beginning (x=0) and at the end of a string (string.length() - x - 1 )
      // Count upward until you reach the midway point of the string.
      bool isPalindrome = true;
      for (int x = 0; x <= productString.length()/2; x++) {
        // If the beginning (x) and end (length-x-1) chars are NOT the same,
        if (productString.at(x) != productString.at(productString.length() - x - 1 )) {
          // then this is not a palindrome, and we do not need to continue.
          isPalindrome = false;
          break;
        }
      }
      // If the productString made it through the barrage,
      if (isPalindrome) {
        // then this is a Palindrome, and we can add it to the list.
        palindromes.push_back(product);
      }
    }
  }
  // Create a variable to house the largest known palindrome.
  int largest = 0;
  // For all of the palindromes we collected in our list.
  for (int i=0; i < palindromes.size(); i++) {
    // If largest known palindrome is smaller than the new palindrome,
    if (largest < palindromes[i]) {
      // assign largest known palindrome, to the new palindrome.
      largest = palindromes[i];
    }
  }
  // Return the largest known palindrome.
  return largest;
}

int main(int argc, char* argv[]) {
  cout << "Problem 3. " << largest_palindrome_product() <<  endl;
}
