#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N;
	int x;
	cin >> N;
	vector <int> A;
	vector <int> B;
	for (int i = 0; i < N; i++) {
		cin >> x;
		A.push_back(x);
	}
	for (int i = 0; i < N; i++) {
		cin >> x;
		B.push_back(x);
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<>());
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += A[i] * B[i];
	}
	cout << sum;
}