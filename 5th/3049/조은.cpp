#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	cout << N * (N-1) * (N-2) * (N-3) / 24; // nC4

	return 0;
}