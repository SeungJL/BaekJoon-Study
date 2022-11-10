#include <iostream>

using namespace std;

int N, M;
int bridge[1001][1001];
int dp[1001][1001];

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> bridge[i][j];
		}
	}

	for (int j = 0; j < M; j++) 
		if (bridge[0][j] == 1) dp[0][j] = 1;

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (bridge[i][j] == 1) {		
				int result = 0;
				if (j > 0 && bridge[i-1][j-1] == 1) {		
					result += (dp[i-1][j-1] % 1000000007);
					result %= 1000000007;
				}		
				if (bridge[i-1][j] == 1) {	
					result += (dp[i-1][j] % 1000000007);
					result %= 1000000007;
				}		
				if (j < M-1 && bridge[i-1][j+1] == 1) {	
					result += (dp[i-1][j+1] % 1000000007);
					result %= 1000000007;
				} 	
				dp[i][j] = result;
			}
		}
	}
	int sum=0;
	for (int j = 0; j < M; j++) {
		sum += (dp[N-1][j] % 1000000007);
		sum %= 1000000007;
	}
	cout << sum << endl;

	return 0;
}