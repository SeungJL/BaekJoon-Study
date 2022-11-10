#include <iostream>
using namespace std;

int self(int k) {
	int a, start, answer;
	int sum = 0;
	start = k;
	while (k != 0) {
		a = k % 10;
		k = k / 10;
		sum += a;
	}

	answer = start + sum;
	return answer;
}

int main() {
	int result[10000];

	for (int i = 1; i <= 10000; i++) {
		int m = self(i);
		if (m < 10000)
			result[m] = 1;
	}

	for (int i = 1; i < 10000; i++) {
		if (result[i] != 1)
			cout << i << endl;
	}


}