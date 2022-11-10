#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T[16];
int P[16];
int DP[16];

int main(void)
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
		DP[i] = P[i];
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			if (i - j >= T[j]) {
				DP[i] = max(P[i] + DP[j], DP[i]);
			}
		}
	}

	int MAX = 0;

	for (int i = 1; i <= N; i++) {
		if (i + T[i] <= N + 1) {
			if (MAX < DP[i])
				MAX = DP[i];
		}
	}

	cout << MAX;

	return 0;
}