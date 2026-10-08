#include <iostream>

#include "positive_integer.h"

int main() {
  PositiveInteger test1(8);
  PositiveInteger test2(24);
  PositiveInteger test3(7);
  PositiveInteger test4(15);
  PositiveInteger test5(12);

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

  std::cout << "\nUse Gcd(num1, num2) ----> ";
  std::cout << Gcd(number1, number2);
  std::cout << "\n";

  std::cout << "\nUse Lcm(num1, num2) ----> ";
  std::cout << Lcm(number1, number2) << "\n";
  std::cout << "\nUse Lcm(num1, num2) ----> ";
  std::cout << Lcm(test1, test2) << "\n";
  std::cout << "\nUse Lcm(num1, num2) ----> ";
  std::cout << Lcm(test3, test4) << "\n";
  std::cout << "\nUse Lcm(num1, num2) ----> ";
  std::cout << Lcm(test5, test5) << "\n";

  std::cout << "\n";

  return 0;
}
