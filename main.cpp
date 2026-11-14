#include <iostream>

#include "positive_integer.h"

int main() {
  int x = 120;
// случаи для 0, 1, 
  PositiveInteger test1(8);
  PositiveInteger test2(24);
  PositiveInteger test3(7);
  PositiveInteger test4(15);
  PositiveInteger test5(12);

  std::cout << "\nInit new number1\n";
  std::cout << x << "\n";
  PositiveInteger number1(x);
  std::cout << "N1: ";
  number1.PrintArray();

// писать числа для которых делители выводим, а не просто n1, n2, ...
  std::cout << "\nCreate new number2 throught copy_constructor\n";
  PositiveInteger number2 = number1;
  std::cout << "N1: ";
  number1.PrintArray();
  std::cout << "N2: ";
  number2.PrintArray();

  std::cout << "\nReplace divisor in number2 (3 --> 11) with sort\n";
  number2.Replace_divisor(3, 11, true);
// сделать тоже но без сортировки.
  std::cout << "N1: ";
  number1.PrintArray();
  std::cout << "N2: ";
  number2.PrintArray();

  std::cout << "\nReplace no exit divisor in number2\n";
  number2.Replace_divisor(9999, 9999);
  std::cout << "N1: ";
  number1.PrintArray(); // зачем?
  std::cout << "N2: ";
  number2.PrintArray();

  std::cout << "\nUse Gcd(num1, num2) ----> ";
  std::cout << Gcd(number1, number2);
  std::cout << "\nUse Gcd(8, 24) ----> ";
  std::cout << Gcd(test1, test2);
  std::cout << "\nUse Gcd(7, 15) ----> ";
  std::cout << Gcd(test3, test4);
  std::cout << "\nUse Gcd(12, 12) ----> ";
  std::cout << Gcd(test5, test5);

  std::cout << "\n";

  std::cout << "\nUse Lcm(num1, num2) ----> ";
  std::cout << Lcm(number1, number2);
  std::cout << "\nUse Lcm(8, 24) ----> ";
  std::cout << Lcm(test1, test2);
  std::cout << "\nUse Lcm(7, 15) ----> ";
  std::cout << Lcm(test3, test4);
  std::cout << "\nUse Lcm(12, 12) ----> ";
  std::cout << Lcm(test5, test5);

  std::cout << "\n";

  return 0;
}
