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

PositiveInteger::~PositiveInteger() { delete[] divisors_; }

void PositiveInteger::PrintArray() const {
  for (int i = 0; i < divisors_count_; ++i) {
    std::cout << divisors_[i] << ' ';
  }
  std::cout << "\n";
}

void PositiveInteger::BuildArray() {
  int n = value_;
  divisors_count_ = 0;

  for (int divisor = 2; divisor * divisor <= n; ++divisor) {
    while (n % divisor == 0) {
      ++divisors_count_;
      n /= divisor;
    }
  }
  if (n > 1) {
    ++divisors_count_;
  }

  divisors_ = new int[divisors_count_];
  n = value_;
  int index = 0;
  for (int divisor = 2; divisor * divisor <= n; ++divisor) {
    while (n % divisor == 0) {
      divisors_[index] = divisor;
      ++index;
      n /= divisor;
    }
  }
  if (n > 1) {
    divisors_[index] = n;
  }
}

void PositiveInteger::Replace_divisor(int v_old, int v_new, bool sorted_) {
  for (int i = 0; i < divisors_count_; ++i) {
    if (divisors_[i] == v_old) {
      divisors_[i] = v_new;
      break;
    }
  }

  value_ = 1;
  for (int i = 0; i < divisors_count_; ++i) {
    value_ *= divisors_[i];
  }

  if (sorted_) {
    SortArray();
  }
}

void PositiveInteger::SortArray() {
  int temporary_value;
  for (int i = 0; i < divisors_count_ - 1; ++i) {
    if (divisors_[i] > divisors_[i + 1]) {
      temporary_value = divisors_[i + 1];
      divisors_[i + 1] = divisors_[i];
      divisors_[i] = temporary_value;
    }
  }
}

int PositiveInteger::GetValue() const { return value_; }

int* PositiveInteger::GetDivisors() const { return divisors_; }

int PositiveInteger::GetDivisors_count() const { return divisors_count_; }

int Gcd(const PositiveInteger& a, const PositiveInteger& b) {
  int* a_divisors = a.GetDivisors();
  int* b_divisors = b.GetDivisors();
  int a_count = a.GetDivisors_count();
  int b_count = b.GetDivisors_count();

  int result = 1;
  int* copy_array = new int[b_count];
  for (int i = 0; i < b_count; ++i) {
    copy_array[i] = b_divisors[i];
  }

  for (int i = 0; i < a_count; ++i) {
    for (int j = 0; j < b_count; ++j) {
      if (a_divisors[i] == copy_array[j]) {
        result *= copy_array[j];
        copy_array[j] = 0;
        break;
      }
    }
  }
  delete[] copy_array;
  return result;
}
