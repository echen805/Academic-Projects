#include <string>
#include <vector>
#include <iostream>

using namespace std;

class BinaryInteger {
public:
	BinaryInteger() {
		sign = false;
		number.push_back(false);
	}

	BinaryInteger(bool sign, vector<bool> number) {
		this->sign = sign;
		this->number = number;
	}
private:
	bool sign;
	vector<bool> number;
friend void print(BinaryInteger& a);
friend class DumbClass;
};

class DumbClass{
public:
	DumbClass(BinaryInteger b) {
		binInt = b;
	}

	void print() {
		if(binInt.sign) {
			cout << "negative";
		} else {
			cout << "positive";
		}
	}
private:
	BinaryInteger binInt;
};

void print(BinaryInteger& a) {
	if(a.sign) cout << "-";
	for(int i = a.number.size() - 1; i >= 0; i--) {
		cout << a.number[i];
	}
}

void main() {
	vector<bool> num;
	num.push_back(0);
	num.push_back(0);
	num.push_back(1);
	num.push_back(1);

	BinaryInteger myBinInt(true, num);

	print(myBinInt);
}