#include<iostream>
#include<string.h>
#include<queue>
#include<vector>
using namespace std;

int dp[16] = { 0 };
int pay[16] = { 0 };
int day[16] = { 0 };

int main() {
	
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> day[i] >> pay[i];
		
		for (int j = 0; j < i; j++) {
			if (day[j] + j <= i && i + day[i] <= n+1) {
				dp[i] = max(dp[i], dp[j]+pay[i]);
			}
		}
	}
	
	int answer = 0;
	for (int i = 0; i <= n; i++) {
	  
		answer = max(answer, dp[i]);
	}

	cout << answer;
    
    return 0;
}