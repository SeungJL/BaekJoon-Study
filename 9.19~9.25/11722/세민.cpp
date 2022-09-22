#include <iostream>
#include <algorithm>

using namespace std;

int a[1000];
int DP[1000];
int pre[1000];
int N, last;

int LIS(int n)
{
	last = 0;
	int len = 1;
	for (int i = 0; i < n; i++) {
		DP[i] = 1;
		pre[i] = -1;

		for (int j = 0; j < i; j++) {
			if (a[j] <= a[i])
				continue;

			if (DP[i] < DP[j] + 1) {
				DP[i] = DP[j] + 1;
				pre[i] = j;
				if (len < DP[i])
					last = i, len = DP[i];
			}
		}
	}
	return len;
}

int main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	cout << LIS(N) << '\n';

	return 0;
}