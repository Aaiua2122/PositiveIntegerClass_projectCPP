#include "positive_integer.h"

//#include <vector>
#include <iostream>
// namespaces

//std::vector
//myvector::vector

PositiveInteger::PositiveInteger(int value) {
  value_ = value;
  divisors_ = nullptr;
  divisors_count_ = 0;

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

// вынести sorted -> ctr
void PositiveInteger::Replace_divisor(int v_old, int v_new, bool sorted) {
  for (int i = 0; i < divisors_count_; ++i) {
    if (divisors_[i] == v_old) {
      divisors_[i] = v_new;
      break;
    }
  }

// ранний выход
  value_ = 1;
  for (int i = 0; i < divisors_count_; ++i) {
    value_ *= divisors_[i];
  }

  if (sorted) {
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

// вынести в метод
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

// переписать, можно через gcd
int Lcm(const PositiveInteger& a, const PositiveInteger& b) {
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
        copy_array[j] = 1;
        break;
      }
    }
    result *= a_divisors[i]; // ???
  }

  for (int i = 0; i < b_count; ++i) {
    result *= copy_array[i];
  }

  delete[] copy_array;
  return result;
}


