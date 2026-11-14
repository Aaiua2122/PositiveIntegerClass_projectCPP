
class PositiveInteger {
 public:
  PositiveInteger(int value);
  PositiveInteger(const PositiveInteger& other);
  ~PositiveInteger();
  PositiveInteger& operator=(const PositiveInteger& other);

  void PrintArray() const;
  void Replace_divisor(int v_old, int v_new, bool sorted_ = false);

  // Get-методы
  int GetValue() const;
  int* GetDivisors() const;
  int GetDivisors_count() const; // поправить style


 private:
  int value_; // поменять на unsigned,

  int* divisors_;
  int divisors_count_;

  bool sorted_;

  void BuildArray();
  void SortArray();
};

// в методы
int Gcd(const PositiveInteger& a, const PositiveInteger& b);
int Lcm(const PositiveInteger& a, const PositiveInteger& b);

