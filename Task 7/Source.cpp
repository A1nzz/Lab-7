#include<iostream>

using namespace std;

int getNumber() {
	int number;

	while (true) {
		cout << "Enter your number: ";
		cin >> number;
		if (cin.fail() || number <= 0) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "\nIncorrect input. Try again.\n";
			continue;
		}
		else {
			break;
		}
	}
	return number;
}

int sum(int firstNumb, int secondNumb) {
	int res = firstNumb ^ secondNumb;
	int numbRank = (firstNumb & secondNumb) << 1;
	while (numbRank) {
		int temp = res;
		res ^= numbRank;
		numbRank = (temp & numbRank) << 1;
	}

	return res;
}

int subtraction(int firstNumb, int secondNumb) {
	return sum(firstNumb, sum(~secondNumb, 1));
}

int multiplication(int firstNumb, int secondNumb) {
	int res = 0;

	while (secondNumb) {
		if (secondNumb & 1) {
			res = sum(res, firstNumb);
		}
		firstNumb <<= 1;
		secondNumb >>= 1;
	}
	return res;
}

int dividing(int firstNumb, int secondNumb) {
	int res = 0;
	while (firstNumb >= secondNumb) {
		res = sum(res, 1);
		firstNumb = subtraction(firstNumb, secondNumb);
	}
	return res;
}

int getRemainder(int firstNumb, int secondNumb) {
	return subtraction(firstNumb, multiplication(dividing(firstNumb, secondNumb), secondNumb));
}

int main() {
	int number = getNumber();
	int myPrimes[] = {3, 79, 151};

	for (int i = 0; i < 3; i++) {
		if (getRemainder(number, myPrimes[i]) == 0) {
			cout << "This number divides to " << myPrimes[i] << " without remainder" << endl;
		} else {
			cout << "This number does not divide to " << myPrimes[i] << " without reamainder" << endl;
		}
	}

	return 0;
}
