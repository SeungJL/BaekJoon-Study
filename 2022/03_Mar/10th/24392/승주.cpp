#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <stdio.h>
#include <map>
#include <cstring>
#include <cmath>
#include <deque>
using namespace std;
int DP[1002][1002] = {};
int main() {
	int N, M;
	cin >> N >> M;
	int x;


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> x;
			if (i == 1) {
				if (x == 1) { DP[i][j] = 1; }
			}
			else {
				if (x == 1) {
					long long y = (long long)DP[i - 1][j - 1] + (long long)DP[i - 1][j] + (long long)DP[i - 1][j + 1];
					y %= 1000000007;
					DP[i][j] = (int)y;
				}
			}
		}
	}
	long long ans = 0;
	for (int i = 1; i <= M; i++) {
		ans += (long long)DP[N][i];
	}
	cout << ans % 1000000007;
}