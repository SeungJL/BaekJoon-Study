/*
221118
백준 1309 : 동물원
https://www.acmicpc.net/problem/1309
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<vector<int>> DP(n + 1); // DP[i][j] : 2*i 일때, 그 위치에 j 방식으로 놓았을 때의 경우의 수
	for (int i = 0; i <= n; i++) {
		DP[i].resize(3);
	}

	DP[1].at(0) = 1; // 두지않음
	DP[1].at(1) = 1; // 왼쪽
	DP[1].at(2) = 1; // 오른쪽

	for (int i = 2; i <= n; i++) {
		//계속해서 9901로 나눠주어야 100000의 경우에 오버플로우가 발생하지 않는다
		DP[i].at(0) = (DP[i - 1].at(0) + DP[i - 1].at(1) + DP[i - 1].at(2))%9901; 
		DP[i].at(1) = (DP[i - 1].at(0) + DP[i - 1].at(2))%9901;
		DP[i].at(2) = (DP[i - 1].at(0) + DP[i - 1].at(1))%9901;
	}

	cout << (DP[n].at(0)+ DP[n].at(1) + DP[n].at(2)) % 9901 << "\n";
	return 0;
}
