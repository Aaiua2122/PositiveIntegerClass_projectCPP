#include <iostream>

#include "positive_integer.h"

int main() {
  std::cout << "\n";
  std::cout << "1. Prime factors\n";
  PositiveInteger unsorted(210);
  const PositiveInteger sorted(210, true);

  std::cout << "210, default mode: ";
  unsorted.PrintArray();
  std::cout << "210, sorted mode:  ";
  sorted.PrintArray();

  std::cout << "\n2. Copy construction and factor replacement\n";
  {
    PositiveInteger copy(sorted);
    copy.Replace_divisor(7, 2);
    unsorted.Replace_divisor(7, 2);

    std::cout << "Replace 7 with 2 in the sorted copy: ";
    copy.PrintArray();
    std::cout << "Replace 7 with 2 in default mode:   ";
    unsorted.PrintArray();

    copy.Replace_divisor(11, 13);
    std::cout << "Try to replace missing factor 11:   ";
    copy.PrintArray();
  }  

  std::cout << "Original after the copy leaves scope: ";
  sorted.PrintArray();

  std::cout << "\n3. Copy assignment\n";
  PositiveInteger assigned(12);
  std::cout << "Before assignment (12): ";
  assigned.PrintArray();
  assigned = sorted;
  std::cout << "After assignment (210): ";
  assigned.PrintArray();

  std::cout << "\n4. Greatest common divisor and least common multiple\n";
  const PositiveInteger eight(8);
  const PositiveInteger twenty_four(24);
  std::cout << "GCD(8, 24) = " << eight.Gcd(twenty_four) << '\n';
  std::cout << "LCM(8, 24) = " << eight.Lcm(twenty_four) << '\n';
  std::cout << "\n";

  return 0;
}
