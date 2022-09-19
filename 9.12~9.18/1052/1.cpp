#include <iostream>
#include <cmath>
#include <stack>

using namespace std;

int main() {
	int N, K;
	stack <int> S;

	cin >> N >> K;

	if (N < K) {
		cout << 0;
		return 0;
	}
	else if (N == K) {
		cout << 0;
		return 0;
	}
	int a; // ÃÖ´ë 2ÀÇ aÁ¦°ö
	int i = 1;
	while (1) {
		if (pow(2, i) > N) {
			a = i - 1;
			break;
		}
		i++;
	}

	while (N) {

		int p = pow(2, a);
		if (p <= N) {
			S.push(p);
			N -= p;
		}
		a--;

	}

	if (S.size() <= K) {
		cout << 0;
		return 0;
	}
	int cnt = S.size() - K;

	int q = 0;

	for (int i = 0; i < cnt; i++) {
		q += S.top();
		S.pop();

	}

	cout << S.top() - q;
}