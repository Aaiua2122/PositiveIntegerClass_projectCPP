#include "positive_integer.h"

#include <iostream>
					 
int main() {
  PositiveInteger number1(120);
  number1.PrintArray();
  PositiveInteger number2 = number1;
  number2.PrintArray();
  return 0;
}
