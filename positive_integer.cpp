#include "positive_integer.h"

#include <iostream>

PositiveInteger::PositiveInteger(int value, bool sorted) {
  value_ = value;
  divisors_ = nullptr;
  divisors_count_ = 0;
  sorted_ = sorted;

  BuildArray();
}

PositiveInteger& PositiveInteger::operator=(const PositiveInteger& other) {
	if (&other == this) { return *this; }
	value_ = other.value_;
	divisors_count_ = other.divisors_count_;
	sorted_ = other.sorted_; 

	delete[] divisors_;
	divisors_ = new int[divisors_count_];
	for (int i = 0; i < divisors_count_; ++i) {
		divisors_[i] = other.divisors_[i];
	}
	return *this;
}

//конструктор по умолчанию
PositiveInteger::PositiveInteger(const PositiveInteger& other) {
  value_ = other.value_;
  divisors_count_ = other.divisors_count_;
  sorted_ = other.sorted_;

  divisors_ = new int[divisors_count_];
  for (int i = 0; i < divisors_count_; ++i) { // size_t 
    divisors_[i] = other.divisors_[i];
  }
}

PositiveInteger::~PositiveInteger() { delete[] divisors_; }

// добавить определённый оператор <<
 
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


void PositiveInteger::Replace_divisor(int v_old, int v_new) {

  bool flag = false;

  for (int i = 0; i < divisors_count_; ++i) {
    if (divisors_[i] == v_old) {
      divisors_[i] = v_new;
      flag = true;
      break;
    }
  }

  if (!flag) {return;}

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
  for (int j = 0; j < divisors_count_ - 1; ++j)
    for (int i = 0; i < divisors_count_ - 1 - j; ++i) {
      if (divisors_[i] > divisors_[i + 1]) {
        temporary_value = divisors_[i + 1];
        divisors_[i + 1] = divisors_[i];
        divisors_[i] = temporary_value;
    }
  }
}

int PositiveInteger::Gcd(const PositiveInteger& a) const {
  int result = 1;
  int* copy_array = new int[a.divisors_count_];
  for (int i = 0; i < a.divisors_count_; ++i) {
    copy_array[i] = a.divisors_[i];
  }

  for (int i = 0; i < divisors_count_; ++i) {
    for (int j = 0; j < a.divisors_count_; ++j) {
      if (divisors_[i] == copy_array[j]) {
        result *= copy_array[j];
        copy_array[j] = 0;
        break;
      }
    }
  }
  delete[] copy_array;
  return result;
}

int PositiveInteger::Lcm(const PositiveInteger& a) const {
  return (value_ / Gcd(a)) * a.value_;;
}


