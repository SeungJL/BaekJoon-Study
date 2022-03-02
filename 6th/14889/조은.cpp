#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N;
int S[21][21]; // 1부터~N까지
bool check[21]; // 스타트팀은 true, 링크팀은 false
int gap = 2100000000;

/* N/2 조합 후 능력치 계산 */
void func(int cnt, int cur) { // 현재 스타트팀으로 cur번 사람까지 cnt명 고른 상태

	if (cnt == N / 2) { // n/2명을 골라서 팀을 다 짰으면
		int start = 0, link = 0;
		for (int i = 1; i <= N; i++) {
			if (check[i]) { // true팀, 즉 스타트팀 능력치 계산
				for (int j = 1; j <= N; j++) {
					if (check[j]) {
						start += S[i][j];
					}
				}
			}
			else { // false팀, 즉 링크팀 능력치 계산
				for (int j = 1; j <= N; j++) {
					if (!check[j]) {
						link += S[i][j];
					}
				}
			}
		}

		gap = min(gap, abs(start - link));
		return;
	}

	for (int i = cur + 1; i <= N; i++) { // 팀 조합
		check[i] = true;
		func(cnt + 1, i); // 다음 사람을 고르러 한 단계 더 들어감 (dfs)
		check[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> S[i][j];
		}
	} // 입력

	func(0, 1);

	cout << gap;

	return 0;
}