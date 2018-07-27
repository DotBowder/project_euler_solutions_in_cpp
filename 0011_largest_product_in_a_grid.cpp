/**********************
Author: Daniel Bowder
Date: July 27, 2018

Problem: https://projecteuler.net/problem=11
  "In the 20×20 grid below, four numbers along a diagonal line have been marked in parentheses.
      08  02  22  97  38  15  00  40  00  75  04  05  07  78  52  12  50  77  91  08
      49  49  99  40  17  81  18  57  60  87  17  40  98  43  69  48  04  56  62  00
      81  49  31  73  55  79  14  29  93  71  40  67  53  88  30  03  49  13  36  65
      52  70  95  23  04  60  11  42  69  24  68  56  01  32  56  71  37  02  36  91
      22  31  16  71  51  67  63  89  41  92  36  54  22  40  40  28  66  33  13  80
      24  47  32  60  99  03  45  02  44  75  33  53  78  36  84  20  35  17  12  50
      32  98  81  28  64  23  67  10 (26) 38  40  67  59  54  70  66  18  38  64  70
      67  26  20  68  02  62  12  20  95 (63) 94  39  63  08  40  91  66  49  94  21
      24  55  58  05  66  73  99  26  97  17 (78) 78  96  83  14  88  34  89  63  72
      21  36  23  09  75  00  76  44  20  45  35 (14) 00  61  33  97  34  31  33  95
      78  17  53  28  22  75  31  67  15  94  03  80  04  62  16  14  09  53  56  92
      16  39  05  42  96  35  31  47  55  58  88  24  00  17  54  24  36  29  85  57
      86  56  00  48  35  71  89  07  05  44  44  37  44  60  21  58  51  54  17  58
      19  80  81  68  05  94  47  69  28  73  92  13  86  52  17  77  04  89  55  40
      04  52  08  83  97  35  99  16  07  97  57  32  16  26  26  79  33  27  98  66
      88  36  68  87  57  62  20  72  03  46  33  67  46  55  12  32  63  93  53  69
      04  42  16  73  38  25  39  11  24  94  72  18  08  46  29  32  40  62  76  36
      20  69  36  41  72  30  23  88  34  62  99  69  82  67  59  85  74  04  36  16
      20  73  35  29  78  31  90  01  74  31  49  71  48  86  81  16  23  57  05  54
      01  70  54  71  83  51  54  69  16  92  33  48  61  43  52  01  89  19  67  48
   The product of these numbers is 26 × 63 × 78 × 14 = 1788696.
   What is the greatest product of four adjacent numbers in the same direction
      (up, down, left, right, or diagonally) in the 20×20 grid?"

***********************/

#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>

using std::cout;
using std::endl;


