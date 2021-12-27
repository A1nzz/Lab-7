#include <iostream>

using namespace std;

bool has_only_digits(string s) {
	return s.find_first_not_of("0123456789ABCDEF-") == string::npos;
}

int getSize(string s) {
	int length = 0;
	while ((int)s[length] > 0 && (int)s[length] < 256) {
		length++;
	}
	return length;
}

string sum(string numb1, string numb2) {
	reverse(numb1.begin(), numb1.end());
	reverse(numb2.begin(), numb2.end());
	if (getSize(numb1) > getSize(numb2)) {
		for (int i = getSize(numb2); i < getSize(numb1); i++) {
			numb2 += '0';
		}
	} 
	if (getSize(numb2) > getSize(numb1)) {
		for (int i = getSize(numb1); i < getSize(numb2); i++) {
			numb1 += '0';
		}
	}
	
	string sum;
	for (int i = 0; i < getSize(numb1); i++) {
		sum += '0';
	}

	for (int i = 0; i < getSize(numb1); i++) {
		int n1;
		if (numb1[i] == 'A') n1 = 10;
		else if (numb1[i] == 'B') n1 = 11;
		else if (numb1[i] == 'C') n1 = 12;
		else if (numb1[i] == 'D') n1 = 13;
		else if (numb1[i] == 'E') n1 = 14;
		else if (numb1[i] == 'F') n1 = 15;
		else n1 = (int)(numb1[i] - 48);
		int n2;
		if (numb2[i] == 'A') n2 = 10;
		else if (numb2[i] == 'B') n2 = 11;
		else if (numb2[i] == 'C') n2 = 12;
		else if (numb2[i] == 'D') n2 = 13;
		else if (numb2[i] == 'E') n2 = 14;
		else if (numb2[i] == 'F') n2 = 15;
		else n2 = (int)(numb2[i] - 48);
		int nSum = n1 + n2;
		
		if (nSum > 15) {
			nSum -= 16;
			if (i + 1 == getSize(sum)) {
				sum += '0';
				sum[i + 1] = '1';
			}
			else {
				sum[i+1]++;
			}
			
		}
		if (nSum == 10) sum[i] += 17;
		else if (nSum == 11) sum[i] += 18;
		else if (nSum == 12) sum[i] += 19;
		else if (nSum == 13) sum[i] += 20;
		else if (nSum == 14) sum[i] += 21;
		else if (nSum == 15) sum[i] += 22;
		else if (nSum < 10) sum[i] += nSum;
	}
	reverse(sum.begin(), sum.end());
	return sum;
}

string subtruction(string numb1, string numb2) {
	reverse(numb1.begin(), numb1.end());
	reverse(numb2.begin(), numb2.end());
	if (getSize(numb1) > getSize(numb2)) {
		for (int i = getSize(numb2); i < getSize(numb1); i++) {
			numb2 += '0';
		}
	}
	if (getSize(numb2) > getSize(numb1)) {
		for (int i = getSize(numb1); i < getSize(numb2); i++) {
			numb1 += '0';
		}
	}

	string subtruction;
	for (int i = 0; i < getSize(numb1); i++) {
		subtruction += '0';
	}

	for (int i = 0; i < getSize(numb1); i++) {
		int n1;
		if (numb1[i] == 'A') n1 = 10;
		else if (numb1[i] == 'B') n1 = 11;
		else if (numb1[i] == 'C') n1 = 12;
		else if (numb1[i] == 'D') n1 = 13;
		else if (numb1[i] == 'E') n1 = 14;
		else if (numb1[i] == 'F') n1 = 15;
		else n1 = (int)(numb1[i] - 48);
		int n2;
		if (numb2[i] == 'A') n2 = 10;
		else if (numb2[i] == 'B') n2 = 11;
		else if (numb2[i] == 'C') n2 = 12;
		else if (numb2[i] == 'D') n2 = 13;
		else if (numb2[i] == 'E') n2 = 14;
		else if (numb2[i] == 'F') n2 = 15;
		else n2 = (int)(numb2[i] - 48);
		int nSubtruction = n1 - n2;

		if (nSubtruction < 0) {
			if (i + 1 == getSize(numb1)) {
				subtruction += '0';
				subtruction[i + 1] = '-';
				nSubtruction = -nSubtruction;
			}
			else {
				nSubtruction += 16;
				subtruction[i + 1]--;
			}

		}
		if (nSubtruction == 10) subtruction[i] += 17;
		else if (nSubtruction == 11) subtruction[i] += 18;
		else if (nSubtruction == 12) subtruction[i] += 19;
		else if (nSubtruction == 13) subtruction[i] += 20;
		else if (nSubtruction == 14) subtruction[i] += 21;
		else if (nSubtruction == 15) subtruction[i] += 22;
		else if (nSubtruction < 10) subtruction[i] += nSubtruction;
	}
	reverse(subtruction.begin(), subtruction.end());
	return subtruction;
}

int main() {
	string number1;
	cout << "Enter a number 1 in the hexademical(16) number system: ";
	cin >> number1;

	while (!has_only_digits(number1)) {
		cout << "Incorrect input! Try again: ";
		cin >> number1;
	}

	string number2;
	cout << "Enter a number 2 in the hexademical(16) number system: ";
	cin >> number2;

	while (!has_only_digits(number2)) {
		cout << "Incorrect input! Try again: ";
		cin >> number2;
	}

	//getting the result given the sign
	string resSum;
	string resSubtruction;
	if (number1[0] == '-' && number2[0] == '-') {
		number1[0] = '0';
		number2[0] = '0';
		resSum = sum(number1, number2);
		reverse(resSum.begin(), resSum.end());
		resSum += '-';
		reverse(resSum.begin(), resSum.end());

		resSubtruction = subtruction(number2, number1);
	} 
	else if (number1[0] == '-') {
		number1[0] = '0';

		resSum = subtruction(number2, number1);
		resSubtruction = sum(number1, number2);
		reverse(resSubtruction.begin(), resSubtruction.end());
		resSubtruction += '-';
		reverse(resSubtruction.begin(), resSubtruction.end());
	}
	else if (number2[0] == '-') {
		number2[0] = '0';
		resSum = subtruction(number1, number2);
		resSubtruction = sum(number1, number2);
	}
	else {
		resSum = sum(number1, number2);
		resSubtruction = subtruction(number1, number2);
	}

	cout << "Sum: " << resSum << endl;
	cout << "Subtruction: " << resSubtruction;
	return 0;
}