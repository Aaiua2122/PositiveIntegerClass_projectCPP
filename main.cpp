#include "positive_integer.h"

#include <iostream>
					 
int main() {
  std::cout << "\nInit new number1\n";
  PositiveInteger number1(120);
  std::cout << "N1: ";
  number1.PrintArray();

  std::cout << "\nCreate new number2 throught copy_constructor\n";
  PositiveInteger number2 = number1;
  std::cout << "N1: ";
  number1.PrintArray();
  std::cout << "N2: ";
  number2.PrintArray();

  std::cout << "\nReplace divisor in number2 with sort\n";
  number2.Replace_divisor(3, 11, true);
  std::cout << "N1: ";
  number1.PrintArray();
  std::cout << "N2: ";  
  number2.PrintArray();

  std::cout << "\nReplace no exit divisor in number2\n";
  number2.Replace_divisor(9999, 9999);
  std::cout << "N1: ";
  number1.PrintArray();
  std::cout << "N2: ";
  number2.PrintArray();
  return 0;
}
