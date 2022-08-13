#include <iostream>
#include <cmath>
using namespace std;

void star(int k, int start, int to) {
	int remain = 6 - start - to;

	if (k == 1) {
		cout << start << " " << to << '\n';
	}
	else {
		star(k - 1, start, remain);
		cout << start << " " << to << '\n';
		star(k - 1, remain, to);
	}
}


int main() {
	int N;
	cin >> N;
	cout << (int)pow(2, N) - 1 << '\n';
	star(N, 1, 3);
}