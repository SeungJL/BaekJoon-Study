#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>

using namespace std;


int main() {
	int N;
	cin >> N;
	int DP[50001] = { };
	DP[1] = 1;

	for (int i = 2; i <= N; i++) {
		if ((int)sqrt(i) * (int)sqrt(i) == i) {
			DP[i] = 1;
			continue;
		}
		int Min = 100;
		for (int j = 1; j < sqrt(N); j++) {
			if (i - j * j < 1) {

				break;
			}
			if (DP[i - j * j] < Min) {
				Min = DP[i - j * j];
			}
		}
		DP[i] = Min + 1;
	}
	cout << DP[N];
}

