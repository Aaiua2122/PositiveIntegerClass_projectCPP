#include "positive_integer.h"

#include <iostream>

PositiveInteger::PositiveInteger(int value) {
  value_ = value;
  divisors_ = nullptr;
  divisors_count_ = 0;

  BuildArray();
}

PositiveInteger::PositiveInteger(const PositiveInteger& other) {
  value_ = other.value_;
  divisors_count_ = other.divisors_count_;

  divisors_ = new int[divisors_count_];
  for (int i = 0; i < divisors_count_; ++i) {
    divisors_[i] = other.divisors_[i];
  }
}

PositiveInteger::~PositiveInteger() {
  delete[] divisors_;
}

void PositiveInteger::PrintArray() const {
  for (int i = 0; i < divisors_count_; ++i) {
    std::cout << divisors_count_ << ' ';
  }
  std::cout << "\n";
}

void PositiveInteger::BuildArray() {
  int n = value_;
  divisors_count_ = 0;

  for (int divisor = 2; divisor*divisor <= n; ++divisor) {
    while (n % divisor) {
      ++divisors_count_;
      n /= divisor;
    }
  }
  if (n > 1) {++divisors_count_;}

  divisors_ = new int[divisors_count_];
  n = value_;
  int index = 0;
  for (int divisor = 2; divisor*divisor <= n; ++divisor) {
    while (n % divisor == 0) {
      divisors_[index] = divisor;	
      ++index;
      n /= divisor;
    }
  }
  if (n > 1) {divisors_[index] = n;}  
}
