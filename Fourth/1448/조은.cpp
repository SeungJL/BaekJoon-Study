#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

bool isTriangle(int c, int a, int b) {
	if (c < a + b) { return true; }
	else { return false; }
}

int main() {
	//freopen("input.txt", "rt", stdin);
	int N;
	cin >> N;
	int* input = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}

	sort(input, input + N, greater<int>());

	for (int i = 0; i < N - 2; i++) {
		int c, a, b;
		c = input[i];
		a = input[i + 1];
		b = input[i + 2];
		if (isTriangle(c, a, b)) {
			cout << c + a + b;
			return 0;;
		}
	}
	cout << -1;

	delete[] input;
	return 0;
}
