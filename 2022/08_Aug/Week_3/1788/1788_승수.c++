#include <bits/stdc++.h>
using namespace std;

long long dp[2000002];

int main()
{
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;
	cin >> n;

	const int max = 1000000;
	const long long div = 1000000000;
	dp[0+max] = 0;
	dp[1+max] = 1;

	if(n < 0)
	{
		for (int i = max - 1; i >= n + max; i--)
		{
			dp[i] = (dp[i + 2] - dp[i + 1]) % div;
		}
	}
	else if(n > 1)
	{
		for(int i = 2+max; i <=n+max; i++)
		{
			dp[i] = (dp[i - 1] + dp[i - 2]) % div;
		}
	}

	long long result = dp[n + max];

	if(result > 0)
	{
		cout << 1 << '\n';
	}
	else if (result == 0)
	{
		cout << 0 << '\n';
	}
	else
	{
		cout << -1 << '\n';
		result *= -1;
	}

	cout << result;

	return 0;
}
