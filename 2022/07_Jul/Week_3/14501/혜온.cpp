#include<iostream>
#include<algorithm>
using namespace std;


int N;
int num[2][17];
int dp[17];
int main()
{
	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> num[0][i] >> num[1][i];

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (num[0][j + 1] + j + 1 <= i + 1)
				dp[i] = max(dp[j] + num[1][j + 1], dp[i]);
			
		}
	}
	cout << dp[N] << endl;
}