
class PositiveInteger {
  public:
    PositiveInteger(int value);
    PositiveInteger(const PositiveInteger& other);
    ~PositiveInteger();

    void PrintArray() const;

  private:
    int value_;
    int* divisors_;
    int divisors_count_;

    void BuildArray();
};
