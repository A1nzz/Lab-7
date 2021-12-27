#include <iostream>
#include <string>

using namespace std;

bool has_only_digits(string s) {
	return s.find_first_not_of("0123456789") == string::npos;
}

string M(int in) {
    string a = "";
    int i = 0;
    while (i < in) {
        a = a + "M";
        i++;
    }
    return a;
}

string C(int in) {
    if (in == 4) return "CD";
    else if ((in != 0) && (in < 4)) {
        string a = "";
        int i = 0;
        while (i < in) {
            a = a + "C";
            i++;
        }
        return a;
    }
    else return "";
}

string X(int in) {
    if (in == 4) return "XL";
    else if ((in != 0) && (in < 4)) {
        string a = "";
        int i = 0;
        while (i < in) {
            a = a + "X";
            i++;
        }
        return a;
    }
    else return "";
}

string D(int in) {
    if (in == 4) {
        return "CM";
    }
    else if ((in != 0) && (in < 4)) {
        return "D";
    }
    else return "";
}

string L(int in) {
    if (in == 4) {
        return "XC";
    }
    else if ((in != 0) && (in < 4)) {
        return "L";
    }
    else return "";

}

string basic(int in) {
    string a[] = {
        "",
        "I",
        "II",
        "III",
        "IV",
        "V",
        "VI",
        "VII",
        "VIII",
        "IX"
    };
    return a[in];
}

string convertToRim(int number) {
	string res = "";
    int m1 = number / 1000;
    res = res + M(m1);
    int m2 = number % 1000;

    int d1 = m2 / 500;
    res = res + D(d1);
    int d2 = m2 % 500;

    int c1 = d2 / 100;
    res = res + C(c1);
    int c2 = d2 % 100;

    int l1 = c2 / 50;
    res = res + L(l1);
    int l2 = c2 % 50;

    int x1 = l2 / 10;
    res = res + X(x1);
    int x2 = l2 % 10;

    res = res + basic(x2);
    return res;
}

int main() {

	string number;

	cout << "Enter arabian number: ";
	cin >> number;
	while (!has_only_digits(number)) {
		cout << "Incorrect input! Try again: ";
		cin >> number;
	}
	cout << convertToRim(stoi(number));

	return 0;
}