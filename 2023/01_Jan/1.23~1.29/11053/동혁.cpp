#include <iostream>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int dp[1001] = {1, };
int a[1001] = {0, };
int main(){
    fastio;
	int N;
	cin >> N;

	int maxNum = 0;
	for(int i = 0; i < N; i++){
		cin >> a[i];
	}	
	for(int i = 0; i < N; i++){
		int temp = 0;
		for(int j = 0; j < i; j++){
			if(a[j] < a[i] && temp < dp[j])
			temp = dp[j];
		}

		dp[i]= temp + 1;
		if(maxNum < dp[i]){
			maxNum = dp[i];
		}
	}
	cout << maxNum;
	return 0;
}