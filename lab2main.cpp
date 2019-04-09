#include <iostream>
#include <cmath>

#define N 100000
#define C 1
#define A 69069

using namespace std;

const long long M = pow(2, 31);

long long random(long long x) {
	x = (A*x + C) % M;
	return x;
}

bool xorB(bool a, bool b) {
	if (a == b) {
		return 0;
	}
	else {
		return 1;
	}	
}
long long tabToLong(bool tab[31]) {
	long long value=0;
	for (int i = 0; i < 32; i++) {
		if (tab[i] == 1) {
			value += pow(2, 30 - i);
		}
	}
	return value;
}


int main() {
	//zad 2.2
	cout << "zad 2.2" << endl;
	long long value = 15;
	int probability[10] = {0,0,0,0,0,0,0,0,0,0};
	for (int i = 0; i < N; i++) {
		value = random(value);
		int index = 10 * value / M;
		probability[index]++;
	}
	int sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += probability[i];
		cout << "probability: " << i << " equals: " << probability[i] << endl;
	}
	cout << "Sum= " << sum << endl;

	//zad 2.6
	cout << "zad 2.6" << endl;
	int p = 3, q = 7;
	int probablity2[10] = { 0,0,0,0,0,0,0,0,0,0 };

	bool tab[32] = { 1,0,1,1,0,0,1 };
	for (int i = 7; i < 31; i++) {
		tab[i] = xorB(tab[i - p], tab[i - q]);
	}

	for (int i = 0; i < N; i++) {
		long long var = tabToLong(tab);
		int index = 10 * var / M;
		probablity2[index]++;
		for (int j = 31; j > 0; j--) {
			tab[j] = tab[j - 1];
		}
		tab[0] = xorB(tab[9], tab[21]);
	}
	sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += probablity2[i];
		cout << "probability: " << i << " equals: " << probablity2[i] << endl;
	}
	cout << "Sum= " << sum << endl;

	return 0;
}