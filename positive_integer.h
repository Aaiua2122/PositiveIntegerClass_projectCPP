
class PositiveInteger {
  public:
    PositiveInteger(int value);
    PositiveInteger(const PositiveInteger& other);
    ~PositiveInteger();

    void PrintArray() const;
    void Replace_divisor(int v_old, int v_new, bool sorted_ = false);
    int gcd(int v1, int v2);
    int lcm(int v1, int v2);

  private:
    int value_;
    int* divisors_;
    int divisors_count_;
    bool sorted_;

    void BuildArray();
    void SortArray();
};
