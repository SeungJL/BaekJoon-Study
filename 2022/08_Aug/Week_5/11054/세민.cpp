#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

constexpr int MAX = 1001;
int N, ans = 0;
int A[MAX];
int dp1[MAX];	//0번 idx부터 시작하는 LIS
int dp2[MAX];	//N-1번 idx부터 시작하는 LIS

void solve(int n)
{
	for (int i = 0; i < n; ++i) {
		dp1[i] = 1;

		for (int j = 0; j < i; ++j) {
			if (A[i] > A[j] && dp1[i] < dp1[j] + 1) {
				dp1[i] = dp1[j] + 1;
			}
		}
	}

	for (int i = n - 1; i >=0; --i) {
		dp2[i] = 1;

		for (int j = N - 1; j >= i; --j) {
			if (A[i] > A[j] && dp2[i] < dp2[j] + 1) {
				dp2[i] = dp2[j] + 1;
			}
		}
	}

	for (int i = 0; i < N; ++i) {	//중복되는 원소 (1 2 3 4 5 / 5 2 1 ->5)를 제외
		if (ans < dp1[i] + dp2[i] - 1) ans = dp1[i] + dp2[i] - 1;
	}

	cout << ans;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}

	solve(N);

	return 0;
}