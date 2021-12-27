#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool has_only_digits(string s) {
	return s.find_first_not_of("0123456789") == string::npos;
}


string conversionToHexademical(int decimal) {
	string res;
	while (decimal) {
		res += (char)('0' + decimal % 2);
		decimal /= 2;
	}
	reverse(res.begin(), res.end());
	return res;
}

bool isTwoDemicalNumber(string twoHexademicalNumber, string number) {
	int sizeNumb = number.length();
	int sizeHex = twoHexademicalNumber.length();
	while (sizeNumb) {
		if (number[sizeNumb - 1] != twoHexademicalNumber[sizeHex - 1]) {
			return false;
		}
		--sizeNumb;
		--sizeHex;
	}
	return true;
}


int main() {
	string number;
	cout << "Enter n: ";
	cin >> number;

	while (!has_only_digits(number) || stoi(number) < 1 || stoi(number) > 10000) {
		cout << "Incorrect input! Try again: ";
		cin >> number;
	}
	vector<int> twoDemicalNumbers;
	int k = 0;
	for (int i = 1; i < 10000; i++) {
		if (isTwoDemicalNumber(conversionToHexademical(i), to_string(i))) {
			k++;
			twoDemicalNumbers.resize(k);
			twoDemicalNumbers[k - 1] = i;
		}
	}
	cout << endl << twoDemicalNumbers[stoi(number) - 1];
	return 0;
}