#include <iostream>
#include <string>

using namespace std;

bool has_only_digits(string s) {
	return s.find_first_not_of("0123456789") == string::npos;
}

int main() {
	int t;
	cout << "Enter number of tests: ";
	cin >> t;

	for (int i = 0; i < t; i++) {
		string n;
		cout << "Enter n: ";
		cin >> n;
		
		while (!has_only_digits(n) || stoi(n) < 1 || stoi(n) > pow(10, 9)) {
			cout << "Incorrect input! Pls enter n from 1 to 10^9" << endl << "Enter n: " ;
			cin >> n;
		}
		int number = stoi(n);
		unsigned long long numberOfInteresting = 0;
		if(number % 10 == 9) cout << "Count of interesting numbers is: " << number / 10 + 1 << endl;
		else cout << "Count of interesting numbers is: " << number / 10 << endl;
	}
	return 0;
}