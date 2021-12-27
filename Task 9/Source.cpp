#include <iostream>
#include <string>

using namespace std;

bool has_only_digits(string s) {
	return s.find_first_not_of("0123456789") == string::npos;
}

int getSize(string s) {
	int k = 0;
	while (s[k]) k++;
	return k;
}

void myErase(string &str, const int position) {
	int tmp = 0;
	for (int i = position; i < getSize(str); i++) {
		tmp = str[i];
		str[i] = str[i + 1];
		str[i + 1] = tmp;
	}
}

string conversionToHexademical(int decimal) {
	string res;
	while (decimal) {
		res += (char)('0' + decimal % 3);
		decimal /= 3;
	}
	reverse(res.begin(), res.end());
	return res;
}
string converionToModificateHexademical(string hexademical) {
	for (int i = 1; i < getSize(hexademical); i++) {
		if (hexademical[i] == '0') {
			hexademical[i - 1] = char((int)hexademical[i - 1] - 1);
			hexademical[i] = '3';
		}
	}
	for (int i = 0; i < getSize(hexademical); i++) {
		if (hexademical[i] == '0') myErase(hexademical, i);
	}
	return hexademical;
}

int main() {
	string number;
	cout << "Enter a number: ";
	cin >> number;

	while (!has_only_digits(number)) {
		cout << "Incorrect input! Try again: ";
		cin >> number;
	}
	cout << "Number in the hexademical(3) number system: " << converionToModificateHexademical(conversionToHexademical(stoi(number))) << endl;

	return 0;
}