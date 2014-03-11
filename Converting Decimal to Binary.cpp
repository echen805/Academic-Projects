#include <iostream>
#include <string>
#include <vector>

using namespace std;

void main() {
	// bit shifting is the same as * or / by 2^n
	int i = 13;
	int j = i>>2;
	cout << "j is " << j << endl;

	// convert integer to binary
	vector<bool> binaryNum;
	int number = 13;

	while(number > 0) {
		int remainder = number % 2;
		if(remainder == 1)
			binaryNum.push_back(true);
		else
			binaryNum.push_back(false);
		number = number / 2;
	}

	for(int i = binaryNum.size() - 1; i >= 0; i--) {
		cout << binaryNum[i] << " ";
	}
}