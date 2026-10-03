#include <iostream>
#include <string>

class PositiveInteger {
	private:
		int value;
		int* divisors;
                // 1) bool
		int* divisors_sorted;
		int divisors_count;

	public:
		PositiveInteger(int value) {
			this->value = value;
			divisors = nullptr;
			divisors_sorted = nullptr;
			divisors_count = 0;
                        // 2) array
			BuildArrey();
			BuildSort_Arrey();
		}

		PositiveInteger(const PositiveInteger& other) {
			value = other.value;
			divisors_count = other.divisors_count;
			
			divisors = new int[divisors_count];
			for (int i = 0; i < divisors_count; ++i) {
				divisors[i] = other.divisors[i];
			}
					
			divisors_sorted = new int[divisors_count];
			for (int i = 0; i < divisors_count; ++i) {
				divisors_sorted[i] = other.divisors_sorted[i];
			}
		}

		~PositiveInteger() {
			delete[] divisors;
			delete[] divisors_sorted;
		}
	private:
		void BuildArrey() {
			int n = value;
			divisors_count = 0;
			for (int divisor = 2; divisor * divisor <= n; ++divisor) {
				while (n % divisor == 0) {
					++divisors_count;
					n /= divisor;
				}
			}

			if (n > 1) {
				++divisors_count;
			}
			divisors = new int[divisors_count];
			n = value;
			int index = 0;
			for (int divisor = 2; divisor * divisor <= n; ++divisor) {
				while (n % divisor == 0) {
					divisors[index] = divisor;
					++index;
					n /= divisor;
				}
				
				if (n > 1) {
					divisors[index] = n;
				}
			}
		}

		void BuildSort_Arrey() {
			
			divisors_sorted = new int[divisors_count];

			for (int i = 0; i < divisors_count; ++i) {
				divisors_sorted[i] = divisors[i];
			}

			int temp_value;
			for (int i; i < divisors_count - 1; ++i) {
				if (divisors_sorted[i] > divisors_sorted[i+1]) {
						temp_value = divisors_sorted[i+i];
						divisors_sorted[i] = divisors_sorted[i+1];
						divisors_sorted[i+1] = temp_value;
				}
			}		
		}

	public:
		void print_array() {
			for (int index = 0; index < divisors_count; ++index) {
				std::cout << divisors[index] << " "; 
			}
			std::cout << "\n";
		}
                // 3) not needed 
		void print_sarray() {
			for (int index = 0; index < divisors_count; ++index) {
				std::cout << divisors_sorted[index] << " ";
			}
			std::cout << "\n";
		}

                // gcd + lcm
		void nod() {

		}

		void nok() {

		}

};

int main() {
	PositiveInteger number1(120);
	number1.print_array();
	PositiveInteger number2 = number1;
	number2.print_sarray();
	return 0;
}
