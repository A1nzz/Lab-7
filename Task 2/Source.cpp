#include <iostream> 
using namespace std;

bool has_only_binary_digits(string s) {
	if (s.length() != 8) {
		return false;
	}
	return s.find_first_not_of("01-") == string::npos;
}

void convertNegative(string& s) {
	if (s[0] == '-') {
		s[0] = '1';
	}
}

string conversionFromAddToReverse(string s) {
	if (s[0] == '0') {
		return s;
	}
	else {
		for (int i = s.length() - 1; i > 0; i--) {
			if (s[i] == '1') {
				s[i] = '0';
				return s;
			}
			else {
				s[i] = '1';
			}
		}
	}
}

int main() {
	string number;

	cout << "Enter a number in additional code(8 bit): ";
	cin >> number;
	while (!has_only_binary_digits(number)) {
		cout << "Incorrect input! Try again: ";
		cin >> number;
	}

	convertNegative(number);

	cout << conversionFromAddToReverse(number);
	

	return 0;
}