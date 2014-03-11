#include <iostream>

using namespace std;

int factorial(int num) {
	if (num > 1) // The recursive case
		return num*factorial(num - 1);
	else // The base case
		return num;
}

int power(int base, int exponent) {
	if (exponent == 1) // The base case
		return base;
	else // The recursive case
		return base * power(base, exponent - 1);
}

void main() {
	int a = 4;
	int b = 3;
	cout << a << "! is " << factorial(a) << endl;
	cout << a << "^" << b << " is " << power(a, b) << endl;
}