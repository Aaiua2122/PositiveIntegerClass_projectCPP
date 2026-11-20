class PositiveInteger {
 public:
  PositiveInteger(int value, bool sorted = false);
  PositiveInteger(const PositiveInteger& other);
  ~PositiveInteger();
  PositiveInteger& operator=(const PositiveInteger& other);

  void PrintArray() const;
  void Replace_divisor(int v_old, int v_new);
  int Gcd(const PositiveInteger& a) const;
  int Lcm(const PositiveInteger& a) const;

 private:
  int value_; // поменять на unsigned,

  int* divisors_;
  int divisors_count_;

  bool sorted_;

  void BuildArray();
  void SortArray();
};

