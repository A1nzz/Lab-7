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

int conversionToDecimal(string s) {
	int res = 0;
	int i = 0;
	while (i < s.length()) {
		res += (s[i] - '0') * pow(2, s.length() - 1 - i);
		i++;
	}
	return res;
}

string conversionDirectReverse(string s) {
	if (s[0] == '0') {
		return s;
	}
	else {
		for (int i = s.length() - 1; i > 0; i--) {
			if (s[i] == '1') {
				s[i] = '0';
			}
			else {
				s[i] = '1';
			}
		}
	}
	return s;
}

string sumNumbersInReverse(string numb1, string numb2) {

	int numb1Decimal = (int)conversionToDecimal(conversionDirectReverse(numb1));
	int numb2Decimal = (int)conversionToDecimal(conversionDirectReverse(numb2));
	
	string res = "00000000";
	for (int i = 7; i > 0; i--) {
		if ((numb1[i] == '1' && numb2[i] == '0') || (numb1[i] == '0' && numb2[i] == '1')) {
			res[i]++;
		}
		if (numb1[i] == '1' && numb2[i] == '1') {
			res[i - 1]++;
		}
		if (res[i] > '1') {
			res[i] = '0';
			res[i - 1]++;
		}
	}
	if ((numb1[0] == '1' && numb2[0] == '0')) {
		if (numb1Decimal > numb2Decimal) {
			res[0] = '1';
		}
		else {
			res[0] = '0';
			for (int i = 7; i > 0; i--) {
				if (res[i] == '0') {
					res[i] = '1';
					break;
				}
				else {
					res[i] = '0';
				}
			}
		}
		
		
	}

	if ((numb1[0] == '0' && numb2[0] == '1')) {
		if (numb2Decimal > numb1Decimal) {
			res[0] = '1';
		}
		else {
			res[0] = '0';

			for (int i = 7; i > 0; i--) {
				if (res[i] == '0') {
					res[i] = '1';
					break;
				}
				else {
					res[i] = '0';
				}
			}
		}

	}
	if (numb1[0] == '1' && numb2[0] == '1') {
		res[0] = '1';
		for (int i = 7; i > 0; i--) {
			if (res[i] == '0') {
				res[i] = '1';
				break;
			}
			else {
				res[i] = '0';
			}
		}
	}
	return res;
}

int main() {
	string number1;
	cout << "Enter a number 1 in binary code(8 bit): ";
	cin >> number1;
	while (!has_only_binary_digits(number1)) {
		cout << "Incorrect input! Try again: ";
		cin >> number1;
	}

	string number2;
	cout << "Enter a number 2 in binary code(8 bit): ";
	cin >> number2;
	while (!has_only_binary_digits(number2)) {
		cout << "Incorrect input! Try again: ";
		cin >> number2;
	}

	convertNegative(number1);
	convertNegative(number2);
	
	cout << conversionDirectReverse(sumNumbersInReverse(conversionDirectReverse(number1), conversionDirectReverse(number2)));
	return 0;
}