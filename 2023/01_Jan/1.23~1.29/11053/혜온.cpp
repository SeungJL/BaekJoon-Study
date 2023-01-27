#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	int num[1000];
	int dp[1000];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	int ma = 0;
	for (int i = 0; i < n; i++)           //1   2  2  3  1   4   4  5  //5  40 1 5 10 90
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)  //10 20 11 12  10 30 20 50
		{
			if (num[i] > num[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}

		ma = max(dp[i], ma);
	}

	cout << ma << endl;


}