#include <iostream>
#include <algorithm>

using namespace std;

constexpr int MAX = 1001;
int dp[MAX] = { 0, };

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	dp[1] = 1; //시작점(가장 왼쪽)까지의 최소 점프 횟수는 1
	for (int i = 1; i <= N; ++i) {
		int num;
		cin >> num;

		if (dp[i] == 0) {
			break;
		}

		for (int j = 1; j <= num; ++j) {
			if (i + j >= MAX) {
				break;
			}
			if (dp[i + j] > dp[i] + 1 || dp[i + j] == 0) {	//최소 점프 횟수 갱신
				dp[i + j] = dp[i] + 1;
			}
		}
	}

	if (dp[N] == 0) {	//가장 오른쪽 끝으로 갈 수 없는 경우
		cout << -1;
	}
	else {
		cout << dp[N] - 1;
	}

	return 0;
}