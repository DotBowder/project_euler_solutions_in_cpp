/**********************
Author: Daniel Bowder
Date: July 31, 2018

Problem: https://projecteuler.net/problem=
  "The sequence of triangle numbers is generated by adding the natural numbers. So the 7th triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28. The first ten terms would be:
    1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
   Let us list the factors of the first seven triangle numbers:
       1: 1 = 1
       3: 1+2 = 3
       6: 1+2+3 = 6
      10: 1+2+3+4 = 10
      15: 1+2+3+4+5 = 15
      21: 1+2+3+4+5+6 = 21
      28: 1+2+3+4+5+6+7 = 28
   We can see that 28 is the first triangle number to have over five divisors.
   What is the value of the first triangle number to have over five hundred divisors?"

***********************/

#include <iostream>
#include <cmath>
#include <thread>
#include <thread>

using std::cout;
using std::endl;


double highly_divisible_triangular_number(double divisors) {
  // The variable i is our index/counter and starts on 2 because we don't need to consider numbers before 2.
  int i=2;
  // Bool to keep while loop open.
  bool foundSolution = false;
  // While we have not found a solution...
  while (!foundSolution) {

    // Generate the next triagle number...
    int sum = 0;
    for (int ii=0; ii<i; ii++) {
      // cout << i << endl;
      sum += ii;
    }

    // Calculate how many divisors the new triangle number has...
    int divisorCount = 2; // Start at 2 to account for init value 1, and the number 1 as a divisor.
    for (int ii=0; ii<sum; ii++) {
      if (0 == fmod(sum, ii)) {
        // cout << " d:" << ii;
        divisorCount++;
      }
    }

    // If this triangle number has more divisors than the specificed divisorLimit,
    if (divisorCount > divisors) {
      // Exit while loop;
      foundSolution = true;
      // return the triangle number
      return sum;
    }

    // Incriment and try the next number for a solution...
    i++;
  }


  return 0;
}

void highly_divisible_triangular_number_threaded(int threadNumber, int threadCount, double divisorLimit) {

    // Start Stopwatch
    auto startTime = std::chrono::high_resolution_clock::now();

    // The variable i is our index/counter and starts on the threadNumber for this process. ThreadNumbers range from 1 to the threadCount.
    int i=threadNumber;
    // Bool to keep while loop open.
    bool jobComplete = false;
    // While this thread has not found a solution...
    while (!jobComplete) {

      // Generate the next triagle number...
      int sum = 0;
      for (int ii=0; ii<i; ii+=1) {
        // cout << i << endl;
        sum += ii;
      }

      // Calculate how many divisors the new triangle number has...
      int divisorCount = 2; // Start at 2 to account for init value 1, and the number 1 as a divisor.
      for (int ii=0; ii<sum; ii++) {
        if (0 == fmod(sum, ii)) {
          divisorCount++;
        }
      }


      // If this triangle number has more divisors than the specificed divisorLimit,
      if (divisorCount > divisorLimit) {
        // Stop our Stopwatch
        auto endTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> timeDuration = endTime - startTime;

        // Print this thread's solution
        cout << "\nDuration: " << timeDuration.count() << "\tTriangle Number: " << sum << "\tDivisor Count: " << divisorCount << endl;

        // Exit while loop;
        jobComplete = true;
        break;
      }
      // Incriment by the number of threads active. Allows us to maintain an undefined linear search to infinity when looking for our solution.
      i+=threadCount;
    }

}

int main(int argc, char* argv[]) {

  // Single Threaded ::
  // Estimated Time To Completion: 1h47m
  // cout  << endl<< "Running Single Threaded - Rough ETA: 1h47m" << endl << endl;
  // cout << "Problem 12: " << highly_divisible_triangular_number(500) <<  endl;


  // Multi Threaded ::
  // Estimated Time To Completion: (1h47m / Number of Threads)
  //                           eg: 1h47m / 30threads = 3m34s

  // As a result of the multithreading and my programming skill limitations, the program does not simply return the result value, instead it prints it to stdout.
  // All threads have to terminate before the program knows to exit, however, your answer will likely be printed well before all the therads terminate.
  // With 30 threads, search for solution takes 214 seconds... On a single thread this search for solution would take (214) * 30 seconds... = 6420 seconds = 107 minuts = 1h47m

  // Define the threadCount.
  int threadCount = 16;
  cout << "Running Multi Threaded - Rough ETA: " << 6420/threadCount/60/60 << "h" << 6420/threadCount/60%60 << "m" << 6420/threadCount%60 << "s" << endl << endl;
  if ((1 != threadCount) && (1 == threadCount % 2)) {
    threadCount = threadCount - 1;
  }
  // Prepare thead workers in an array of std::thread objects
  std::thread *threadWorkers = new std::thread[threadCount-1];

  // Start each thread
  for (int threadNumber=0; threadNumber < threadCount; threadNumber++) {
    threadWorkers[threadNumber] = std::thread(highly_divisible_triangular_number_threaded, threadNumber, threadCount, 500);
  }

  // Wait for threads to finish...
  for (int i=0; i < threadCount; i++) {
    threadWorkers[i].join();
  }

}