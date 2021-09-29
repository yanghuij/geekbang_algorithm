#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
	for (int i = digits.size() - 1; i >= 0; i--) {
		digits[i] += 1;
		if (digits[i] >= 10) {
			digits[i] %= 10;
		} else {
			return digits;
		}
	}

	digits.insert(digits.begin(), 1);

	return digits;
}

void test1() {
	int a[] = {1, 2, 3};
	vector<int> digits;
	
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
		digits.push_back(a[i]);	
	}
	
	plusOne(digits);
	
	cout << "[";
	for (int i = 0; i < digits.size(); i++) {
		cout << digits[i] << " ";	
	}
	
	cout << "]"<< endl;
}

void test2() {
	int a[] = {9, 9, 9};
	vector<int> digits;
	
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
		digits.push_back(a[i]);	
	}
	
	plusOne(digits);
	
	cout << "[";
	for (int i = 0; i < digits.size(); i++) {
		cout << digits[i] << " ";	
	}
	
	cout << "]"<< endl;
}

void test3() {
	int a[] = {0};
	vector<int> digits;
	
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
		digits.push_back(a[i]);	
	}
	
	plusOne(digits);
	
	cout << "[";
	for (int i = 0; i < digits.size(); i++) {
		cout << digits[i] << " ";	
	}
	
	cout << "]"<< endl;
}

int main(void) {
	test1();
	test2();
	test3();
	
	return 0;
}