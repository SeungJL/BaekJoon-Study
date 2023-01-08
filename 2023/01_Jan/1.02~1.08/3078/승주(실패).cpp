#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, K;
vector <vector <int>> V;
vector <vector <int>> dp;
vector <bool> visit;
int cnt = 0;
int flag = 0;
void DP(int index, int start, int beforeSum) {
	flag = 0;
	if (index == N - 1)return;
	if (start >= N) {
		flag = 1;
	}
	int leng = V[index][0];
	int cnt = 0;
	int next = -1;
	for (int i = index + 1; i <= index + K; i++) {

		if (i < start) {
			if (next == -1) next = i;

		}
		else {
			if (leng == V[i][0]) {
				if (flag == 0) cnt++;
				if (next == -1) next = i;
			}
		}
		if (i == index + K || i == N - 1) {
			if (dp[index].size() == 0) {
				dp[index].push_back(cnt + beforeSum);
			}
			return DP(next, index + K + 1, cnt + beforeSum - 1);
		}
	}
}

int main() {

	cin >> N >> K;
	V.resize(N);
	visit.resize(N);
	dp.resize(N);
	string name;
	for (int i = 0; i < N; i++) {
		cin >> name;
		V[i].push_back(name.length());
	}
	for (int i = 0; i < N; i++) {
		if (dp[i].size() == 0) {
			DP(i, 1, 0);
		}
	}
	int sum = 0;
	for (int i = 0; i < dp.size(); i++) {
		if (dp[i].size() == 0) continue;
		sum += dp[i][0];
	}
	cout << sum;
}