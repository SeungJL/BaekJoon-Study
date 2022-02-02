#include <iostream>
#include <algorithm> 
using namespace std;
 
int main()
{
	int n;
	cin >> n;
 
	long long dp[81] = { 0 };
 
	dp[1] = 4;
	dp[2] = 6;
	dp[3] = 10;	
	dp[4] = 16;
 
	for (int i = 5; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i-2];
	}
 
	cout << dp[n] << endl;
 
	return 0;
}
