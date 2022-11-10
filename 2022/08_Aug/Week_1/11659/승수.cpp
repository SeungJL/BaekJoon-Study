#include <bits/stdc++.h>
using namespace std;

long long dp[100000];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	int start, end;
	long long num;
	cin >> n >> m;

	dp[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> num;
		dp[i] = dp[i-1] + num;
	}

	for (int i = 0; i < m; i++)
	{
		cin >> start >> end;
		cout << dp[end] - dp[start - 1] << '\n';
	}
	
	return 0;
}
