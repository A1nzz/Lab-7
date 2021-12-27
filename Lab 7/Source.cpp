#include <iostream>
using namespace std;

bool has_only_digits(string s) {
	return s.find_first_not_of("0123456789") == string::npos;
}

int conversionToDecimal(string s) {
	int res = 0;
	int i = 0;
	while (i < s.length()) {
		res += (s[i] - '0') * pow(6, s.length() - 1 - i);
		i++;
	}
	return res;
}

string conversionToHexademical(int decimal) {
	string res;
	while (decimal) {
		if (decimal % 13 > 9) {
			res += (char)('A' + decimal % 13 - 10);
		}
		else {
			res += (char)('0' + decimal % 13);
		}
		decimal /= 13;
	}
	reverse(res.begin(), res.end());
	return res;
}

int main() {
	string number;
	cout << "Enter a number in the hexademical(6) number system: ";
	cin >> number;

	while (!has_only_digits(number)) {
		cout << "Incorrect input! Try again: ";
		cin >> number;
	}
	cout << "Number in the hexademical(13) number system: " << conversionToHexademical(conversionToDecimal(number)) << endl;
	return 0;
}