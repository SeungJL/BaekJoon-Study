#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	int sum = 0;
	for (int i = 1; i <= K; i++) { sum += i; }

	if (sum > N) {
		cout << -1;
		return 0;
	}

	N -= sum;

	if (N % K == 0) { cout << K - 1; }
	else { cout << K; }
}

