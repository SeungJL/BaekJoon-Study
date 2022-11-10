#include <iostream>
#include <algorithm>

using namespace std;

int a[1000];
int DP[1000];
int MAX[1000] = { 0, };
int N;

void LIS(int n)
{
	int ans = a[0];
	for (int i = 0; i < n; i++) {
		DP[i] = 1;

		for (int j = 0; j < i; j++) {
			if (a[j] >= a[i])
				continue;

			if (DP[i] < DP[j] + 1) {
				DP[i] = DP[j] + 1;
				MAX[i] = max(a[i] + MAX[j], MAX[i]);

			}
			ans = max(MAX[i], ans);
		}
	}
	cout << ans;
}


int main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		MAX[i] = a[i];
	}
	LIS(N);
	
	return 0;
}