int largest_product_in_a_grid() {
  // Place the grid into a string variable for processing
  std::string gridString = " 08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08 49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00 81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65 52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91 22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80 24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50 32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70 67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21 24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72 21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95 78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92 16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57 86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58 19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40 04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66 88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69 04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36 20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16 20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54 01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48";

  // Define the width and heigth of the string grid of numbers
  int gridWidth=20;
  int gridHeight=20;

  // Dump the gridString to an array for processing
  int gridArray[gridWidth][gridHeight];
  for (int i=0;i<gridString.length();i+=3) {
    if (gridString.at(i) == ' ') {
      std::string s = "";
      s = s + gridString.at(i+1);
      s = s + gridString.at(i+2);
      gridArray[(i/3) / gridWidth][(i/3) % gridHeight] = stoi(s);
    }
  }


  // Print our Data to verify it looks correct
  // cout << "\nArray:\n";
  // for (int y=0;y<gridHeight;y++) {
  //   for (int x=0;x<gridWidth;x++) {
  //     if (gridArray[y][x] < 10) {
  //       cout << "0" << gridArray[y][x] << " ";
  //     } else {
  //       cout << gridArray[y][x] << " ";
  //     }
  //   }
  //   cout << "\n";
  // }


  // Create placeholders to hold the max product of each given orrientation
  double maxProductUp = 0;
  double maxProductDown = 0;
  double maxProductLeft = 0;
  double maxProductRight = 0;
  double maxProductDiaginalLeft = 0;
  double maxProductDiaginalRight = 0;




  // This next part could all be done in one large double for loop, but,
  //       for diagnostics, its simpler to have them sepparated.


  // Go through all the possible up orrientations, and preserve the largest product
  // cout << "\nCalculating Up..." << endl;
  for (int y=0;y<gridHeight;y++) {
    for (int x=0;x<gridWidth;x++) {
      if (y > 2) {
        double product = 1;
        product = product * gridArray[y-3][x];
        product = product * gridArray[y-2][x];
        product = product * gridArray[y-1][x];
        product = product * gridArray[y][x];
        if (maxProductUp < product) {
          // cout << "New Max Up Product on " << x << "," << y << "\tValues: " << " " << gridArray[y][x] << " " << gridArray[y-1][x] << " " << gridArray[y-2][x] << " " << gridArray[y-3][x] << "\tProduct: " << (int)product <<  "\n" << endl;
          maxProductUp = product;
        }
      }
    }
  }


  // Go through all the possible down positions, and preserve the largest product
  // cout << "\nCalculating Down..." << endl;
  for (int y=0;y<gridHeight;y++) {
    for (int x=0;x<gridWidth;x++) {
      if (y < gridHeight-3) {
        // cout << " " << gridArray[y+3][x] << " " << gridArray[y+2][x] << " " << gridArray[y+1][x] << " " << gridArray[y][x] << endl;
        double product = 1;
        product = product * gridArray[y+3][x];
        product = product * gridArray[y+2][x];
        product = product * gridArray[y+1][x];
        product = product * gridArray[y][x];
        if (maxProductDown < product) {
          // cout << "New Max Down Product on " << x << "," << y << "\tValues: " << " " << gridArray[y][x] << " " << gridArray[y+1][x] << " " << gridArray[y+2][x] << " " << gridArray[y+3][x] << "\tProduct: " << (int)product <<  "\n" << endl;
          // exit(0);
          maxProductDown = product;
        }
      }
    }
  }


  // Go through all the possible left positions, and preserve the largest product
  // cout << "\nCalculating Left..." << endl;
  for (int y=0;y<gridHeight;y++) {
    for (int x=0;x<gridWidth;x++) {
      if (x > 2) {
        double product = 1;
        product = product * gridArray[y][x-3];
        product = product * gridArray[y][x-2];
        product = product * gridArray[y][x-1];
        product = product * gridArray[y][x];
        if (maxProductLeft < product) {
          // cout << "New Max Left Product on " << x << "," << y << "\tValues: " << " " << gridArray[y][x] << " " << gridArray[y][x-1] << " " << gridArray[y][x-2] << " " << gridArray[y][x-3] << "\tProduct: " << (int)product <<  "\n" << endl;
          maxProductLeft = product;
        }
      }
    }
  }


  // Go through all the possible right positions, and preserve the largest product
  // cout << "\nCalculating Right..." << endl;
  for (int y=0;y<gridHeight;y++) {
    for (int x=0;x<gridWidth;x++) {
      if (x < gridWidth-3) {
        double product = 1;
        product = product * gridArray[y][x+3];
        product = product * gridArray[y][x+2];
        product = product * gridArray[y][x+1];
        product = product * gridArray[y][x];
        if (maxProductRight < product) {
          // cout << "New Max Right Product on " << x << "," << y << "\tValues: " << " " << gridArray[y][x] << " " << gridArray[y][x+1] << " " << gridArray[y][x+2] << " " << gridArray[y][x+3] << "\tProduct: " << (int)product <<  "\n" << endl;
          maxProductRight = product;
        }
      }
    }
  }


  // Go through all the possible diagonal right positions, and preserve the largest product
  // cout << "\nCalculating D Right..." << endl;
  for (int y=0;y<gridHeight;y++) {
    for (int x=0;x<gridWidth;x++) {
      if (x < gridWidth-3 && y < gridHeight-3) {
        double product = 1;
        product = product * gridArray[y+3][x+3];
        product = product * gridArray[y+2][x+2];
        product = product * gridArray[y+1][x+1];
        product = product * gridArray[y][x];
        if (maxProductDiaginalRight < product) {
          // cout << "New Max D Right Product on " << x << "," << y << "\tValues: " << " " << gridArray[y][x] << " " << gridArray[y+1][x+1] << " " << gridArray[y+2][x+2] << " " << gridArray[y+3][x+3] << "\tProduct: " << (int)product <<  "\n" << endl;
          maxProductDiaginalRight = product;
        }
      }
    }
  }


  // Go through all the possible diagonal left positions, and preserve the largest product
  // cout << "\nCalculating D Left..." << endl;
  for (int y=0;y<gridHeight;y++) {
    for (int x=0;x<gridWidth;x++) {
      if (x > 2 && y < gridHeight-3) {
        double product = 1;
        product = product * gridArray[y+3][x-3];
        product = product * gridArray[y+2][x-2];
        product = product * gridArray[y+1][x-1];
        product = product * gridArray[y][x];
        if (maxProductDiaginalLeft < product) {
          // cout << "New Max D Left Product on " << x << "," << y << "\tValues: " << " " << gridArray[y][x] << " " << gridArray[y+1][x-1] << " " << gridArray[y+2][x-2] << " " << gridArray[y+3][x-3] << "\tProduct: " << (int)product <<  "\n" << endl;
          maxProductDiaginalLeft = product;
        }
      }
    }
  }


  // Output our max product variable for each position/orrientation.
  // cout << "\nMax Product Up: \t" << (int)maxProductUp;
  // cout << "\nMax Product Down:\t" << (int)maxProductDown;
  // cout << "\nMax Product Left:\t" << (int)maxProductLeft;
  // cout << "\nMax Product Right:\t" << (int)maxProductRight;
  // cout << "\nMax Product Diaginal Left:\t" << (int)maxProductDiaginalLeft;
  // cout << "\nMax Product Diaginal Right:\t" << (int)maxProductDiaginalRight;


  // Compare the max products, and keep the largest of them all.
  double maxProduct = 0;
  if (maxProduct < maxProductUp) {
    maxProduct = maxProductUp;
  }
  if (maxProduct < maxProductDown) {
    maxProduct = maxProductDown;
  }
  if (maxProduct < maxProductLeft) {
    maxProduct = maxProductLeft;
  }
  if (maxProduct < maxProductRight) {
    maxProduct = maxProductRight;
  }
  if (maxProduct < maxProductDiaginalLeft) {
    maxProduct = maxProductDiaginalLeft;
  }
  if (maxProduct < maxProductDiaginalRight) {
    maxProduct = maxProductDiaginalRight;
  }


  // Return the largest product found from the shapes.
  return maxProduct;
}

int main(int argc, char* argv[]) {
  cout << "Problem 11. " << largest_product_in_a_grid() <<  endl;
}
