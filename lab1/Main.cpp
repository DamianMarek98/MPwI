#include <iostream>

using namespace std;

#include <stdio.h>
#include <cstdlib>
#include <windows.h>
#include <stdio.h>
#include <vector>
using namespace std;
const int len = 6;
const int tab[len] = { 1,2,3,4,5,6 };
void petla(int *test, int len, int c, int iteration) {


}
void kombinacje(int *test,int len, int c, int iteration,int z) {
	if (iteration < c) {
		for (int i = z; i < len - c + iteration + 1; i++) {
			test[iteration] = tab[i];
			kombinacje(test, len, c, iteration + 1, i + 1);
		}
	}else{
		for (int a = 0; a < c; a++) {
			cout << test[a] << " ";
		}
		cout << endl;
	}
	return;
}

int main() {
	int c;
	scanf_s("%d", &c);
	int *test = new int[c];
	for (int i = 0; i < len - c + 1; i++) {
		test[0] = tab[i];
		kombinacje(test, len, c, 1, i + 1);
		
	}
	
	return 0;
}